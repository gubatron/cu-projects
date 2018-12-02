#include "Servo.h"
#include "Supply.h"

void Servo::resetCart() {
    if (!cart.empty()) {
        cart.clear();
    }
    cart = Supply::emptyCart();
}

void Servo::addSupplyToCart(const Supply &productChoice, int productAmount) {
    cart[productChoice] += productAmount;
}

void Servo::resetSupply(const Supply &productChoice) {
    cart[productChoice] = 0;
}

/** Used at all servos but the first one*/
float Servo::getTotal(unsigned int milestonesOffset) {
    float invoiceAmount = 0;
    for (std::pair<Supply, int> keyValue : cart) {
        Supply supply = keyValue.first;
        int amount = keyValue.second;
        float supplyTotal = supply.costPerUnit * amount;
        invoiceAmount += supplyTotal;
    }
    return invoiceAmount * getSurchargePercent(milestonesOffset);
}

float Servo::getSurchargePercent(unsigned int milestoneOffset) const {
    return static_cast<float>(1 + (milestoneOffset * .25));
}

void Servo::checkout(Van &van, unsigned int milestonesOffset) {
    // restock the van with our cart, and charge it the full amount of our cart's contents
    van.restock(cart, getTotal(milestonesOffset));
}

float Servo::getSupplyCost(const Supply &productChoice, unsigned int milestoneOffset) const {
    return productChoice.costPerUnit * getSurchargePercent(milestoneOffset);
}

std::map<Supply, int> Servo::getShoppingCart() {
    return cart;
}
