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
    Game() :
             playerQuit(false),
             lastVisitedMilestoneOffset(0),
             deadline(Calendar(2019, 12, 2)),
             startDate(Calendar(2019, 9, 5)),
             currentDate(Calendar(2019, 9, 1))
              {
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
    unsigned int distanceToNextMilestone();
    
	int daysLeft();

    unsigned int daysTranscurred();

    void addDays(int days);

	void addToStartDate(int nDays);

    /** Checks if current date isn't already past the deadline date. Time runs out after 124 days */
    bool timeIsUp();

    int partyAlive();

    bool partyBroke();

    bool partyStarved();

    void rest(bool gainHealth);

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

    Calendar getStartDate();

    Calendar getCurrentDate();

    std::vector<Player> getParty() { return party; }

    int affectPlayerHealth(int playerNumber, int healthChange);
private:
    bool playerQuit;
    unsigned int lastVisitedMilestoneOffset;
    std::vector<Player> party;
    std::vector<Milestone> milestones;
    Servo store;
    Calendar deadline;
    Calendar startDate;
    Calendar currentDate;
    Van van;
};

#endif

