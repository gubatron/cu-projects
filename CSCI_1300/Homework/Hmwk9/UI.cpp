#include "UI.h"
#include <fstream>

void UI::start() {
    // initialize milestones.txt
    // This screen will welcome the player, and will use the enterPlayer() method as needed
    if (!printFile("welcome_screen.txt")) {
        std::cout
        << "error: UI::start: printFile(\"welcome_screen.txt\") failed. File \"welcome_screen.txt\" not found."
        << std::endl;
        return;
    }

    enterPlayer();

    // to check if player quit already on the first enter player screen.
    unsigned int state = game.state();
    if (state != GAME_NOT_OVER) {
        gameOver(state);
    }

    // Date
    std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
    selectStartDate();

    state = game.state();
    if (state != GAME_NOT_OVER) {
        gameOver(state);
    }

    // Servo
    // This screen tells player about the servo

    std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
    printFile("servo_summary.txt");

    servoScreen();

    // Game Loop: While the game state is not over, we keep showing the milestone screen
    // which can take input or direct to other screens.
    state = game.state();
    while (state == GAME_NOT_OVER) {
        state = milestoneScreen();
    }

    gameOver(state);
}

unsigned int UI::milestoneScreen() {
    // TODOS:
    // - Show the name of the current milestone (could be in transit, or at milestone, perhaps add a little
    // flair if it's a servo, other than the extra option

    // - Show current van stats and location
    // - Show time transcured and time left and current date, and final date

    // clear() the screen (TIP: research conio.h)
    bool servoOptionShown = false;
    bool enterPlayerMenuOptionShown = false;
    showMilestoneMenuOptions(servoOptionShown, enterPlayerMenuOptionShown);

    // Ask user for option
    std::string option = UI_INVALID_OPTION;

    while (option == UI_INVALID_OPTION) {
        option = askForValidMilestoneScreenOption(servoOptionShown, enterPlayerMenuOptionShown);

        if (option == UI_INVALID_OPTION) {
            showMilestoneMenuOptions(servoOptionShown, enterPlayerMenuOptionShown);
        }
    }

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
    } else if (option == UI_MILESTONE_OPTION_GO_TO_SERVO) {
        servoScreen();
    } else if (option == UI_MILESTONE_OPTION_ENTER_PLAYER) {
        enterPlayer();
    } else if (option == UI_OPTION_QUIT_Q || option == UI_OPTION_QUIT_QUIT) {
        game.quit();
    }
    return game.state();
}

std::string UI::askForValidMilestoneScreenOption(bool servoOptionShown, bool enterPlayerMenuOptionShown) {
    std::cout << std::endl;
    std::cout << "Enter a valid option number: ";
    std::string userOption;
    getline(std::cin, userOption);
    toLower(userOption);
    trim(userOption);

    // BASIC VALID OPTIONS FOR ALL MILESTONES:
    // 1. TRAVEL
    // 2. REST
    // 3. TAKE PHOTOS
    // 10. 'q', 'quit'
    std::vector<std::string> validOptions = {
    UI_MILESTONE_OPTION_TRAVEL,
    UI_MILESTONE_OPTION_REST,
    UI_MILESTONE_OPTION_TAKE_PHOTOS,
    UI_OPTION_QUIT_Q,
    UI_OPTION_QUIT_QUIT
    };

    // EXTRA VALID OPTION FOR MILESTONES WITH SERVOS
    if (servoOptionShown) {
        validOptions.push_back(UI_MILESTONE_OPTION_GO_TO_SERVO);
    }

    // EXTRA VALID OPTION TO ENTER PLAYER FOR FIRST MILESTONE WHILE NOT MAX PLAYER NUMBER HIT
    if (enterPlayerMenuOptionShown) {
        validOptions.push_back(UI_MILESTONE_OPTION_ENTER_PLAYER);
    }

    // now check that the user enter a valid option
    // https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value

    bool isValidOption = (validOptions.end() != std::find(validOptions.begin(), validOptions.end(), userOption));

    if (!isValidOption) {
        std::cout << std::endl << "Invalid Input [" << userOption << "] please enter a valid option";
        return UI_INVALID_OPTION;
    }
    return userOption;
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
    Calendar defaultStartDate = game.getDefaultStartDate();
    std::cout << "    The default start date is " << defaultStartDate.to_string() << std::endl << std::endl;

    std::cout << std::endl;
    int dateInput = askIntQuestion("Enter a day of September to start gandering", 1, 30);

    if (dateInput == UI_QUIT_CODE) {
        game.quit();
        return;
    }

    // Current date is set to Sept 1st.
    // User will enter a dateInput representing the day of the month to start.
    int daysToAdd = dateInput - 1;
    game.addToStartDate(daysToAdd);

    std::cout << std::endl << "    Your start date is " << game.getStartDate().to_string() << std::endl;
}

