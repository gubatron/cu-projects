#include "Common.h"

#ifndef TURN_H
#define TURN_H

class Turn {
public:
    Turn();
    
    string getChoice(int choiceInput);

private: 
    int choice; // 1) cont; 2) rest; 3) quit
    
    // next milestone
    // date ++
    // food --
    // distance ++
    // @end of turn: chance of misfortune --> pig or sickness which affects health
}; 

#endif

// one turn is 2 days
// 400-800 km per turn
// choose REST or SIGHTSEE/ATTRACTIONS == shorter turn
// display DATE
// display DISTANCE
// display FOOD available 
// display number of FILM
// display MONEY left