#include "Game.h"
#include "Tests.h"

bool testServoPurchase() {
    Game game;
    Van van = game.getVan();
    Supply food = SUPPLY_CATALOG[SUPPLY_FOOD];
    Supply engine = SUPPLY_CATALOG[SUPPLY_ENGINE];
    if (van.getAmountOfSupply(SUPPLY_FOOD) != 2) {
        std::cout << "testServoPurchase() failed - Van shouldn't have more than 1 pound of food at the start ("
                  << van.getAmountOfSupply(SUPPLY_FOOD) << ")" << std::endl;
        return false;
    }

    std::cout << van.distanceTraveled() << std::endl;

    // shop around
    game.getServo().addSupplyToCart(food, 4);
    game.getServo().addSupplyToCart(engine, 1);
    game.getServo().addSupplyToCart(food, 1);

    // check out
    game.getServo().checkout(van, game.getLastVisitedMilestoneOffset());

    int amountOfFoodInVan = van.getAmountOfSupply(SUPPLY_FOOD);
    if (amountOfFoodInVan != 7) {
        std::cout << "testServoPurchase() failed - Van should have 7 " << food.pluralUnitName << " of " << food.name
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
    long daysDifference = jan1_2020.subtractDays(jan1);
    long daysDifference2 = jan1.subtractDays(jan1_2020);
    if (daysDifference != 365) {
        std::cout << "calendarTests() failed - dayDifference is not 365 between jan1 and jan1_2020" << std::endl;
        std::cout << daysDifference << std::endl;
        return false;
    }
    if (daysDifference2 != -365) {
        std::cout << "calendarTests() failed - dayDifference is not -365 between jan1_2020 and jan1" << std::endl;
        std::cout << daysDifference2 << std::endl;
        return false;
    }

    std::cout << "calendarTests() success - jan1_2020 - jan1 = " << daysDifference << " == " << daysDifference2
              << std::endl;
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

    for (int i = 0; i < 100; i++) {
        int n = randomBetween(21, 25);
        if (!(n >= 21 && n <= 25)) {
            std::cout << "randomBetween() failed - " << n << std::endl;
            return false;
        }
    }
    std::cout << "randomBetween() succeeded " << std::endl;

    // 0 based numbers?
    int n_0s = 0;
    int n_1s = 0;
    for (int i = 0; i < 1000; i++) {
        int n = randomBetween(0, 1);
        if (n==0) {
            n_0s++;
        } else if (n==1) {
            n_1s++;
        }
    }

    if (n_0s == 0) {
        std::cout << "randomBetween(0,1) failed, no 0s were generated" << std::endl;
        return false;
    }

    if (n_1s == 0) {
        std::cout << "randomBetween(0,1) failed, no 1s were generated" << std::endl;
        return false;
    }

    std::cout << "randomBetween(0,1) sucess, 0s=" << n_0s << ", 1s=" << n_1s << " were generated" << std::endl;

    return true;
}

bool testRestTurn() {
    Game game;
    game.enterPlayer("Alice");
    game.enterPlayer("Bob");
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


bool testTravelTurn() {
    // Test without misfortunes. Just travel method
    srand(5); // this test always travels the same "random" distance
    Game game;
    game.enterPlayer("Nicole");
    game.enterPlayer("Austin");
    game.enterPlayer("Angel");
    game.enterPlayer("Paulina");
    game.getVan().modifySupplyAmount(SUPPLY_FOOD, 100);
    game.getVan().modifySupplyAmount(SUPPLY_FUEL, 40);

    std::cout << "=====================================================================" << std::endl;
    std::cout << "START:" << std::endl;
    std::cout << "testTravelTurn() - distance " << game.traveledDistance() << std::endl;
    std::cout << "testTravelTurn() - food " << game.getVan().getAmountOfSupply(SUPPLY_FOOD) << std::endl;
    std::cout << "testTravelTurn() - fuel " << game.getVan().getAmountOfSupply(SUPPLY_FUEL) << std::endl;
    std::cout << "testTravelTurn() - current milestone: " << game.getLastVisitedMilestone().getName() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    game.travel();
    std::cout << "testTravelTurn() - distance " << game.traveledDistance() << std::endl;
    std::cout << "testTravelTurn() - food " << game.getVan().getAmountOfSupply(SUPPLY_FOOD) << std::endl;
    std::cout << "testTravelTurn() - fuel " << game.getVan().getAmountOfSupply(SUPPLY_FUEL) << std::endl;
    std::cout << "testTravelTurn() - current milestone: " << game.getLastVisitedMilestone().getName() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    if (game.getLastVisitedMilestoneOffset() != 0) {
        std::cout << "testTravelTurn() failed - at this point the last visited milestone offset should be 0, not "
                  << game.getLastVisitedMilestoneOffset() << std::endl;
        return false;
    }

    game.travel();
    std::cout << "testTravelTurn() - distance " << game.traveledDistance() << std::endl;
    std::cout << "testTravelTurn() - food " << game.getVan().getAmountOfSupply(SUPPLY_FOOD) << std::endl;
    std::cout << "testTravelTurn() - fuel " << game.getVan().getAmountOfSupply(SUPPLY_FUEL) << std::endl;
    std::cout << "testTravelTurn() - current milestone: " << game.getLastVisitedMilestone().getName() << std::endl;
    std::cout << "=====================================================================" << std::endl;
    game.travel();
    std::cout << "testTravelTurn() - distance " << game.traveledDistance() << std::endl;
    std::cout << "testTravelTurn() - food " << game.getVan().getAmountOfSupply(SUPPLY_FOOD) << std::endl;
    std::cout << "testTravelTurn() - fuel " << game.getVan().getAmountOfSupply(SUPPLY_FUEL) << std::endl;
    std::cout << "testTravelTurn() - current milestone: " << game.getLastVisitedMilestone().getName() << std::endl;
    return true;
}

bool testTakePhotosTurn() {
    Game game;
    game.enterPlayer("Nicole");
    game.enterPlayer("Austin");
    game.enterPlayer("Angel");
    game.enterPlayer("Paulina");

    game.getVan().modifySupplyAmount(SUPPLY_FOOD, 100);
    game.getVan().modifySupplyAmount(SUPPLY_FUEL, 40);
    game.getVan().modifySupplyAmount(SUPPLY_PHOTOS, 45);


    std::cout << "NO PICTURES TAKEN." << std::endl;
    std::cout << "testTakePhotosTurn() - daysTranscurred: " << game.daysTranscurred() << std::endl;
    std::cout << "testTakePhotosTurn() - photos left: " << game.getVan().getAmountOfSupply(SUPPLY_PHOTOS) << std::endl;
    std::cout << "testTakePhotosTurn() - balance: " << game.getVan().balance() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    srand(5000); // restart number generator seed for deterministic results

    bool tookBeachPhotos = game.takePhotos(POSSIBLE_PHOTOS[PHOTO_BEACH]);

    std::cout << "testTakePhotosTurn() - tookBeachPhotos? " << tookBeachPhotos << std::endl;
    std::cout << "testTakePhotosTurn() - daysTranscurred: " << game.daysTranscurred() << std::endl;
    std::cout << "testTakePhotosTurn() - photos left: " << game.getVan().getAmountOfSupply(SUPPLY_PHOTOS) << std::endl;
    std::cout << "testTakePhotosTurn() - balance: " << game.getVan().balance() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    bool tookAnimalPhotos = game.takePhotos(POSSIBLE_PHOTOS[PHOTO_ANIMAL]);
    std::cout << "testTakePhotosTurn() - tookAnimalPhotos? " << tookAnimalPhotos << std::endl;
    std::cout << "testTakePhotosTurn() - daysTranscurred: " << game.daysTranscurred() << std::endl;
    std::cout << "testTakePhotosTurn() - photos left: " << game.getVan().getAmountOfSupply(SUPPLY_PHOTOS) << std::endl;
    std::cout << "testTakePhotosTurn() - balance: " << game.getVan().balance() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    bool tookTownPhotos = game.takePhotos(POSSIBLE_PHOTOS[PHOTO_TOWN]);
    std::cout << "testTakePhotosTurn() - tookTownPhotos? " << tookTownPhotos << std::endl;
    std::cout << "testTakePhotosTurn() - daysTranscurred: " << game.daysTranscurred() << std::endl;
    std::cout << "testTakePhotosTurn() - photos left: " << game.getVan().getAmountOfSupply(SUPPLY_PHOTOS) << std::endl;
    std::cout << "testTakePhotosTurn() - balance: " << game.getVan().balance() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    bool tookCityPhotos = game.takePhotos(POSSIBLE_PHOTOS[PHOTO_CITY]);
    std::cout << "testTakePhotosTurn() - tookCityPhotos? " << tookCityPhotos << std::endl;
    std::cout << "testTakePhotosTurn() - daysTranscurred: " << game.daysTranscurred() << std::endl;
    std::cout << "testTakePhotosTurn() - photos left: " << game.getVan().getAmountOfSupply(SUPPLY_PHOTOS) << std::endl;
    std::cout << "testTakePhotosTurn() - balance: " << game.getVan().balance() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    bool tookLandmarkPhotos = game.takePhotos(POSSIBLE_PHOTOS[PHOTO_LANDMARK]);
    std::cout << "testTakePhotosTurn() - tookLandmarkPhotos? " << tookLandmarkPhotos << std::endl;
    std::cout << "testTakePhotosTurn() - daysTranscurred: " << game.daysTranscurred() << std::endl;
    std::cout << "testTakePhotosTurn() - photos left: " << game.getVan().getAmountOfSupply(SUPPLY_PHOTOS) << std::endl;
    std::cout << "testTakePhotosTurn() - balance: " << game.getVan().balance() << std::endl;
    std::cout << "=====================================================================" << std::endl;

    return true;
}

bool runTests() {
    bool passedAll = true;
    passedAll = passedAll && testServoPurchase();
    passedAll = passedAll && calendarTests();
    passedAll = passedAll && testRestTurn();
    passedAll = passedAll && testRandomEvents();
    passedAll = passedAll && testTravelTurn();
    passedAll = passedAll && testTakePhotosTurn();


    if (!passedAll) {
        std::cout << "TESTS KO!";
    } else {
        std::cout << "TESTS OK!";
    }

    return passedAll;
}
