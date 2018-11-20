#include "Common.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    
    string enterPlayer(string playerNameInput);
    
    int readForts(string fortFile);
    
    int readAttractions(string attractionFile);
    
    void setDate(int dayInput); // not sure if this is correct
    
    int visitServo(string purchaceItem); // not sure if this is correct

private:
    Player playerName;
    Milestone location;
    Date day; // not sure if this is correct
    Servo store; // not sure if this is correct
    

};

#endif