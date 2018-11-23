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
             defaultStartDate(Calendar(2019, 12, 2)),
             startDate(Calendar(2019, 12, 2)),
             currentDate(Calendar(2019, 12, 2)) {
        readMilestonesFile("txt-files/milestones.txt");
        currentMilestone = &milestones[0];
        nextMilestone = &milestones[1];
    }

    int readMilestonesFile(std::string filePath);

    size_t enterPlayer(std::string &playerName);

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

    void addDays(int days);

    Servo &getServo() {
        return store;
    }

    Milestone getCurrentMilestone() {
        return *currentMilestone;
    }

    Van &getVan();

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

