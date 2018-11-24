#include "Common.h"
#include "Player.h"
#include "Milestone.h"
#include "Servo.h"
#include "Calendar.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game() : deadline(Calendar(2019, 12, 2)),
             defaultStartDate(Calendar(2019, 9, 5)),
             startDate(Calendar(2019, 9, 5)),
             currentDate(Calendar(2019, 9, 5)),
         	 currentMilestoneOffset(0)
	{
        readMilestonesFile("milestones.txt");
    }

    int readMilestonesFile(std::string filePath);

    size_t enterPlayer(std::string &playerName);
	
	/** Distance traveled by the van*/
	unsigned int traveledDistance();

    /** Distance from start to home */
    unsigned int totalDistance();

    /** Distance from current van location to final destination */
    unsigned int remainingDistance();

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

    void addDays(int days);

    Servo &getServo() {
        return store;
    }

    Milestone &getCurrentMilestone() {
        return milestones[currentMilestoneOffset];
    }

    Van &getVan();

    unsigned int getCurrentMilestoneOffset() const;

private:
    std::vector<Player> party;
    std::vector<Milestone> milestones;
    Servo store;
    unsigned int currentMilestoneOffset;
    Calendar deadline;
    Calendar defaultStartDate; // suggested start
    Calendar startDate;
    Calendar currentDate;
    Van van;


};

#endif

