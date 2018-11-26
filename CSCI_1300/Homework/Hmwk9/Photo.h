#include "Common.h"

#ifndef PHOTO_H
#define PHOTO_H

class Photo {
public:
    Photo(const int ID,
          const float chance,
          const float moneyEarned,
          const unsigned int photosNeeded) :
    id(ID),
    probability(chance),
    earnings(moneyEarned),
    photosTaken(photosNeeded) {
    }

    const int id;
    const float probability;
    const float earnings;
    const unsigned int photosTaken;
};

const Photo POSSIBLE_PHOTOS[] = {
Photo(PHOTO_BEACH, PHOTO_BEACH_PROBABILITY, PHOTO_BEACH_EARNINGS, PHOTO_BEACH_PHOTOS_TAKEN),
Photo(PHOTO_ANIMAL, PHOTO_ANIMAL_PROBABILITY, PHOTO_ANIMAL_EARNINGS, PHOTO_ANIMAL_PHOTOS_TAKEN),
Photo(PHOTO_TOWN, PHOTO_TOWN_PROBABILITY, PHOTO_TOWN_EARNINGS, PHOTO_TOWN_PHOTOS_TAKEN),
Photo(PHOTO_CITY, PHOTO_CITY_PROBABILITY, PHOTO_CITY_EARNINGS, PHOTO_CITY_PHOTOS_TAKEN),
Photo(PHOTO_LANDMARK, PHOTO_LANDMARK_PROBABILITY, PHOTO_LANDMARK_EARNINGS, PHOTO_LANDMARK_PHOTOS_TAKEN)
};

#endif //PHOTO_H
