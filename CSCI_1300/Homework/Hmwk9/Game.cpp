#include "Game.h"
#include <fstream>
#include <AppleTextureEncoder.h>

int Game::readMilestonesFile(std::string filePath) {
    std::ifstream infile(filePath);
    if (infile.fail()) {
        std::cout << "FATAL ERROR: Could not load milestones file: " << filePath << std::endl;
        return -1;
    }
    std::string line;
    while (std::getline(infile, line)) {
        if (line != "") {
            std::istringstream ss(line);
            unsigned int distance;
            int cost;
            std::string name;
            ss >> distance >> cost >> name;
            Milestone m(name, distance, cost == 0, cost);
            milestones.push_back(m);
        }
    }
    infile.close();
    return 0;
}

size_t Game::enterPlayer(const std::string &playerName) {
    size_t playerId = party.size();
    party.emplace_back(Player(playerId, playerName));
    return playerId;
}

unsigned int Game::traveledDistance() {
    return van.distanceTraveled();
}

unsigned int Game::totalDistance() {
    unsigned long lastIndex = milestones.size() - 1;
    Milestone lastMilestone = milestones[lastIndex];
    return lastMilestone.getDistanceFromOrigin();
}

unsigned int Game::remainingDistance() {
    return totalDistance() - van.distanceTraveled();
}

int Game::distanceToNextMilestone() {
    int lastMilestoneIndex = milestones.size() - 1;
    int nextMilestoneIndex = getLastVisitedMilestoneOffset() + 1;
    if (nextMilestoneIndex > lastMilestoneIndex) {
        return 0;
    }
    Milestone nextMilestone = milestones[nextMilestoneIndex];
    int nextMilestoneTotalDistance = nextMilestone.getDistanceFromOrigin();
    return nextMilestoneTotalDistance - van.distanceTraveled();
}

int Game::daysLeft() {
    return deadline - currentDate;
}

int Game::daysTranscurred() {
    return currentDate - startDate;
}

int Game::partyAlive() {
    if (party.empty()) {
        return 0;
    }
    int totalAlive = 0;
    for (const auto &player : party) {
        if (player.getHealth() > 0) {
            totalAlive += 1;
        }
    }
    return totalAlive;
}

bool Game::partyBroke() {
    return van.balance() == 0.0f;
}

bool Game::partyStarved() {
    return van.getAmountOfSupply(SUPPLY_FOOD) == 0;
}

void Game::rest() {
    // time goes by
    addDays(1);

    // food is consumed
    int numberOfPlayersAlive = partyAlive();
    int totalPoundsPerDay = numberOfPlayersAlive * 2;
    van.modifySupplyAmount(SUPPLY_FOOD, -totalPoundsPerDay);
}

void Game::travel() {
    // time goes by
    addDays(2);

    // food is consumed
    int numberOfPlayersAlive = partyAlive();
    int totalPoundsPerDay = numberOfPlayersAlive * 2;
    van.modifySupplyAmount(SUPPLY_FOOD, -totalPoundsPerDay);

    // distance is traveled random(400 - 800 km) or what's left to the next milestone
    int travelDistance = std::min(randomBetween(400, 800), distanceToNextMilestone());

    van.move(travelDistance);

    // If we land at the next milestone, we update the milestone index
    if (distanceToNextMilestone() == 0) {
        lastVisitedMilestoneOffset++;
    }

    // fuel is used -- consume 5L/100km (36L tank per 720km)
    int fuelConsumed = (travelDistance / 100) * 5;
    van.modifySupplyAmount(SUPPLY_FUEL, -fuelConsumed);
}

bool Game::takePhotos(Photo photoSubjectChoice) {
    // UI will be something like this:
    //    Attempt to shoot a subject, pick one below:
    //
    //    1. Beach
    //    2. Animal
    //    3. Town
    //    4. City
    //    5. Landmark
    //
    //    > 2
    //    You chose Animal, you have a 25% of taking good photos
    //    Calculating odds...
    //    (Possible outputs)
    //    a) Sorry, no animals were found, you took 8 bad pictures, you earned AUD $0
    //    b) Success, you took 8 pictures of Animal -> you earned AUD $80

    // time goes by
    addDays(1);

    int diceRoll = randomBetween(1, 100);
    bool success = diceRoll <= (photoSubjectChoice.probability * 100);

    // photos are spent no matter the outcome
    van.modifySupplyAmount(SUPPLY_PHOTOS, -photoSubjectChoice.photosTaken);

    // money goes up on success
    if (success) {
        van.earn(photoSubjectChoice.earnings * photoSubjectChoice.photosTaken);
    }
    return success;
}

void Game::quit() {
    Game end;
    end.quit();
    std::cout << "Crikey! Your trip ended on short notice! Ooroo!" << std::endl;
}

void Game::addDays(int days) {
    currentDate.addDays(days);
}

Van &Game::getVan() {
    return van;
}

unsigned int Game::getLastVisitedMilestoneOffset() const {
    return lastVisitedMilestoneOffset;
}
