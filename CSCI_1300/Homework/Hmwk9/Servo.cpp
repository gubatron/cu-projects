#include "Servo.h"
#include "Supply.h"

// implementation file

void Servo::initializeSupplies() {
  supplies.emplace_back(Supply(0, "Tire", 20, 1, 0, "tire", "tires"));
  supplies.emplace_back(Supply(1, "Food", 0.5, 1, 90, "kg", "kgs"));
  supplies.emplace_back(Supply(2, "Film", 2, 20, 0, "roll", "rolls"));
  supplies.emplace_back(Supply(3, "Engine", 40, 1, 1, "engine", "engines"));
  supplies.emplace_back(Supply(4, "Battery", 40, 1, 1, "battery", "batteries"));
  supplies.emplace_back(Supply(5, "Bumper", 40, 1, 1, "bumper", "bumpers"));
  supplies.emplace_back(Supply(6, "Medical Kit", 25, 1, 0, "kit", "kits"));
  supplies.emplace_back(Supply(7, "Fuel", 1.5, 1, 36, "liter", "liters"));
}

void Servo::resetCart()
{
	for (auto &it: supplies) {
		cart.insert(std::make_pair(it, 0));
	}	
}

void Servo::addSupplyToCart(Supply &productChoice, int productAmount) {
	// TODO : add to previous amount
	cart.insert(std::make_pair(productChoice, productAmount));
}

float Servo::getTotal() {
	return 0.0f;
}

double Servo::getSurchargePercent(unsigned int milestoneOffset) {
	return 1 + (milestoneOffset * .25);
}

void Servo::checkout(Van &van) {
}
