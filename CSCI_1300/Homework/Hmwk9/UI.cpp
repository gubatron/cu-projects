#include "UI.h"
#include <fstream>

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
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_FOOD], 100);
        game.getServo().addSupplyToCart(SUPPLY_CATALOG[SUPPLY_FUEL], 100);
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
    bool servoOptionShown = false;
    showMilestoneMenuOptions(servoOptionShown);

    // Ask user for option
    int option = askForValidMilestoneScreenOption(servoOptionShown);

    // handle option action (switch)
    if (option == UI_MILESTONE_OPTION_TRAVEL) {
        travel();
        //missfortunes();
        //pigs();
    } else if (option == UI_MILESTONE_OPTION_REST) {
        rest();
        //missfortunes();
        //pigs();
    } else if (option == UI_MILESTONE_OPTION_TAKE_PHOTOS) {
        takePhotos();
        //missfortunes();
        //pigs();
    } else if (option == UI_MILESTONE_OPTION_CHECK_VAN) {
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

    if (userOption == UI_MILESTONE_OPTION_QUIT || userOption == UI_QUIT_CODE) {
        game.quit();
        exit(0);
    }

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

    if (dateInput == UI_QUIT_CODE) {
        game.quit();
        return;
    }

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
    std::cout << "    0. Exit servo" << std::endl << std::endl;

    float total = game.getServo().getTotal(game.getLastVisitedMilestoneOffset());
    if (total > 0) {
        printShoppingCart();
        std::cout << std::endl << "Your current total is AUD $" << total << std::endl;
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

    std::cout << "                Health: " << player1.getName() << " " << player1.getHealth() << " %" << std::endl;
    std::cout << "                        " << player2.getName() << " " << player2.getHealth() << " %" << std::endl;

    std::cout << "                  Food: " << game.getVan().getAmountOfSupply(SUPPLY_FOOD) << " kgs" << std::endl;
    std::cout << "                  Fuel: " << game.getVan().getAmountOfSupply(SUPPLY_FUEL) << " liters" << std::endl;
    std::cout << "               Balance: AUD $" << game.getVan().balance() << std::endl << std::endl;
    std::cout << "        Next Milestone: " << game.distanceToNextMilestone() << " km" << std::endl;
    std::cout << "     Distance Traveled: " << game.traveledDistance() << " km" << std::endl;
    std::cout << "    Distance Remaining: " << game.remainingDistance() << " km" << std::endl;
    std::cout << std::endl << std::endl;
}

void UI::printShoppingCart() {
    std::cout << std::endl;
    auto cart = game.getServo().getShoppingCart();
    std::cout << "Product" << "\t\t" << "Price" << "\t" << "Amount" << "\t" << "Sub-total" << std::endl;
    std::cout << std::endl;
    for (std::pair<Supply, int> keyValue : cart) {
        Supply supply = keyValue.first;
        int amount = keyValue.second;
        float supplyTotal = supply.costPerUnit * amount;
        if (amount > 0) {
            std::cout << supply.name << "\t\t$" << supply.costPerUnit << "\t" << amount << "\t" << supplyTotal
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
        if (itemNumber == UI_QUIT_CODE) {
            game.quit();
            return;
        }

        // Leave servo
        if (itemNumber == UI_SERVO_MENU_EXIT) {
            // if there are products in the cart, check out
            float total = game.getServo().getTotal(game.getLastVisitedMilestoneOffset());
            if (total > 0) {
                // does the user have enough money?
                float vanBalance = game.getVan().balance();
                if (vanBalance < total) {
                    std::cout << std::endl
                              << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                              << std::endl;
                    std::cout << "Clerk:    HOLD IT MATE!!! AUD $" << vanBalance
                              << " is all you got, the total is AUD $" << total
                              << std::endl;
                    std::cout << std::endl
                              << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
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

            std::cout << "You've added " << itemQuantity << " " << unitString << " of " << supply.name << " for AUD $"
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
    //    Attempt to shoot a subject, pick one below:
    //
    //    1. Beach
    //    2. Animal
    //    3. Town
    //    4. City
    //    5. Landmark
    //
    //    > 2
    //    You chose Animal, you have a 25% of taking good photos
    //    Calculating odds...
    //    (Possible outputs)
    //    a) Sorry, no animals were found, you took 8 bad pictures, you earned AUD $0
    //    b) Success, you took 8 pictures of Animal -> you earned AUD $80
    std::cout
    << "TODO: Print menu options to pick what picture subject user will attempt to capture (animal? beach?, etc.) "
    << std::endl;
    //getline(cin, optionNumberString)
    //int optionNumber = -1;
    // try {
    //optionNumber = stoi(optionNumberString)
    // } catch (when the user did not enter a number it will throw an exception, remember that from the
    // other homework
    //
    //Photo chosenSubject = POSSIBLE_PHOTOS[optionNumber];
    //bool tookPhotos = game.takePhotos(Photo)
    // if (tookPhotos) {
    // Success, you took 8 pictures of Animal -> you earned AUD $80
    // } else {
    // Sorry, no animals were found, you took 8 bad pictures, you earned AUD $0
    //
    // Here we just present the outcome to the user, no need to tell the game to do anything
    // else except what we did -> game.takePhotos(Photos)
}

void UI::showBasicMenuOptions() {
    std::cout << "1. Travel" << std::endl;
    std::cout << "2. Rest" << std::endl;
    std::cout << "3. Take Photos" << std::endl;
    std::cout << "4. Check Van" << std::endl;
}

void UI::showServoMenuOptions() {
    std::cout << "5. Go to Servo" << std::endl;
}

void UI::showQuitMenuOptions() {
    std::cout << "0. Quit (q/quit)" << std::endl;
}

void UI::showMilestoneMenuOptions(bool &servoOptionShown) {
    std::cout << std::endl;
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
    std::cout << "Game Over Mofo, because of reasons " << reason << std::endl;
    std::cout << "Come again!!!" << std::endl << std::endl;
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
