#include "Common.h"
#include "Supply.h"

#ifndef VAN_H
#define VAN_H

class Van {
public:
    Van() {
        supplies = Supply::emptyCart();
        money = 1000;
        distance = 0;
    }

    unsigned int distanceFromOrigin() {
        return distance;
    }

    float balance() {
        return money;
    }

    void restock(std::map<Supply, int> cart, float invoiceAmount) {
        money -= invoiceAmount;

        for (auto &keyValue : cart) {
            // in std::map, key->value are inserted as a std::pair
            // where the key, is the first element of the pair
            // and the value is the second one.
            //
            // k == pair.first
            // v == pair.second
            Supply key = keyValue.first;
            int amountBought = keyValue.second;
            supplies[key] += amountBought;
        }
    }

    /** Used by fortune and misfortune events */
    void modifySupply(Supply supply, int amount) {
        supplies[supply] += amount;
    }

    void move(unsigned int kilometers) {
        distance += kilometers;
    }

private:
    std::map<Supply, int> supplies; // map { supply -> amountInUnits }
    float money;
    unsigned int distance;

};

#endif
