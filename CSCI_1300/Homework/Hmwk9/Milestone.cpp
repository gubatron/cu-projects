#include "Milestone.h"

std::string Milestone::getName() {
    return name;
}

unsigned int Milestone::getDistanceFromOrigin() {
    return distanceFromOrigin;
}

bool Milestone::isServo() {
    return is_fort;
}

float Milestone::getDailyTollPerPerson() {
    return dailyTollPerPerson;
}
