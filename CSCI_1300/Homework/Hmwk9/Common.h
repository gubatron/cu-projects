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
const unsigned int GAME_OVER_USER_QUIT = 7;

// PLAYER MISFORTUNE GAME OVER REASON CODES
const unsigned int GAME_OVER_PLAYER_KIDNAPPED = 8;

// VAN MISFORTUNE GAME OVER REASON CODES
const unsigned int GAME_OVER_NO_SPARE_TIRES = 9;
const unsigned int GAME_OVER_NO_BUMPER_CRASH = 10;
const unsigned int GAME_OVER_BATTERY_BROKE = 11;
const unsigned int GAME_OVER_ENGINE_BROKE = 12;

const std::string GAME_OVER_REASONS[] = {
    "Game not over",
    "Ran out of fuel",
    "Player in party died",
    "Party starved",
    "Party broke",
    "Arrived to destination, good on 'ya mate!",
    "Time is up",
    "User quit game",
    "Greg McLean kidnapped 'ya and nobody paid your ransom, R.I.P.",
    "Popped a tire and you don't have a spare",
    "Hit a 'roo and didn't have a bumper, Van is totalled",
    "Get a spare car battery next time, you got stranded for days and missed your flight home",
    "Engine broke and you ain't got a spare, remember these are long trips. Plan ahead next time",
};

const std::string HEALTH_MISFORTUNE_NAMES[] =
{
 "dehydrated",
 "attacked by a drop bear",
 "bit by a snake",
 "motion sickness"
};

const std::string FORTUNE_NAMES[] = {
 "got free Vegemite",
 "got towed 200km",
 "got free 40 liters of gas"
};

// HEALTH MISFORTUNE MENU OPTIONS
const unsigned int UI_HEALTH_MENU_REST = 0;
const unsigned int UI_HEALTH_MENU_PRESS_ON = 1;
const unsigned int UI_HEALTH_MENU_MEDKIT = 2;

// UI VALID OPTIONS

const std::string UI_INVALID_OPTION = "invalid";
const std::string UI_OPTION_QUIT_0 = "0";
const std::string UI_OPTION_QUIT_Q = "q";
const std::string UI_OPTION_QUIT_QUIT = "quit";

const int UI_INVALID_INPUT = -1;
const unsigned int UI_NO_LIMIT = 999999999;
const unsigned int UI_QUIT_CODE = 999999999;

const unsigned int UI_MILESTONE_OPTION_QUIT = 0;
const unsigned int UI_MILESTONE_OPTION_TRAVEL = 1;
const unsigned int UI_MILESTONE_OPTION_REST = 2;
const unsigned int UI_MILESTONE_OPTION_TAKE_PHOTOS = 3;
const unsigned int UI_MILESTONE_OPTION_CHECK_VAN = 4;
const unsigned int UI_MILESTONE_OPTION_GO_TO_SERVO = 5;

// UI SERVO MENU CHOICES
const unsigned int UI_SERVO_MENU_EXIT = 0;
const unsigned int UI_SERVO_MENU_FOOD = 1 + SUPPLY_FOOD;
const unsigned int UI_SERVO_MENU_FUEL = 1 + SUPPLY_FUEL;
const unsigned int UI_SERVO_MENU_ENGINE = 1 + SUPPLY_ENGINE;
const unsigned int UI_SERVO_MENU_BATTERY = 1 + SUPPLY_BATTERY;
const unsigned int UI_SERVO_MENU_BUMPER = 1 + SUPPLY_BUMPER;
const unsigned int UI_SERVO_MENU_TIRE = 1 + SUPPLY_TIRE;
const unsigned int UI_SERVO_MENU_PHOTOS = 1 + SUPPLY_PHOTOS;
const unsigned int UI_SERVO_MENU_MEDICAL_KIT = 1 + SUPPLY_MEDICAL_KIT;

// TAKE PHOTOS MENU OPTIONS
const unsigned int UI_TAKE_PHOTOS_MENU_EXIT = 0;
const unsigned int UI_TAKE_PHOTOS_MENU_BEACH = 1;
const unsigned int UI_TAKE_PHOTOS_MENU_ANIMAL = 2;
const unsigned int UI_TAKE_PHOTOS_MENU_TOWN = 3;
const unsigned int UI_TAKE_PHOTOS_MENU_CITY = 4;
const unsigned int UI_TAKE_PHOTOS_MENU_LANDMARK = 5;

const unsigned int CHANCE_OF_GETTING_KIDNAPPED = 5;

const unsigned int FORTUNE_VEGEMITE = 0;
const unsigned int FORTUNE_GOT_TOWED_200_KM = 1;
const unsigned int FORTUNE_GOT_FREE_40_LITERS_OF_GAS = 2;

const unsigned int REST_PLAYER_HEALTH_RECOVERY_POINTS = 5;
const unsigned int VEGEMITE_PLAYER_HEALTH_RECOVERY_POINTS = 2;

const unsigned int UI_PIGS_MENU_RUN = 0;
const unsigned int UI_PIGS_MENU_BRIBE = 1;
const unsigned int UI_PIGS_MENU_SURRENDER = 2;


inline bool randomEvent(int probability) {
	return ((rand() % 100) + 1) <= probability; // covers [1 to 100]
}

// (a,b] exclusive-inclusive, TODO: make it [a,b] fully inclusive
inline unsigned int randomBetween(unsigned int a, unsigned int b) {
	return static_cast<unsigned int>(rand()) % (b - a + 1) + a;
}

#endif
