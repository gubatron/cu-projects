#include "Common.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    
    string getName(string nameInput);
    
    int setPlayer(int playerNumber); // p1 or p2
    // Turn
    // Servo
    // Misfortune
    // Health

private: 
    string name; // two players total ***** Should each of them have a private member?
}; 

#endif

// two players
// HEALTH bars
// eat food
// have happiness
// have sickness