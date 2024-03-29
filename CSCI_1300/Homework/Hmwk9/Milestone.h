#include "Common.h"

#ifndef MILESTONE_H
#define MILESTONE_H

// where methods and member variables are defined
class Milestone {
public:
    // Constructor
    Milestone(std::string milestoneName,
              unsigned int distance,
              bool isItAFort,
              float costPerDay,
              bool inTransit=false) : name(milestoneName),
                                  distanceFromOrigin(distance),
                                  is_fort(isItAFort),
                                  dailyTollPerPerson(costPerDay),
                                  inTransit_(inTransit) {
    }

    // Methods
    std::string getName();

    unsigned int getDistanceFromOrigin(); // in KM

    bool isServo(); // all forts are where the player can buy supplies from a Servo

    bool canLeaveTheSameDay();

    float getDailyCostPerPlayer(); // can be zero if it's a fort or a special attraction

    bool inTransit() const;

// private to the class
private:
    const std::string name;
    const unsigned int distanceFromOrigin; // in km
    const bool is_fort; // if not, it's an attraction.
    const float dailyTollPerPerson; // cost in AUD per person in party
    const bool inTransit_;
};

#endif

// At attractions, the money paid is just a toll/fee
//



