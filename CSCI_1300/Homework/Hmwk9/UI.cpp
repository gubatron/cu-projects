#include "UI.h"
#include "VanMisfortune.h"
#include <fstream>
#include <cmath> // pow

void UI::start(bool debug) {
    if (!debug) {
        // initialize milestones.txt
        // This screen will welcome the player, and will use the enterPlayers() method as needed
        if (!printFile("welcome_screen.txt")) {
            std::cout
            << "error: UI::start: printFile(\"welcome_screen.txt\") failed. File \"welcome_screen.txt\" not found."
            << std::endl;
            return;
        }

        enterPlayer();
        std::cout << "Good, now what's your mate's name?" << std::endl;
        enterPlayer();

        // to check if player quit already on the first enter player screen.
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }

        // Greet the party
        auto party = game.getParty();
        // TODO FUTURE VERSION: Allow to enter many players, and print all the party, not just the two.
        std::cout << std::endl << "Players in the party: " << party[0].getName() << " and " << party[1].getName()
                  << std::endl;

        // Date
        printBreakLine();
        printBreakLine();
        selectStartDate();

        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }

        // Servo
        // This screen tells player about the servo

        printBreakLine();
        printBreakLine();
        printFile("servo_summary.txt");

        servoScreen();
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }
    } else {
        // debug mode initialization
        game.enterPlayer("Alice");
        game.enterPlayer("Bob");
        game.getVan().earn(40000);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_FOOD], 1000);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_FUEL], 1000);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_BATTERY], 10);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_TIRE], 10);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_BUMPER], 20);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_ENGINE], 3);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_PHOTOS], 200);
        game.getServo().checkout(game.getVan(), 0);
        // Let's start on the second

        game.addToStartDate(-3); //5-3 = 2
        game.addDays(1); //1 + 1 = 2
    }

    printPartyStatus();
    printVanSupplies();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Game Loop: While the game state is not over, we keep showing the milestone screen
    // which can take input or direct to other screens.
    while (milestoneScreen() == GAME_NOT_OVER) {}
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    gameOver(game.state());
}

unsigned int UI::milestoneScreen() {
    if (game.state() != GAME_NOT_OVER) {
        return game.state();
    }

    bool servoOptionShown = false;
    showMilestoneMenuOptions(servoOptionShown);

    // Ask user for option
    int option = askForValidMilestoneScreenOption(servoOptionShown);

    // handle option action (switch)
    if (option == UI_MILESTONE_OPTION_TRAVEL) {
        travel();
        fortunes();
        //TODO refactor into checkGameOver();
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }
        pigs();
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }
    } else if (option == UI_MILESTONE_OPTION_REST) {
        rest();
        fortunes();
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }
        pigs();
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }

    } else if (option == UI_MILESTONE_OPTION_TAKE_PHOTOS) {
        takePhotos();
        fortunes();
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }
        pigs();
        if (game.state() != GAME_NOT_OVER) {
            gameOver(game.state());
        }
    } else if (option == UI_MILESTONE_OPTION_CHECK_VAN) {
        printPartyStatus();
        printVanSupplies();
    } else if (option == UI_MILESTONE_OPTION_GO_TO_SERVO) {
        servoScreen();
    }
    return game.state();
}

unsigned int UI::askForValidMilestoneScreenOption(bool servoOptionShown) {
    int maxValidOption = UI_MILESTONE_OPTION_CHECK_VAN;
    if (servoOptionShown) {
        maxValidOption = UI_MILESTONE_OPTION_GO_TO_SERVO;
    }
    int userOption = askIntQuestion("Enter a valid option number", 0, maxValidOption);
    return userOption;
}

void UI::printBreakLine() const {
    std::cout << std::string(80, '-') << std::endl;
}

bool UI::printFile(std::string filePath) const {
    std::string line = "";
    std::ifstream f(filePath);

    if (!f.is_open()) {
        return false;
    }

    while (getline(f, line)) {
        std::cout << line << std::endl;
    }
    f.close();
    return true;
}

