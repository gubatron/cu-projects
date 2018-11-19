#include "Common.h"

#ifndef HEALTH_H
#define HEALTH_H


class Health {
public:
    Health();
    
    Helath(bool eventInput); // default constructor
    
    double healthBar(double value);

private: 
    bool event;
    // one per player
    // Sickness occurs at random
}; 

#endif

// impacted by sickness
// impacted by happiness
// each player has a health bar