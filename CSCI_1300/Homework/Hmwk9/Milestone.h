#include "Common.h"

#ifndef MILESTONE_H
#define MILESTONE_H

// where methods and member variables are defined
class Milestone {
public:
    // Constructor
    Milestone(std::string milestoneName,
              int distance,
              bool isItAFort,
              int minDays,
              float costPerDay) : name(milestoneName),
                                  distanceFromOrigin(distance),
                                  is_fort(isItAFort),
                                  minimumDaysRequired(minDays),
                                  dailyTollPerPerson(costPerDay) {
    }

    // Methods
    std::string getName();

    int getDistanceFromOrigin(); // in KM
    bool isFort(); // all forts are where the player can buy supplies from a Servo
    bool canLeaveTheSameDay();

    int getMinimumDaysRequired(); // can be zero if player can leave right away
    float getDailyTollPerPerson(); // can be zero if it's a fort or a special attraction

// private to the class
private:
    const std::string name;
    const int distanceFromOrigin; // in km
    const bool is_fort; // if not, it's an attraction.
    const int minimumDaysRequired;
    const float dailyTollPerPerson; // cost in AUD per person in party
};

#endif

// At attractions, the money paid is just a toll/fee
//



