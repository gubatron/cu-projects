#include "Common.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(int playerNumber, std::string playerName) : number(playerNumber), name(playerName), health(100) {
    }

    int getPlayerNumber() const;

    std::string getName() const;

    int getHealth() const;

    int affectHealth(int healthChange);

private:
    const int number;
    int health;
    const std::string name;
};

#endif
