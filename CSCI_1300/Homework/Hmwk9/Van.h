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
        modifySupplyAmount(SUPPLY_FUEL, 1);
        modifySupplyAmount(SUPPLY_FOOD, 2);
        modifySupplyAmount(SUPPLY_ENGINE, 1);
        modifySupplyAmount(SUPPLY_BUMPER, 1);
        modifySupplyAmount(SUPPLY_BATTERY, 1);
        modifySupplyAmount(SUPPLY_TIRE, 4);
    }

    unsigned int distanceTraveled() {
        return distance;
    }

    float balance() {
        return money;
    }

    void spend(float amountOfMoney) {
        // Make sure they can't hack Van's Balance by spending negative money
        if (amountOfMoney < 0) {
            amountOfMoney *= -1;
        }
        money -= amountOfMoney;
    }

    void earn(float amountOfMoney) {
        if (amountOfMoney < 0) {
            amountOfMoney *= -1;
        }
        money += amountOfMoney;
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

    int getAmountOfSupply(int supplyId) {
        // static_cast is to get rid of old style cast warning if we did "(unsigned long)"
        // warning: use of old-style cast [-Wold-style-cast]
        Supply supply = SUPPLY_CATALOG[static_cast<unsigned long>(supplyId)];
        return supplies[supply];
    }

    /** Used by fortune and misfortune events */
    void modifySupplyAmount(int supplyId, int amount) {
        // static_cast is to get rid of old style cast warning if we did "(unsigned long)"
        // warning: use of old-style cast [-Wold-style-cast]
        Supply supply = SUPPLY_CATALOG[static_cast<unsigned long>(supplyId)];
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
