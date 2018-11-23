#include "Common.h"
#include "Player.h"
#include "Milestone.h"
#include "Servo.h"
#include "Calendar.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game();

	int readMilestonesFile(std::string filePath);
	
	int enterPlayer(std::string playerName);

	/** Distance from start to home */
	int totalDistance();

	/** Distance from current van location to final destination */
	int distanceToHome(); 

	/** Distance from current van location to next milestone */
	int distanceToNextMilestone();

	int daysLeft();

	int daysTranscurred();

	int partyAlive();

	bool partyBroke();

	bool partyStarved();
	
	void rest();

	void travel();

	void takePhotos();

	void quit();

	void setDate(int dayInput); 


private:
    std::vector<Player> party;
	std::vector<Milestone> milestones;
    Servo store;
	Milestone *currentMilestone;
	Milestone *nextMilestone;
	Calendar deadline;
	Calendar defaultStartDate; // suggested start
	Calendar startDate;
	Calendar currentDate;
	Van van;
    

};

#endif