void UI::printServoMenu() {

    std::cout << "    You can buy items or leave the store: " << std::endl;

    std::cout << "    1. Food............[90 kg per person].....$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_FOOD], game.getLastVisitedMilestoneOffset()) << std::endl;
    std::cout << "    2. Fuel............[40 L per tank]........$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_FUEL], game.getLastVisitedMilestoneOffset()) << std::endl;
    std::cout << "    3. Engine.................................$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_ENGINE], game.getLastVisitedMilestoneOffset()) << std::endl;
    std::cout << "    4. Battery................................$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_BATTERY], game.getLastVisitedMilestoneOffset()) << std::endl;
    std::cout << "    5. Bumper.................................$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_BUMPER], game.getLastVisitedMilestoneOffset()) << std::endl;
    std::cout << "    6. Tire...................................$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_TIRE], game.getLastVisitedMilestoneOffset()) << std::endl;
    std::cout << "    7. Photos..........[36 per package].......$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_PHOTOS], game.getLastVisitedMilestoneOffset()) << std::endl;
    std::cout << "    8. Medical Kit............................$" << game.getServo().getSupplyCost(SUPPLY_CATALOG[SUPPLY_MEDICAL_KIT], game.getLastVisitedMilestoneOffset()) << std::endl;

    std::cout << "    0. Exit servo" << << std::endl;

}

void UI::servoScreen() {
    std::cout << std::endl;
    std::cout << "    Ow ya goin' mate! Welcome to the Servo. What can I get for ya?  " << std::endl;

    // call servo supply list and maybe put prices at the end of each line as it reads the file
    while (true) {



        // Enter item
        std::cout << "Enter an item number ";
        if (game.partyAlive() == 0) {
            std::cout << " ('q' or 'quit' to Exit the game)";
        }
        std::cout << " : ";
        std::string itemNumber;
        getline(std::cin, itemNumber);
        trim(itemNumber);

        if (itemNumber != "") {
            if (game.partyAlive() == 0 && (itemNumber == UI_OPTION_QUIT_Q || itemNumber == UI_OPTION_QUIT_QUIT)) {
                game.quit();
                return;
            }


            // Supply purchase = SUPPLY_CATALOG[toInt(itemNumber)];
            // Enter quantity
            std::cout << "How many units do you want?: ";
            std::string itemQuantity;
            getline(std::cin, itemQuantity);
            trim(itemQuantity);

            game.getServo().addSupplyToCart(SUPPLY_CATALOG[toInt(itemNumber) - 1], toInt(itemQuantity));

            // int UI::enterValidNumber(int *valid_numbers_array, size_of_that_array);
            // int supplyId = toInt(itemNumber) - 1;
            // int quantity = toInt(itemQuantity);
            // game.getServo().addSupplyToCart(SUPPLY_CATALOG[supplyId], quantity);

            // Total bill
            // std::cout << "Do you wish to add more to your cart? (y/n)" << std::endl;
            std::string yn;
            getline(std::cin, yn);
            toLower(yn);
            trim(yn);
            std::cout << std::endl;
            // NOT SURE WHAT TO DO BELOW vvvv
            if (yn == "y" || yn == "yes" || yn == "YES") {
                //game.enterPlayer(playerName); **********************************************
                return;
            }
            // y - LOOP

        }
    }
}

void UI::travel() {
    game.travel();
    std::cout
    << "TODO: We actually traveled here (half ass implemented), you can print what changed (distance, food, fuel)"
    << std::endl;
}

void UI::rest() {
    game.rest();
    std::cout
    << "TODO: We actually rested here (half ass implemented), you can print what changed (distance, food, fuel)"
    << std::endl;
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
}

void UI::showServoMenuOptions() {
    std::cout << "4. Go to Servo" << std::endl;
}

void UI::showEnterPlayerMenuOptions() {
    std::cout << "5. Enter another player" << std::endl;
}

void UI::showQuitMenuOptions() {
    std::cout << "10. Quit (q/quit)" << std::endl;
}

void UI::showMilestoneMenuOptions(bool &servoOptionShown, bool &enterPlayerMenuOptionShown) {
    Milestone &milestone = game.getLastVisitedMilestone();
    // Show the basic options
    // 1. TRAVEL
    // 2. REST 
    // 3. TAKE PHOTOS 
    showBasicMenuOptions();

    // Show optional options
    // [4. GO TO SERVO]
    if (milestone.isServo()) {
        showServoMenuOptions();
        servoOptionShown = true;
    }

    // [5. ENTER ANOTHER PLAYER]
    if (game.getLastVisitedMilestoneOffset() == 0 &&
        game.partyAlive() < MAX_NUMBER_OF_PLAYERS) {
        showEnterPlayerMenuOptions();
    }

    // Show quit option
    // 10. QUIT
    showQuitMenuOptions();
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

void UI::clearScreen() const {
    // the simple way http://www.cplusplus.com/articles/4z18T05o/
    std::cout << std::string(100, '\n');
}
