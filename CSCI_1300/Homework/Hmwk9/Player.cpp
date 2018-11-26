#include "Player.h"

std::string Player::getName() const {
    return name;
}

size_t Player::getPlayerNumber() const {
    return number;
}

int Player::getHealth() const {
    return health;
}

int Player::affectHealth(int healthChange) {
    health += healthChange;
    return health;
}

bool Player::operator==(const Player &other) const {
    return other.getPlayerNumber() == getPlayerNumber();
}