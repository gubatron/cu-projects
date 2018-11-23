#include "Common.h"
#include "Supply.h"


#ifndef VAN_H
#define VAN_H

class Van {
public:
	Van() {
		supplies = {};
		money = 0.0f;
		distance = 0;
	}

	unsigned int distanceFromOrigin() {
		return distance;
	}

	// CANNOT BE UNSIGNED - Possible loss of data
	float balance() {
		return money;
	}

	void restock(std::map<Supply, int> cart, float invoiceAmount) {

	}

	/** Used by fortune and misfortune events */
	void modifySupply(Supply supply, int amount) {

	}

	void move(unsigned int kilometers) {
		distance += kilometers;
	}

private:
	std::map<Supply, int> supplies;
	float money;
	int distance;
	
};

#endif