void UI::enterPlayer() {
    while (true) {
        std::cout << "Enter a Player name ";

        // If it's the first player being entered, we're on the first screen of the game
        // and we can let the user 'quit' from here already. Otherwise, let the player quit
        // from the previous milestone screen.

        if (game.partyAlive() == 0) {
            std::cout << " ('q' or 'quit' to Exit the game)";
        }
        std::cout << " : ";
        std::string playerName;
        getline(std::cin, playerName);
        toTitle(playerName);
        trim(playerName);

        if (playerName != "") {
            if (game.partyAlive() == 0 && (playerName == UI_OPTION_QUIT_Q || playerName == UI_OPTION_QUIT_QUIT)) {
                game.quit();
                return;
            }

            std::cout << "Is '" << playerName << "' correct? (y/n): ";
            std::string yn;
            getline(std::cin, yn);
            toLower(yn);
            trim(yn);
            std::cout << std::endl;
            if (yn == "y" || yn == "yes" || yn == "YES") {
                game.enterPlayer(playerName);
                return;
            }
        }
    }
}

void UI::selectStartDate() {
    // This screen tells user current date and instructs to choose a start date.
    printFile("start_date_intro.txt");
    Calendar defaultStartDate = game.getStartDate();
    std::cout << "        The default start date is " << defaultStartDate.to_string() << std::endl << std::endl;

    std::cout << std::endl;
    int dateInput = askIntQuestion("Enter a day of September to start your gander", 1, 30);

    // Current date is set to Sept 1st.
    // User will enter a dateInput representing the day of the month to start.
    int daysToAddToStartDate = dateInput - 5; // because start date is set to sep. 5th
    int daysToAddToCurrentDate = dateInput - 1; // because current date is set to sep. 1st.

    // e.g. Say you want to start on the 7th
    // start date = sep 5 => 7 - 5 => Add 2 days to start date => 5 + 2 => 7th.
    // current = sep 5 => 7 - 1 => Add 6 days to current date => 1 + 6  => 7th.

    game.addToStartDate(daysToAddToStartDate);
    game.addDays(daysToAddToCurrentDate);

    std::cout << std::endl << "    Your start date is " << game.getStartDate().to_string() << std::endl;
}

void UI::printServoMenu() {
    //TODO: Print minimum units
    std::cout << std::endl << std::endl << "    You can buy items or leave the store: " << std::endl << std::endl;
    std::cout << "    1. Food............[90 kg per person].....$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_FOOD], game.getLastVisitedMilestoneOffset())
              << std::endl;
    std::cout << "    2. Fuel............[40 L per tank]........$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_FUEL], game.getLastVisitedMilestoneOffset())
              << std::endl;
    std::cout << "    3. Engine.................................$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_ENGINE], game.getLastVisitedMilestoneOffset())
              << std::endl;
    std::cout << "    4. Battery................................$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_BATTERY], game.getLastVisitedMilestoneOffset())
              << std::endl;
    std::cout << "    5. Bumper.................................$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_BUMPER], game.getLastVisitedMilestoneOffset())
              << std::endl;
    std::cout << "    6. Tire...................................$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_TIRE], game.getLastVisitedMilestoneOffset())
              << std::endl;
    std::cout << "    7. Photos..........[36 per package].......$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_PHOTOS], game.getLastVisitedMilestoneOffset())
              << std::endl;
    std::cout << "    8. Medical Kit............................$"
              << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_MEDICAL_KIT], game.getLastVisitedMilestoneOffset())
              << std::endl << std::endl;
    std::cout << "    0. Checkout" << std::endl << std::endl;

    float total = game.getServo().getTotal(game.getLastVisitedMilestoneOffset());
    if (total > 0) {
        printShoppingCart();
        printBreakLine();
        std::cout << std::endl
                  << "Your current total is AUD $" << total << std::endl;
        printBreakLine();
        std::cout
        << "                                                        Your Wallet: AUD $" << game.getVan().balance()
        << std::endl;
        float wouldBeLeft = game.getVan().balance() - total;
        if (wouldBeLeft > 0) {
            std::cout
            << "                                      At checkout you'd be left with AUD $" << wouldBeLeft << std::endl;
        } else {
            std::cout
            << "                Remove items from the shopping cart, you can't afford that much" << std::endl
            << "                    (To remove Product, add it again to the cart with amount 0)" << std::endl;

        }
        printBreakLine();
    } else {
        std::cout << std::endl << "Your cart is empty" << std::endl;
    }

    std::cout << std::endl;
}

