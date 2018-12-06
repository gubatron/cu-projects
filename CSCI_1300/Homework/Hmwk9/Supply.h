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

    /** Returns a map of supplies with amounts set to 0, an empty shopping cart */
    static std::map<Supply, int> emptyCart();

    const int id; // supply identifier, is the same position in the Servo's supplies array
    const std::string name; // name of supply, e.g. Tire, Film, Battery, Medical Kit
    const float costPerUnit; // cost in AUD
    const int minimumPurchaseUnits;
    const int recommendedPurchaseUnits;
    const std::string unitName; // e.g. liters, units, kgs
    const std::string pluralUnitName;

    bool operator<(const Supply &other) const {
        return id < other.id;
    }

    bool operator==(const Supply &other) const {
        return id == other.id;
    }
};

// The Servo's supply catalog. These instances are defined here and nowhere else and they cannot change, therefore
// they are declared as an array of const Supply objects.
const std::array<Supply, 8> SUPPLY_CATALOG {
Supply(SUPPLY_FOOD, "Food", 0.5, 1, 90, "kg", "kgs"),
Supply(SUPPLY_FUEL, "Fuel", 1.5, 36, 40, "liter", "liters"),
Supply(SUPPLY_ENGINE, "Engine", 40, 1, 1, "engine", "engines"),
Supply(SUPPLY_BATTERY, "Battery", 40, 1, 1, "battery", "batteries"),
Supply(SUPPLY_BUMPER, "Bumper", 40, 1, 1, "bumper", "bumpers"),
Supply(SUPPLY_TIRE, "Tire", 20, 1, 0, "tire", "tires"),
Supply(SUPPLY_PHOTOS, "Photos", 0.05f, 36, 36, "photo", "photos"),
Supply(SUPPLY_MEDICAL_KIT, "Medical Kit", 25, 1, 0, "kit", "kits")
};

// did not want to create a .cpp file just for one method, also the array above
// was better in the .h so the possible supplies can be included in Servo.cpp.
inline std::map<Supply, int> Supply::emptyCart() {
    std::map<Supply, int> empty;
    for (auto &it: SUPPLY_CATALOG) {
        empty.insert(std::make_pair(it, 0));
    }
    return empty;
}

#endif
