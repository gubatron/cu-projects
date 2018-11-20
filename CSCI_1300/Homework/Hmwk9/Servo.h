#include "Common.h"
#include "Supply.h"

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
        initializeSupplies();
    }

private:
    void initializeSupplies();
    float surchargePremium; // extra percentage to charge on supplies, goes from 0.0 to 1.0)
    std::vector<Supply> supplies; // "film", the name won't change CONSTANT
};

#endif
