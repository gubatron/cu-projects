#include "Player.h"

// implementation file


std::string Player::getName() const {
    return name;
}

int Player::getPlayerNumber() const {
    return number;
}

int Player::getHealth() const {
    return health;
}

int Player::affectHealth(int healthChange) {
    health += healthChange;
    return health;
}
