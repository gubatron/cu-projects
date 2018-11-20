#include "Common.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(std::string playerName, int playerNumber) : name(playerName), number(playerNumber), health(100) {
    }

    std::string getName() const;

    int getPlayerNumber() const;

    int getHealth() const;

    int affectHealth(int healthChange);

private:
    const std::string name; // two players total ***** Should each of them have a private member?
    const int number;
    int health;
};

#endif
