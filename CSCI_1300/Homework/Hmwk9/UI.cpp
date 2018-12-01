#include "UI.h"
#include <fstream>

void UI::start() {
	// initialize milestones.txt
    // This screen will welcome the player, and will use the enterPlayer() method as needed
	if (!printFile("welcome_screen.txt")) {
		std::cout << "error: UI::start: printFile(\"welcome_screen.txt\") failed. File \"welcome_screen.txt\" not found." << std::endl;
		return;
	}

	enterPlayer();

    // to check if player quit already on the first enter player screen.
    unsigned int state = game.state();
    if (state != GAME_NOT_OVER) {
        gameOver(state);
    }

	// Date
	selectStartDate();

	// Servo
	// This screen tells player about the servo
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
		return  false;
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

// TODO - BUG!! -- If dateInput is outside of range, program freezes...
void UI::selectStartDate() {
	// This screen tells user current date and instucts to choose a start date. 
	printFile("start_date_intro.txt");
	std::cout << "		On what day would you like to start your journey? (q / quit to quit; d / D for default) ";
	std::cout << std::endl;
	while (true) {
		std::cout << "Enter a start day (ie. 5): "; // day but I need to call Calendar()
										 // and use stoi for inputs. Do I just ask for a day or offer start date choices?
		std::string dateInput;
		getline(std::cin, dateInput);
		trim(dateInput);

		// They will start (dateInput - 1) days after
		// game.addToStartDate;

		// std::string d = defaultStartDate;
			// ask  for how many days after they want to start, 
			// and then add those days to the game.startDate.Right now.startDate is private in Game, 
			// so you will probably have to create a new method in Game called addToStartDate(int n)
			// similar to addDays.

		if (dateInput != "") {
			if (game.partyAlive() == 0 && (dateInput == UI_OPTION_QUIT_Q || dateInput == UI_OPTION_QUIT_QUIT)) {
				game.quit();
				return;
			}

			getline(std::cin, dateInput);
			int days = toInt(dateInput);
			while (days < 0 || days > 30) {
				std::cout << "Please enter a valid number between 0-30 inclusive" << std::endl;
				getline(std::cin, dateInput);
				days = toInt(dateInput);
			}

			if (days == 1) {
				std::cout << "Is 'September " << dateInput << "st , 2019' correct? (y/n): ";
			}
			else if (days == 2) {
				std::cout << "Is 'September " << dateInput << "nd , 2019' correct? (y/n): ";
			}
			else if (days == 3) {
				std::cout << "Is 'September " << dateInput << "rd , 2019' correct? (y/n): ";
			}
			else {
				std::cout << "Is 'September " << dateInput << "th , 2019' correct? (y/n): ";
			}

			//else if (dateInput == "d")
				// HOW DO I CALL THE FUNCTION????
				// std::cout << " Is 'September " << DEFAULT << "th , 2019' correct? (y/n): ";
		}

			std::string yn;
			getline(std::cin, yn);
			toLower(yn);
			trim(yn);
			std::cout << std::endl;
			if (yn == "y" || yn == "yes" || yn == "YES") {
				// TODO : What is the date alternative of enterPlayer?
				// game.enterPlayer(dateInput); ******************************************
				return;
			}
	}
		// I want to set the date
		//Calendar date(2019, 09, dateInput);

		// 0 to 100 >
		//
		// and again do the if above to check if game is over
}

void UI::servoScreen() {
	std::cout << std::endl;
	std::cout << "    Ow ya goin mate! Welcome to the Servo. What can I get for ya? 		   " << std::endl;

	// call servo supply list and maybe put prices at the end of each line as it reads the file
	while (true) {

		printFile("servo_supply_list.txt");

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
}

// taken and modified from https://stackoverflow.com/questions/48711502/how-to-convert-stdstring-to-upper-case
void UI::toLower(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(),
    // lambda function λ(char c) -> convert character to uppercase
    // Transform applies the lambda function below to all the elements of a collection
    // in this case, the collection is a string, a collection of char.
                   [](char c) { return tolower(c); });
}

void UI::toTitle(std::string & str) {
	// Puts all letters to lowercase but the first. 
	// NICOLE -> Nicole;	nIcOlE -> nicole
	std::transform(str.begin() + 1, str.end(), str.begin() + 1,
		[](char c) { return tolower(c); });
}

void UI::trim(std::string &str) {
    str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
    str.erase(str.find_last_not_of(' ') + 1);         //surfixing spaces
}

int UI::toInt(const std::string &str) {
	try {
		return stoi(str);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}
