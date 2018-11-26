#include "Common.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(size_t playerNumber, std::string playerName) : number(playerNumber), name(playerName), health(100) {
    }

    size_t getPlayerNumber() const;

    std::string getName() const;

    int getHealth() const;

    int affectHealth(int healthChange);

    bool operator==(const Player &other) const;

private:
    const size_t number;
    const std::string name;
    int health;
};

#endif
