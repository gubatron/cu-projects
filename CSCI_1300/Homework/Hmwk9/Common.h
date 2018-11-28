#ifndef COMMON_H
#define COMMON_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <sstream>
#include <algorithm> // std::min

// MAX NUMBER OF PLAYERS THAT CAN BE ADDED TO THE PARTY
const int MAX_NUMBER_OF_PLAYERS = 2;

// Vital supplies
const int SUPPLY_FOOD = 0;

// Van supplies
const int SUPPLY_FUEL = 1;
const int SUPPLY_ENGINE = 2;
const int SUPPLY_BATTERY = 3;
const int SUPPLY_BUMPER = 4;
const int SUPPLY_TIRE = 5;

// Travel supplies
const int SUPPLY_PHOTOS = 6;
const int SUPPLY_MEDICAL_KIT = 7;

// PHOTO SUBJECT IDS
const int PHOTO_BEACH = 0;
const int PHOTO_ANIMAL = 1;
const int PHOTO_TOWN = 2;
const int PHOTO_CITY = 3;
const int PHOTO_LANDMARK = 4;

// CHANCE OF SHOOTING AN OBJECT
const float PHOTO_BEACH_PROBABILITY = 0.50f;
const float PHOTO_ANIMAL_PROBABILITY = 0.25f;
const float PHOTO_TOWN_PROBABILITY = 0.15f;
const float PHOTO_CITY_PROBABILITY = 0.7f;
const float PHOTO_LANDMARK_PROBABILITY = 0.5f;

// EARNED MONEY PER SUBJECT SUCCESSFULLY SHOT
const float PHOTO_BEACH_EARNINGS = 5.0f;
const float PHOTO_ANIMAL_EARNINGS = 7.0f;
const float PHOTO_TOWN_EARNINGS = 15.0f;
const float PHOTO_CITY_EARNINGS = 25.0f;
const float PHOTO_LANDMARK_EARNINGS = 30.0f;

// HOW MANY PHOTOS ARE NEEDED TO SHOOT SUBJECT
const unsigned int PHOTO_BEACH_PHOTOS_TAKEN = 5;
const unsigned int PHOTO_ANIMAL_PHOTOS_TAKEN = 10;
const unsigned int PHOTO_TOWN_PHOTOS_TAKEN = 8;
const unsigned int PHOTO_CITY_PHOTOS_TAKEN = 10;
const unsigned int PHOTO_LANDMARK_PHOTOS_TAKEN = 12;

// POSSIBLE GAME STATES, IF NOT GAME_NOT_OVER GAME HAS ENDED FOR THAT REASON
const unsigned int GAME_NOT_OVER = 0;
const unsigned int GAME_OVER_RUN_OUT_OF_FUEL = 1;
const unsigned int GAME_OVER_PARTY_DIED = 2;
const unsigned int GAME_OVER_PARTY_STARVED = 3;
const unsigned int GAME_OVER_PARTY_BROKE = 4;
const unsigned int GAME_OVER_ARRIVED = 5;
const unsigned int GAME_OVER_TIME_IS_UP = 6;
const unsigned int GAME_OVER_USER_QUIT = 999;

// UI VALID OPTIONS

const std::string UI_INVALID_OPTION = "invalid";
const std::string UI_OPTION_QUIT_Q = "q";
const std::string UI_OPTION_QUIT_QUIT = "quit";

const std::string UI_MILESTONE_OPTION_TRAVEL = "1";
const std::string UI_MILESTONE_OPTION_REST = "2";
const std::string UI_MILESTONE_OPTION_TAKE_PHOTOS = "3";
const std::string UI_MILESTONE_OPTION_GO_TO_SERVO = "4";
const std::string UI_MILESTONE_OPTION_ENTER_PLAYER = "5";

inline bool randomEvent(int probability) {
	return ((rand() % 100) + 1) <= probability; // covers [1 to 100]
}

inline int randomBetween(int a, int b) {
	return rand()%(b - a + 1) + a;
}

#endif
