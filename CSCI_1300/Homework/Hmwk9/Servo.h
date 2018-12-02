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
        //supplies = Supply::possibleSupplies();
        resetCart();
    }

    double getSurchargePremium(unsigned int milestoneOffset) {
        return (milestoneOffset * 0.25) + 1; // prices increment at per milestone
    }

    void addSupplyToCart(const Supply &productChoice, int productAmount);

    void resetSupply(const Supply &productChoice);

    float getSupplyCost(const Supply &productChoice, unsigned int milestoneOffset) const;

    float getTotal(unsigned int milestonesOffset);

    /** Each milestone adds 25% surcharge */
    float getSurchargePercent(unsigned int milestoneOffset) const;

    void checkout(Van &van, unsigned int milestonesOffset);
    // van.restock(cart,getTotal())

    std::map<Supply, int> getShoppingCart();


private:
    void resetCart(); // adds all supplies to cart with amount zero
    std::vector<Supply> supplies; // "film", the name won't change CONSTANT
    std::map<Supply, int> cart; // shopping cart
};

#endif
