#include "Servo.h"
#include "Supply.h"

void Servo::resetCart() {
    if (!cart.empty()) {
        cart.clear();
    }
    cart = Supply::emptyCart();
}

void Servo::addSupplyToCart(Supply &productChoice, int productAmount) {
    cart[productChoice] += productAmount;
}

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

float Servo::getSurchargePercent(unsigned int milestoneOffset) {
    return static_cast<float>(1 + (milestoneOffset * .25));
}

void Servo::checkout(Van &van, unsigned int milestonesOffset) {
  // restock the van with our cart, and charge it the full amount of our cart's contents
    van.restock(cart, getTotal(milestonesOffset));
}
