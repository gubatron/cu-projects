#include "Common.h"
#include "Player.h"
#include "Milestone.h"
#include "Servo.h"
#include "Calendar.h"
#include "Photo.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game() : deadline(Calendar(2019, 12, 2)),
             defaultStartDate(Calendar(2019, 9, 5)),
             startDate(Calendar(2019, 9, 5)),
             currentDate(Calendar(2019, 9, 5)),
             lastVisitedMilestoneOffset(0),
             playerQuit(false) {
        readMilestonesFile("milestones.txt");
    }

    int readMilestonesFile(std::string filePath);

    size_t enterPlayer(const std::string &playerName);

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

    void addDays(int days);

	void addToStartDate(int nDays);

	bool timeIsUp();
    /** checks if current date isn't already past the deadline date. *
	* time runs out after 124 days
	*/


    int partyAlive();

    bool partyBroke();

    bool partyStarved();

    void rest();

    void travel();

    bool takePhotos(Photo photoSubjectChoice);

    void quit();
    Van &getVan();

    Servo &getServo() {
        return store;
    }

    unsigned int getLastVisitedMilestoneOffset() const;

    Milestone &getLastVisitedMilestone();

    unsigned int state();

private:
    bool playerQuit;
    unsigned int lastVisitedMilestoneOffset;
    std::vector<Player> party;
    std::vector<Milestone> milestones;
    Servo store;
    Calendar deadline;
    Calendar defaultStartDate; // suggested start
    Calendar startDate;
    Calendar currentDate;
    Van van;
};

#endif

