#include "Common.h"
#include "Supply.h"
#include "Van.h"

#ifndef SERVO_H
#define SERVO_H

/**
 * We will have a single Servo instance.
 * All Forts will reuse this Servo instance to allow player to purchase supplies.
 *
 * The servo can:
 *  -> List all available supplies with their prices and units.
 *  -> Add supplies to a shopping cart
 *  -> Remove supplies from shopping cart
 *  -> Reset the shopping cart (empty cart)
 *  -> Checkout
 */
class Servo {
public:
	// default constructor - initialize variables
	Servo() {
		//supplies = {};
		initializeSupplies();
		resetCart();
	}

	double getSurchargePremium(int milestoneOffset) {
		return (milestoneOffset * 0.25) + 1; // prices increment at per milestone
	}


	void addSupplyToCart(Supply &productChoice, int productAmount);

	float getTotal();

	/** Each milestone adds 25% surcharge */
	double getSurchargePercent(unsigned int milestoneOffset);

	void checkout(Van &van);
		// van.restock(cart,getTotal())

private:
    void initializeSupplies();
	void resetCart(); // adds all supplies to cart with amount zero
	std::vector<Supply> supplies; // "film", the name won't change CONSTANT
	std::map<Supply, int> cart; // shopping cart
};

#endif
