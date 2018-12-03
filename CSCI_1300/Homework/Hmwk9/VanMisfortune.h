#include "Common.h"

#ifndef MISFORTUNE_H
#define MISFORTUNE_H

class VanMisfortune {
public:
    VanMisfortune(const unsigned int supplyId_,
                  const unsigned int minToSurvive_,
                  const unsigned int gameOverCode_,
                  const std::string eventDescription_) :
    supplyId(supplyId_),
    minToSurvive(minToSurvive_),
    gameOverCode(gameOverCode_),
    eventDescription(eventDescription_) { }

    const unsigned int supplyId;
    const unsigned int minToSurvive;
    const unsigned int gameOverCode;
    const std::string eventDescription;
};


#endif //MISFORTUNE_H

const std::vector<VanMisfortune> POSSIBLE_VAN_MISFORTUNES = {
    VanMisfortune(SUPPLY_ENGINE, 1, GAME_OVER_ENGINE_BROKE, "Engine broke"),
    VanMisfortune(SUPPLY_TIRE, 4, GAME_OVER_NO_SPARE_TIRES, "Popped a tire"),
    VanMisfortune(SUPPLY_BUMPER, 1, GAME_OVER_NO_BUMPER_CRASH, "Hit a 'roo, bumper destroyed"),
    VanMisfortune(SUPPLY_BATTERY, 1, GAME_OVER_BATTERY_BROKE, "Busted battery"),
};

//   Break Engine, SUPPLY_ENGINE (Supply Id) , , 1 (Min to survive)
//   Tire Popped, SUPPLY_TIRE, -1, 4
//   Hit a Roo, SUPPLY BUMPER, -1, 1
//   Dead Battery, SUPPLY_BATTERY, -1, 1
