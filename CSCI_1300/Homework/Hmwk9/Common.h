#ifndef COMMON_H
#define COMMON_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <sstream>
#include  <algorithm> // std::min

const int SUPPLY_TIRE = 0;
const int SUPPLY_FOOD = 1;
const int SUPPLY_FILM = 2;
const int SUPPLY_ENGINE = 3;
const int SUPPLY_BATTERY = 4;
const int SUPPLY_BUMPER = 5;
const int SUPPLY_MEDICAL_KIT = 6;
const int SUPPLY_FUEL = 7;

inline bool randomEvent(int probability) {
	return ((rand() % 100) + 1) <= probability; // covers [1 to 100]
}

inline int randomBetween(int a, int b) {
	return rand()%(b - a + 1) + a;
}

#endif
