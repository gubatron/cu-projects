#include "Common.h"

#ifndef PHOTO_H
#define PHOTO_H

class Photo {
public:
    Photo(const int id_,
          const std::string &name_,
          const float probability_,
          const float earnings_,
          const unsigned int photosTaken_) :
    id(id_),
    name(name_),
    probability(probability_),
    earnings(earnings_),
    photosTaken(photosTaken_) {
    }

    const int id;
    const std::string name;
    const float probability;
    const float earnings;
    const unsigned int photosTaken;
};

const Photo POSSIBLE_PHOTOS[] = {
Photo(PHOTO_BEACH, "Beach", PHOTO_BEACH_PROBABILITY, PHOTO_BEACH_EARNINGS, PHOTO_BEACH_PHOTOS_TAKEN),
Photo(PHOTO_ANIMAL, "Animal", PHOTO_ANIMAL_PROBABILITY, PHOTO_ANIMAL_EARNINGS, PHOTO_ANIMAL_PHOTOS_TAKEN),
Photo(PHOTO_TOWN, "Town", PHOTO_TOWN_PROBABILITY, PHOTO_TOWN_EARNINGS, PHOTO_TOWN_PHOTOS_TAKEN),
Photo(PHOTO_CITY, "City", PHOTO_CITY_PROBABILITY, PHOTO_CITY_EARNINGS, PHOTO_CITY_PHOTOS_TAKEN),
Photo(PHOTO_LANDMARK, "Landmark", PHOTO_LANDMARK_PROBABILITY, PHOTO_LANDMARK_EARNINGS, PHOTO_LANDMARK_PHOTOS_TAKEN)
};

#endif //PHOTO_H
