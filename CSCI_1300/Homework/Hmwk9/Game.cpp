#include "Game.h"
#include <sstream>

Game::Game() {
	// readMilestonesFile("txt-files/milestones.txt");

}

int Game::readMilestonesFile(std::string filePath)
{
	std::ifstream infile(filePath);
	if (infile.fail()) {
		return -1;
	}
	std::string line;
	while (std::getline(infile, line)) {
		if (line != "") {
			std::istringstream ss(line);
			int distance;
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

int Game::enterPlayer(std::string playerName)
{
	return 0;
}

int Game::totalDistance()
{
	return 0;
}

int Game::distanceToHome()
{
	return 0;
}

int Game::distanceToNextMilestone()
{
	return 0;
}

int Game::daysLeft()
{
	return 0;
}

int Game::daysTranscurred()
{
	return 0;
}

int Game::partyAlive()
{
	return 0;
}

bool Game::partyBroke()
{
	return false;
}

bool Game::partyStarved()
{
	return false;
}

void Game::rest()
{
}

void Game::travel()
{
}

void Game::takePhotos()
{
}

void Game::quit()
{
}

void Game::setDate(int dayInput)
{
}
