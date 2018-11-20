#include "Milestone.h"
// implementation file

                    
string Milestone::getName() {
    return name;
}

int Milestone::getDistanceFromOrigin() {
    return distanceFromOrigin;
}

bool Milestone::isFort() {
    return isFort;
}

bool Milestone::canLeaveTheSameDay() {
    return minimumDaysRequired == 0;
}

int Milestone::getMinimumDaysRequired() {
    return minimumDaysRequired;
}

float Milestone::getDailyTollPerPerson() {
    return dailyTollPerPerson;
}