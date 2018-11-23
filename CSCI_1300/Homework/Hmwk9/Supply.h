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

	bool operator<(const Supply &other) const {
		return name < other.name;
	}

private:
    const int id; // supply identifier, is the same position in the Servo's supplies array
    const std::string name; // name of supply, e.g. Tire, Film, Battery, Medical Kit
    const float costPerUnit; // cost in AUD
    const int minimumPurchaseUnits;
    const int recommendedPurchaseUnits;
    const std::string unitName; // e.g. liters, units, kgs
    const std::string pluralUnitName;

	
};

#endif