void UI::printVanSupplies() {
    std::cout << std::endl << "These are the items in your Van:" << std::endl << std::endl;
    std::cout << std::endl << "Supply" << "\t\t" << "Amount" << std::endl;
    std::cout << std::endl;
    for (std::pair<Supply, int> keyValue : game.getVan().getSupplies()) {
        Supply supply = keyValue.first;
        int amount = keyValue.second;

        std::string unitString = supply.unitName; // singular unit name
        if (amount > 1 || amount == 0) {
            unitString = supply.pluralUnitName;
        }

        std::cout << supply.name << "\t\t" << amount << " " << unitString << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void UI::printPartyStatus() {
    Calendar today = game.getCurrentDate();
    Calendar startDate = game.getStartDate();
    std::cout << std::endl << std::endl;
    printBreakLine();
    std::cout << "      Current Location: " << game.getLastVisitedMilestone().getName() << std::endl;
    std::cout << "          Today's date: " << today.to_string() << std::endl;
    std::cout << "            Start date: " << startDate.to_string() << std::endl;
    std::cout << "           Days passed: " << game.daysTranscurred() << " days" << std::endl;
    std::cout << "             Days left: " << game.daysLeft() << " days" << std::endl;
    printBreakLine();
    auto party = game.getParty();
    Player player1 = party[0];
    Player player2 = party[1];
    // TODO: Print dead instead of health 0
    std::cout << "                Health: " << player1.getName() << " " << player1.getHealth() << " %" << std::endl;
    std::cout << "                        " << player2.getName() << " " << player2.getHealth() << " %" << std::endl;

    std::cout << "                  Food: " << game.getVan().getAmountOfSupply(SUPPLY_FOOD) << " kgs" << std::endl;
    std::cout << "                  Fuel: " << game.getVan().getAmountOfSupply(SUPPLY_FUEL) << " liters" << std::endl;
    std::cout << "                 Money: AUD $" << game.getVan().balance() << std::endl << std::endl;
    std::cout << "        Next Milestone: " << game.distanceToNextMilestone() << " km" << std::endl;
    std::cout << "     Distance Traveled: " << game.traveledDistance() << " km" << std::endl;
    std::cout << "    Distance Remaining: " << game.remainingDistance() << " km" << std::endl;
    std::cout << std::endl << std::endl;
}

void UI::printShoppingCart() {
    std::cout << std::endl;
    printBreakLine();
    std::cout << "YOUR SHOPPING CART:" << std::endl;
    printBreakLine();
    auto cart = game.getServo().getShoppingCart();
    std::cout << "Product" << "\t\t     " << "Price" << "\tAmount" << "\t" << "Sub-total" << std::endl;
    printBreakLine();
    std::cout << std::endl;


    for (std::pair<Supply, int> keyValue : cart) {
        Supply supply = keyValue.first;
        int amount = keyValue.second;
        float supplyTotal = supply.costPerUnit * amount;
        if (amount > 0) {
            std::cout << supply.name << "\t\tAUD $" << supply.costPerUnit << "\t" << amount << "\tAUD $"
                      << std::setprecision(2) << supplyTotal
                      << std::endl;
        }
    }
    std::cout << std::endl;
}

void UI::servoScreen() {
    std::cout << std::endl;
    std::cout << "Clerk:    Ow ya goin' mate! Welcome to the Servo. What can I get for ya?  " << std::endl;

    // call servo supply list and maybe put prices at the end of each line as it reads the file
    while (true) {

        printServoMenu();
        int itemNumber = askIntQuestion("Enter an item number", 0, 8);

        // Leave servo
        if (itemNumber == UI_SERVO_MENU_EXIT) {
            // if there are products in the cart, check out
            float total = game.getServo().getTotal(game.getLastVisitedMilestoneOffset());
            if (total == 0) {
                return;
            }
            if (total > 0) {
                // does the user have enough money?
                float vanBalance = game.getVan().balance();
                if (vanBalance < total) {
                    std::cout << std::endl
                              << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                              << std::endl;
                    std::cout << "Clerk:    HOLD IT MATE!!! AUD $" << vanBalance
                              << " is all you got, the total is AUD $" << total << std::endl;
                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                              << std::endl;
                    std::cout << "Please remove some items from your cart" << std::endl << std::endl;
                    continue;
                } else {
                    game.getServo().checkout(game.getVan(), game.getLastVisitedMilestoneOffset());
                    std::cout << std::endl << "You've paid AUD $" << total << ", you have AUD $"
                              << game.getVan().balance()
                              << " left" << std::endl << std::endl;
                    std::cout << "Clerk:    Thanks! Come again!" << std::endl << std::endl;
                    return;
                }
            }
        }

        if (itemNumber >= UI_SERVO_MENU_FOOD && itemNumber <= UI_SERVO_MENU_MEDICAL_KIT) {
            std::cout << std::endl;
            // Supply purchase = SUPPLY_CATALOG[toInt(itemNumber)];
            // Enter quantity
            Supply supply = SUPPLY_CATALOG[itemNumber - 1];
            int itemQuantity = askIntQuestion(
            "How many " + supply.pluralUnitName + " of " + supply.name + " do you want? (Enter 0 to remove product): ",
            0, UI_NO_LIMIT);

            if (itemQuantity == 0) {
                game.getServo().resetSupply(supply);
                continue; //this breaks the while and starts over
            }
            game.getServo().addSupplyToCart(supply, itemQuantity);

            std::string unitString = supply.unitName; // singular unit name
            if (itemQuantity > 1 || itemQuantity == 0) {
                unitString = supply.pluralUnitName;
            }

            std::cout << std::endl <<
                      "You've added " << itemQuantity << " " << unitString << " of " << supply.name << " for AUD $"
                      << (supply.costPerUnit * itemQuantity *
                          game.getServo().getSurchargePercent(game.getLastVisitedMilestoneOffset()));
        }
    }

}

void UI::travel() {
    game.travel();
    printPartyStatus();
}

void UI::rest() {
    game.rest();
    printPartyStatus();
}

void UI::takePhotos() {
    std::cout << std::endl << std::endl;
    printBreakLine();
    std::cout << "    Attempt to shoot a subject, pick one below:" << std::endl;
    std::cout << std::endl;
    std::cout << "    1. Beach    $" << std::endl;
    std::cout << "    2. Animal   $$" << std::endl;
    std::cout << "    3. Town     $$$" << std::endl;
    std::cout << "    4. City     $$$$" << std::endl;
    std::cout << "    5. Landmark $" << std::endl;
    std::cout << std::endl;
    std::cout << "    0. Exit" << std::endl;
    std::cout << std::endl;

    int photoOption = askIntQuestion("Pick a subject", UI_TAKE_PHOTOS_MENU_EXIT, UI_TAKE_PHOTOS_MENU_LANDMARK);

    if (photoOption == UI_TAKE_PHOTOS_MENU_EXIT) {
        return;
    }

    std::cout << std::endl << std::endl;
    Photo chosenSubject = POSSIBLE_PHOTOS[photoOption - 1];

    int photosLeft = game.getVan().getAmountOfSupply(SUPPLY_PHOTOS);
    if (photosLeft < chosenSubject.photosTaken) {
        std::cout << "Blimey, " << photosLeft << " photos isn't enough to shoot that. Buy Photos at the nearest Servo"
                  << std::endl << std::endl;
        return;
    }

    std::cout << "You chose " << chosenSubject.name << ", you have a " << (chosenSubject.probability * 100)
              << "% chance of taking good photos" << std::endl;
    std::cout << std::endl << "Calculating odds..." << std::endl;
    if (game.takePhotos(chosenSubject)) {
        std::cout << "Success, you took " << chosenSubject.photosTaken << " pictures of " << chosenSubject.name
                  << " and earned AUD $" << chosenSubject.earnings * chosenSubject.photosTaken;
    } else {
        std::cout << "Crikey! You couldn't take a single picture of any " << chosenSubject.photosTaken << ". You took "
                  << chosenSubject.photosTaken << " blurry pictures and earned AUD $0" << std::endl;
    }

    std::cout << std::endl << std::endl;
}

void UI::fortunes() {
    bool fortuneEventWillHappen = randomEvent(40);
    if (!fortuneEventWillHappen) {
        return;
    }

    // If Around Halls Creek (near 2368-100=2268 and 7271+100=7371) you have a 5% chance of getting kidnapped
    if (2268 <= game.traveledDistance() && game.traveledDistance() <= 7371
        && randomEvent(CHANCE_OF_GETTING_KIDNAPPED)) {
        gameOver(GAME_OVER_PLAYER_KIDNAPPED);
        return;
    }

    // Either fortune or misfortune
    bool fortune = randomEvent(50);

    // MISFORTUNES
    if (!fortune) {
        bool healthRelated = randomEvent(50);
        if (healthRelated) {
            healthMisfortune();
        } else {
            vanMisfortune();
        }
    }
        // FORTUNES
    else {
        std::cout << std::endl << std::endl;
        printBreakLine();
        std::cout << "    I WISH I HAD HALF YOUR LUCK!" << std::endl;
        printBreakLine();

        if (game.getLastVisitedMilestone().inTransit()) {
            int fortuneIndex = randomBetween(0, 2);
            if (fortuneIndex == FORTUNE_VEGEMITE) {
                game.recoverBothPlayers(VEGEMITE_PLAYER_HEALTH_RECOVERY_POINTS);
                std::cout << "    You found some VEGEMITE!!!! - Both player's health increased by "
                          << VEGEMITE_PLAYER_HEALTH_RECOVERY_POINTS << "%" << std::endl;
            } else if (fortuneIndex == FORTUNE_GOT_TOWED_200_KM) {
                game.getVan().move(200); // does not spend gas
                std::cout << "    You got towed 200kms!" << std::endl;
            } else if (fortuneIndex == FORTUNE_GOT_FREE_40_LITERS_OF_GAS) {
                game.getVan().modifySupplyAmount(SUPPLY_FUEL, 40);
                std::cout << "    You got FREE 40 liters of gas!" << std::endl;
            }
        } else {
            // All good fortune in non-transit milestones is vegemite
            game.recoverBothPlayers(VEGEMITE_PLAYER_HEALTH_RECOVERY_POINTS);
            std::cout << "    You found some VEGEMITE!!!! - Both player's health increased by "
                      << VEGEMITE_PLAYER_HEALTH_RECOVERY_POINTS << "%" << std::endl;
        }
        printBreakLine();
        std::cout << std::endl << std::endl;
    }
}

void UI::healthMisfortune() {
    // HEALTH RELATED MISFORTUNES (Randomly display Dehyration or motion sickness or Drop Bear or Snake)
    const std::string healhMisfortuneDescription = HEALTH_MISFORTUNE_NAMES[randomBetween(0, 3)];

    int affectedPlayerIndex = randomBetween(0, 1);
    Player player = game.getParty()[affectedPlayerIndex];

    std::cout << std::endl << std::endl;
    printBreakLine();
    std::cout << "    STREWTH! " << player.getName() << " got " << healhMisfortuneDescription << std::endl;
    std::cout << "    You have " << game.getVan().getAmountOfSupply(SUPPLY_FUEL) << " liters of fuel left" << std::endl;
    printBreakLine();

    int healthChange = 0;
    int maxValidOption = 2;

    std::cout << std::endl << "What would you like to do?" << std::endl
              << std::endl;
    std::cout << "1. Rest (lose 3 days, 30% chance of dying)" << std::endl;
    std::cout << "2. Press-On (lose 0 days, 70% chance of dying)" << std::endl;

    bool gotMedKit = game.getVan().getAmountOfSupply(SUPPLY_MEDICAL_KIT) > 0;
    if (gotMedKit) {
        std::cout << "3. Use MedKit and press-on (lose 0 days, 50% chance of dying)" << std::endl;
        maxValidOption++;
    }

    int option = askIntQuestion("Pick an option number", 1, maxValidOption) - 1;

    std::cout << std::endl << std::endl;
    std::cout << "You chose to ";
    if (option == UI_HEALTH_MENU_REST) {
        healthChange = -30;
        game.rest(false);
        game.rest(false);
        game.rest(false);
        std::cout << "rest";
    } else if (option == UI_HEALTH_MENU_PRESS_ON) {
        healthChange = -70;
        travel();
        std::cout << "press-on";
    } else if (gotMedKit && option == UI_HEALTH_MENU_MEDKIT) {
        healthChange = -50;
        travel();
        game.getVan().modifySupplyAmount(SUPPLY_MEDICAL_KIT, -1);
        std::cout << "use MedKit";
    }

    int updatedHealth = game.affectPlayerHealth(affectedPlayerIndex, healthChange);

    std::cout << std::endl
              << std::endl
              << player.getName() << "'s health is now at " << updatedHealth << "%"
              << std::endl << std::endl;
    printBreakLine();
    std::cout << std::endl << std::endl;
}

void UI::vanMisfortune() {
    // VAN RELATED MISFORTUNES
    // they all have the same chance
    int randomIndex = randomBetween(0, POSSIBLE_VAN_MISFORTUNES.size() - 1);

    VanMisfortune vanMisfortune = POSSIBLE_VAN_MISFORTUNES[randomIndex];

    game.getVan().modifySupplyAmount(vanMisfortune.supplyId, -1);

    int supplyAmountLeft = game.getVan().getAmountOfSupply(vanMisfortune.supplyId);

    std::cout << std::endl << std::endl;
    printBreakLine();
    std::cout << "    STREWTH! A van misfortune has happened" << std::endl;
    printBreakLine();
    std::cout << vanMisfortune.eventDescription << std::endl;

    Supply affectedSupply = SUPPLY_CATALOG[vanMisfortune.supplyId];
    std::cout << supplyAmountLeft << " " << affectedSupply.name << " " << affectedSupply.pluralUnitName << " left"
              << std::endl;

    printBreakLine();
    std::cout << std::endl << std::endl;

    if (vanMisfortune.minToSurvive > supplyAmountLeft) {
        gameOver(vanMisfortune.gameOverCode);
        return;
    }
}

double UI::pigProbability(unsigned int distanceTraveled) const {
    std::setprecision(10);
    double M = pow((distanceTraveled / 100) - 4, 2);
    return (((M + 72) / (M + 12)) - 1) / 10;
}

void UI::pigs() {
    int pigProb = 100 * pigProbability(game.traveledDistance());
    int r = randomBetween(1, 100);

    if (r > pigProb) {
        return;
    }

    std::cout << std::endl << std::endl;
    printBreakLine();
    std::cout << "    BUSTED! Pigs caught you speeding and they're spewing!" << std::endl;
    printBreakLine();

    std::cout << std::endl;

    std::cout << "1. Step on it!" << std::endl;
    std::cout << "2. Try to bribe them" << std::endl;
    std::cout << "3. Surrender" << std::endl;
    std::cout << std::endl;
    int pigOption = askIntQuestion("What ya gon' do?", UI_PIGS_MENU_RUN + 1, UI_PIGS_MENU_SURRENDER + 1) - 1;
    std::cout << std::endl;
    std::cout << std::endl;

    float lostCash = 0.0f;
    if (pigOption == UI_PIGS_MENU_RUN) {
        lostCash = 0;
        game.getVan().modifySupplyAmount(SUPPLY_FOOD, -5);
        int fuelLost = game.getVan().getAmountOfSupply(SUPPLY_FUEL) / 2;
        game.getVan().modifySupplyAmount(SUPPLY_FUEL, fuelLost);
        std::cout << "** You lost " << fuelLost << " liters of fuel in a wild chase and 5kgs of food" << std::endl;
    } else if (pigOption == UI_PIGS_MENU_BRIBE) {

        std::cout << "Pig: I'm thinking of a number between 1 to 10, if you guess it, you're free with a warning!"
                  << std::endl << std::endl;
        int r = randomBetween(1, 10);
        int guess = askIntQuestion("Pick a number", 1, 10);
        if (guess == r) {
            lostCash = game.getVan().balance() / 8;
            std::cout << "Nah yeh! You've got it!. Don't wanna see you speeding again, get ouf of here!" << std::endl;
            std::cout << "** The Pig takes 1/8 of your cash only (- AUD $" << lostCash << ")" << std::endl;
        } else {
            lostCash = game.getVan().balance() / 4;
            std::cout << "Yeh nah, the number was " << r << std::endl << std::endl;
            std::cout << "** You've lost 1/4 of your cash (- AUD $" << lostCash << ")" << std::endl;
        }

    } else if (pigOption == UI_PIGS_MENU_SURRENDER) {
        lostCash = game.getVan().balance() / 4;
        std::cout << "You've surrendered and lost 1/4 of your cash (- AUD $" << lostCash << ")" << std::endl;
    }
    game.getVan().spend(lostCash);
    printBreakLine();

}

void UI::showBasicMenuOptions() {
    std::cout << "1. Travel" << std::endl;
    std::cout << "2. Rest" << std::endl;
    std::cout << "3. Take Photos" << std::endl;
    std::cout << "4. Check Van" << std::endl;
}

void UI::showServoMenuOptions() {
    std::cout << "5. Go to " << game.getLastVisitedMilestone().getName() << "'s Servo" << std::endl;
}

void UI::showQuitMenuOptions() {
    std::cout << "0. Quit (q/quit)" << std::endl;
}

void UI::showMilestoneMenuOptions(bool &servoOptionShown) {
    std::cout << std::endl;
    printBreakLine();
    std::cout << "                       ////////// MENU OPTIONS \\\\\\\\\\\\\\\\\\\\" << std::endl;
    printBreakLine();
    Milestone &milestone = game.getLastVisitedMilestone();
    // Show the basic options
    // 1. TRAVEL
    // 2. REST 
    // 3. TAKE PHOTOS
    // 4. CHECK VAN
    showBasicMenuOptions();

    // Show optional options
    // [5. GO TO SERVO]
    if (milestone.isServo()) {
        showServoMenuOptions();
        servoOptionShown = true;
    }

    // Show quit option
    // 10. QUIT
    showQuitMenuOptions();
    printBreakLine();
}

void UI::gameOver(const unsigned int reason) {
    std::cout << std::endl;
    printBreakLine();
    std::cout << GAME_OVER_REASONS[reason] << std::endl << std::endl;
    std::cout << "Game Over, Ooroo Drongo!" << std::endl;
    printBreakLine();
    std::cout << std::endl << std::endl;
    printPartyStatus();
    printVanSupplies();
    std::exit(0); //https://en.cppreference.com/w/cpp/utility/program/exit
}

// taken and modified from https://stackoverflow.com/questions/48711502/how-to-convert-stdstring-to-upper-case
void UI::toLower(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(),
    // lambda function λ(char c) -> convert character to uppercase
    // Transform applies the lambda function below to all the elements of a collection
    // in this case, the collection is a string, a collection of char.
                   [](char c) { return tolower(c); });
}

void UI::toTitle(std::string &str) {
    // Puts all letters to lowercase but the first.
    // NICOLE -> Nicole;	nIcOlE -> nicole
    std::transform(str.begin() + 1, str.end(), str.begin() + 1,
                   [](char c) { return tolower(c); });
}

void UI::trim(std::string &str) {
    str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
    str.erase(str.find_last_not_of(' ') + 1);       //sufixing spaces
}

int UI::toInt(const std::string &str) {
    // stoi throws an invalid_argument exception when something other than a integer looking string
    // is passed to it. if stoi throws the execution, we catch it and we return UI_INVALID_INPUT (-1) avoiding a crash.
    try {
        return stoi(str);
    }
    catch (const std::invalid_argument &) {
        return UI_INVALID_INPUT;
    }
    catch (const std::out_of_range &) {
        return UI_INVALID_INPUT; // In case input is a big number
    }
}

int UI::readInt() {
    std::string str;
    getline(std::cin, str);
    trim(str);

    if ((str == UI_OPTION_QUIT_Q || str == UI_OPTION_QUIT_QUIT)) {
        game.quit();
        gameOver(game.state());
        return UI_QUIT_CODE;
    }

    return toInt(str);
}

int UI::askIntQuestion(std::string question, unsigned int validMin, int unsigned validMax) {
    // if there's no minimum bound no need to ask the user again, they can enter whatever minimum
    bool askForMinimumLimit = validMin != UI_NO_LIMIT;
    // if there's no maximum bound no need to ask the user again, they can enter whatever maximum
    bool askForMaximumLimit = validMax != UI_NO_LIMIT;


    std::cout << question;
    std::cout << " ('q'/'quit' to quit)";
    if (askForMinimumLimit) {
        std::cout << " (min: " << validMin << ")";
    }
    if (askForMaximumLimit) {
        std::cout << " (max: " << validMax << ")";
    }
    std::cout << " : ";


    int readValue = readInt();
    if (readValue == UI_QUIT_CODE) {
        return UI_QUIT_CODE;
    }

    // ASK AGAIN AND AGAIN IF ANSWERS ARE CONSIDERED INVALID OR OUT OF BOUNDS
    while (readValue != UI_QUIT_CODE && // if they quit, no need to check for invalid values.
           (readValue == UI_INVALID_INPUT || // user entered other than a number
            (askForMinimumLimit && (readValue < validMin)) || // we care for min, user entered < min
            (askForMaximumLimit && (readValue > validMax)))) { // we care for max, user entered > max
        std::cout << question;
        std::cout << " ('q'/'quit' to quit)";
        if (askForMinimumLimit) {
            std::cout << " (min: " << validMin << ")";
        }
        if (askForMaximumLimit) {
            std::cout << " (max: " << validMax << ")";
        }
        std::cout << " : ";
        readValue = readInt();
    }
    return readValue;
}
