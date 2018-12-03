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

int Game::daysLeft() {
    return deadline.subtractDays(currentDate);
}

unsigned int Game::daysTranscurred() {
    return static_cast<unsigned int>(currentDate.subtractDays(startDate));
}
void Game::addDays(int days) {
    currentDate.addDays(days);
}

void Game::addToStartDate(int nDays) {
	startDate.addDays(nDays);
}

bool Game::timeIsUp() {
    return daysLeft() < 0;
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
    return van.balance() <= 0.0f;
}

bool Game::partyStarved() {
    return van.getAmountOfSupply(SUPPLY_FOOD) <= 0;
}

void Game::rest() {
    rest(true);
}

void Game::rest(bool gainHealth) {
    // time goes by
    addDays(1);

    // food is consumed
    int numberOfPlayersAlive = partyAlive();
    int totalPoundsPerDay = numberOfPlayersAlive * 2;
    van.modifySupplyAmount(SUPPLY_FOOD, -totalPoundsPerDay);
    van.spend(getLastVisitedMilestone().getDailyCostPerPlayer() * party.size());

    // gain health
    if (gainHealth) {
        recoverBothPlayers(REST_PLAYER_HEALTH_RECOVERY_POINTS);
    }
}

void Game::recoverBothPlayers(const unsigned int healthChange) {
    if (party[0].getHealth() > 0 && party[0].getHealth() < 100) {
        unsigned int leftToRecover = 100 - party[0].getHealth();
        party[0].affectHealth(static_cast<int>(std::min(healthChange, leftToRecover)));
    }
    if (party[1].getHealth() > 0 && party[1].getHealth() < 100) {
        unsigned int leftToRecover = 100 - party[1].getHealth();
        party[1].affectHealth(static_cast<int>(std::min(healthChange, leftToRecover)));
    }
}

void Game::travel() {
    // time goes by
    addDays(2);
    van.spend(getLastVisitedMilestone().getDailyCostPerPlayer() * party.size() * 2); // x 2 days

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
    Milestone inTransitMilestone = Milestone("In-Transit", traveledDistance(), false, 0.0f, true);
    return inTransitMilestone;
}

unsigned int Game::state() {
    if (playerQuit) {
        return GAME_OVER_USER_QUIT;
    }
    if (van.getAmountOfSupply(SUPPLY_FUEL) <= 0) {
        return GAME_OVER_RUN_OUT_OF_FUEL;
    }

    // if all players dead or player 1 has died
    if (!partyAlive() || party[0].getHealth() <= 0) {
        return GAME_OVER_PARTY_DIED;
    }
    if (partyStarved()) {
        return GAME_OVER_PARTY_STARVED;
    }
    if (partyBroke()) {
        return GAME_OVER_PARTY_BROKE;
    }
    if (timeIsUp()) {
        return GAME_OVER_TIME_IS_UP;
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

int Game::affectPlayerHealth(int playerNumber, int healthChange) {
    return party[playerNumber].affectHealth(healthChange);
}
