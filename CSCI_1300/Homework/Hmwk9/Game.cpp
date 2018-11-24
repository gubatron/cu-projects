#include "Game.h"
#include <fstream>

int Game::readMilestonesFile(std::string filePath) {
    std::ifstream infile(filePath);
    if (infile.fail()) {
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

size_t Game::enterPlayer(std::string &playerName) {
    size_t playerId = party.size();
    party.emplace_back(Player(playerId, playerName));
    return playerId;
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
    int nextMilestoneIndex = getCurrentMilestoneOffset() + 1;
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
}

void Game::takePhotos() {
}

void Game::quit() {
}

void Game::addDays(int days) {
    currentDate.addDays(days);
}

Van &Game::getVan() {
    return van;
}

unsigned int Game::getCurrentMilestoneOffset() const {
    return currentMilestoneOffset;
}
