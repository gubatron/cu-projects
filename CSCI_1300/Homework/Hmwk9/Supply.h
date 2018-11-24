#include "Common.h"

#ifndef SUPPLY_H
#define SUPPLY_H

// where methods and member variables are defined
class Supply {
public:
    Supply(int supplyId,
           std::string supplyName,
           float cost,
           int minimumUnits,
           int recommendedUnits,
           std::string unit,
           std::string pluralUnit) :
    id(supplyId),
    name(supplyName),
    costPerUnit(cost),
    minimumPurchaseUnits(minimumUnits),
    recommendedPurchaseUnits(recommendedUnits),
    unitName(unit),
    pluralUnitName(pluralUnit) {
    }

    static std::map<Supply, int> emptyCart() {
        std::map<Supply, int> empty;
        std::vector<Supply> supplies = possibleSupplies();
        for (auto &it: supplies) {
            empty.insert(std::make_pair(it, 0));
        }
        return empty;
    }

    static std::vector<Supply> possibleSupplies() {
        std::vector<Supply> supplies;
        supplies.emplace_back(Supply(0, "Tire", 20, 1, 0, "tire", "tires"));
        supplies.emplace_back(Supply(1, "Food", 0.5, 1, 90, "kg", "kgs"));
        supplies.emplace_back(Supply(2, "Film", 2, 20, 0, "roll", "rolls"));
        supplies.emplace_back(Supply(3, "Engine", 40, 1, 1, "engine", "engines"));
        supplies.emplace_back(Supply(4, "Battery", 40, 1, 1, "battery", "batteries"));
        supplies.emplace_back(Supply(5, "Bumper", 40, 1, 1, "bumper", "bumpers"));
        supplies.emplace_back(Supply(6, "Medical Kit", 25, 1, 0, "kit", "kits"));
        supplies.emplace_back(Supply(7, "Fuel", 1.5, 1, 36, "liter", "liters"));
        return supplies;
    }

    bool operator<(const Supply &other) const {
        return id < other.id;
    }

    bool operator==(const Supply &other) const {
        return id == other.id;
    }

    const int id; // supply identifier, is the same position in the Servo's supplies array
    const std::string name; // name of supply, e.g. Tire, Film, Battery, Medical Kit
    const float costPerUnit; // cost in AUD
    const int minimumPurchaseUnits;
    const int recommendedPurchaseUnits;
    const std::string unitName; // e.g. liters, units, kgs
    const std::string pluralUnitName;
};

#endif
