#include "UI.h"


void UI::start() {
    // This screen will welcome the player, and will use the enterPlayer() method as needed
    enterPlayer();

    // to check if player quit already on the first enter player screen.
    unsigned int state = game.state();
    if (state != GAME_NOT_OVER) {
        gameOver(state);
    }

    // TODO: selectStartDate() screen here
    // Something like:
    //
    // Today is 2019-01-01, you have until blah date.
    // How many days from now you want to start your journey? (q/quit to quit)
    // 0 to 100 >
    //
    // and again do the if above to check if game is over

    // Game Loop: While the game state is not over, we keep showing the milestone screen
    // which can take input or direct to other screens.
    state = game.state();
    while (state == GAME_NOT_OVER) {
        state = milestoneScreen();
    }

    gameOver(state);
}

void UI::showBasicMenuOptions() {
    std::cout << "1. Travel" << std::endl;
    std::cout << "2. Rest" << std::endl;
    std::cout << "3. Take Photos" << std::endl;
}


void UI::showServoMenuOptions() {
    std::cout << "5. Go to Servo" << std::endl;
}

void UI::showEnterPlayerMenuOptions() {
    std::cout << "5. Enter another player" << std::endl;
}

void UI::showQuitMenuOptions() {
        std::cout << "10. Quit (q/quit)" << std::endl;
}

int UI::milestoneScreen() {
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

std::string UI::askForValidMilestoneScreenOption(bool servoOptionShown, bool enterPlayerMenuOptionShown) {
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

// taken and modified from https://stackoverflow.com/questions/48711502/how-to-convert-stdstring-to-upper-case
void UI::toLower(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(),
    // lambda function λ(char c) -> convert character to uppercase
    // Transform applies the lambda function below to all the elements of a collection
    // in this case, the collection is a string, a collection of char.
                   [](char c) { return std::tolower(c); });
}

void UI::trim(std::string &str) {
    str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
    str.erase(str.find_last_not_of(' ') + 1);         //surfixing spaces
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
        toLower(playerName);
        trim(playerName);

        if (game.partyAlive() == 0 &&
            (playerName == UI_OPTION_QUIT_Q || playerName == UI_OPTION_QUIT_QUIT)) {
            game.quit();
            return;
        }

        std::cout << "Is '" << playerName << "' correct? (y/n) ";
        std::string yn;
        getline(std::cin, yn);
        toLower(yn);
        trim(yn);
        std::cout << std::endl;
        if (yn == "y") {
            game.enterPlayer(playerName);
            return;
        }
    }
}

void UI::servoScreen() {
    std::cout << "Servo Screen Menu and option reading goes here" << std::endl;
}

void UI::travel() {
    game.travel();
    std::cout
    << "TODO: We actually travelled here (half ass implemented), you can print what changed (distance, food, fuel)"
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
    std::cout << "TODO: Print menu options to pick what picture subject user will attempt to capture (animal? beach?, etc.) " << std::endl;
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

void UI::gameOver(const unsigned int reason) {
    std::cout << "Game Over Mofo, because of reason " << reason << std::endl;
    std::cout << "Come again!!!" << std::endl << std::endl;
}
