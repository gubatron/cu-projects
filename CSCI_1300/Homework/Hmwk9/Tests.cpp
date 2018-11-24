#include "Game.h"
#include "Tests.h"

bool testServoPurchase() {
    Game game;
    Van van = game.getVan();
    Supply food = VECTOR_POSSIBLE_SUPPLIES[SUPPLY_FOOD];
    Supply engine = VECTOR_POSSIBLE_SUPPLIES[SUPPLY_ENGINE];
    if (van.getAmountOfSupply(SUPPLY_FOOD) != 0) {
        std::cout << "testServoPurchase() failed - Van shouldn't have food at the start" << std::endl;
        return false;
    }

    std::cout << van.distanceTraveled() << std::endl;

    // shop around
    game.getServo().addSupplyToCart(food, 4);
    game.getServo().addSupplyToCart(engine, 1);
    game.getServo().addSupplyToCart(food, 1);

    // check out
    game.getServo().checkout(van, game.getCurrentMilestoneOffset());

    int amountOfFoodInVan = van.getAmountOfSupply(SUPPLY_FOOD);
    if (amountOfFoodInVan != 5) {
        std::cout << "testServoPurchase() failed - Van should have 5 " << food.pluralUnitName << " of " << food.name
                  << " (" << amountOfFoodInVan << ")" << std::endl;
        return false;
    }

    std::cout << "===============" << std::endl;
    van.move(400);
    std::cout << van.distanceTraveled() << std::endl;
    std::cout << van.distanceTraveled() << std::endl;
    return true;
}

bool calendarTests() {
    Calendar jan1(2019, 1, 1);
    Calendar dec31(2019, 12, 31);
    Calendar jan1_2020(2020, 1, 1);
    long daysDifference = jan1_2020 - jan1;
    long daysDifference2 = jan1 - jan1_2020;
    if (daysDifference != daysDifference2) {
        std::cout << "calendarTests() failed - dayDifference should be the same no matter the order" << std::endl;
        return false;
    }
    if (daysDifference != 365) {
        std::cout << "calendarTests() failed - dayDifference is not 365 between jan1 and jan1_2020" << std::endl;
        return false;
    }
    std::cout << "calendarTests() success - jan1_2020 - jan1 = " << daysDifference << " == " << daysDifference2 << std::endl;
    return true;
}

bool testRestTurn() {
    Game game;
    Van van = game.getVan();
    int daysLeftFromStart = game.daysLeft();
    van.modifySupplyAmount(SUPPLY_FOOD, 100);
    std::cout << "testRestTurn() success - Days before first rest = " << daysLeftFromStart << std::endl;
    game.rest();
    int daysAfterRest = game.daysLeft();
    if (daysAfterRest == (daysLeftFromStart - 1) && daysAfterRest > daysLeftFromStart) {
        std::cout << "testRestTurn() failed - daysAfterRest = " << daysAfterRest << ", daysLeftFromStart = "
                  << daysLeftFromStart << std::endl;
        return false;
    }
    std::cout << "testRestTurn() success - Days after first rest = " << daysAfterRest << std::endl;
    game.rest();
    daysAfterRest = game.daysLeft();
    if (daysAfterRest == (daysLeftFromStart - 2) && daysAfterRest > daysLeftFromStart) {
        std::cout << "testRestTurn() failed - daysAfterRest = " << daysAfterRest << ", daysLeftFromStart = "
                  << daysLeftFromStart << std::endl;
        return false;
    }
    std::cout << "testRestTurn() success - Days after second rest = " << daysAfterRest << std::endl;
    return true;
}

bool testRandomEvents() {
	int n = 0;
	for (int i = 0; i < 1000000; i++) {
		if (randomEvent(35)) {
			n++;
		}
	}
	std::cout << "testRandomEvents - n for 35% = " << n << std::endl;
	return true;
}

bool runTests() {
    bool passedAll = true;
    passedAll = passedAll && testServoPurchase();
    passedAll = passedAll && calendarTests();
    passedAll = passedAll && testRestTurn();
	passedAll = passedAll && testRandomEvents();

    if (!passedAll) {
        std::cout << "TESTS KO!";
    } else {
        std::cout << "TESTS OK!";
    }

    return passedAll;
}
