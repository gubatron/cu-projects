#include "Milestone.h"

std::string Milestone::getName() {
    return name;
}

int Milestone::getDistanceFromOrigin() {
    return distanceFromOrigin;
}

bool Milestone::isFort() {
    return is_fort;
}

float Milestone::getDailyTollPerPerson() {
    return dailyTollPerPerson;
}