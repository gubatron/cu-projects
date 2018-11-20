#include "Common.h"
#include "Player.h"
#include "Milestone.h"
#include "Servo.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    
    std::string enterPlayer(std::string playerNameInput);
    
    int readMilestonesFile(std::string filePath);

    void setDate(int dayInput); // not sure if this is correct
    
    int visitServo(std::string purchaseItem); // not sure if this is correct

private:
    Player playerName;
    Milestone location;
    Servo store; // not sure if this is correct
    

};

#endif