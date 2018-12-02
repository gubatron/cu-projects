#include "Game.h"
#include <fstream>

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
    party.push_back(Player(playerId, playerName));
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

unsigned int Game::distanceToNextMilestone() {
    auto lastMilestoneIndex = static_cast<unsigned int>(milestones.size() - 1);
    unsigned int nextMilestoneIndex = getLastVisitedMilestoneOffset() + 1;
    if (nextMilestoneIndex > lastMilestoneIndex) {
        return 0;
    }
    Milestone nextMilestone = milestones[nextMilestoneIndex];
    unsigned int nextMilestoneTotalDistance = nextMilestone.getDistanceFromOrigin();
    return nextMilestoneTotalDistance - van.distanceTraveled();
}

unsigned int Game::daysLeft() {
    return static_cast<unsigned int>(deadline - currentDate);
}

unsigned int Game::daysTranscurred() {
    return static_cast<unsigned int>(currentDate - startDate);
}
void Game::addDays(int days) {
    currentDate.addDays(days);
}

void Game::addToStartDate(int nDays) {
	startDate.addDays(nDays);
}

// bool Game::timeIsUp() {
// TODO }

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
    unsigned int travelDistance = std::min(randomBetween(400, 800), distanceToNextMilestone());

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
  playerQuit = true;
}


Van &Game::getVan() {
    return van;
}

unsigned int Game::getLastVisitedMilestoneOffset() const {
    return lastVisitedMilestoneOffset;
}

Milestone &Game::getLastVisitedMilestone() {
    Milestone &lastVisitedMilestone = milestones[lastVisitedMilestoneOffset];
    if (traveledDistance() == lastVisitedMilestone.getDistanceFromOrigin()) {
        return lastVisitedMilestone;
    }
    // If not at a milestone, return special "In-Transit" milestone
    Milestone inTransitMilestone = Milestone("In-Transit", traveledDistance(), false, 0.0f);
    return inTransitMilestone;
}

unsigned int Game::state() {
    if (playerQuit) {
        return GAME_OVER_USER_QUIT;
    }
    if (van.getAmountOfSupply(SUPPLY_FUEL) <= 0) {
        return GAME_OVER_RUN_OUT_OF_FUEL;
    }
    if (!partyAlive()) {
        return GAME_OVER_PARTY_DIED;
    }
    if (partyStarved()) {
        return GAME_OVER_PARTY_STARVED;
    }
    if (partyBroke()) {
        return GAME_OVER_PARTY_BROKE;
    }
    if (getLastVisitedMilestoneOffset() == milestones.size() - 1) {
        return GAME_OVER_ARRIVED;
    }
    // TODO: Check that the date is not the last
    // if (timeIsUp()) {
    //   return GAME_OVER_TIME_IS_UP;
    // }
    return GAME_NOT_OVER;
}

Calendar Game::getStartDate() {
    return startDate;
}

Calendar Game::getCurrentDate() {
    return currentDate;
}