#include "UI.h"

void UI::start() {
	// initialize milestones.txt
	game.readMilestonesFile("milestones.txt");

    // This screen will welcome the player, and will use the enterPlayer() method as needed
	std::cout << std::endl;
	std::cout << "	                  WELCOME TO OUTBACK TRAIL				   			       " << std::endl;
	std::cout << "    G'day mate! How ya goin'?                                                " << std::endl;
	std::cout << "    In this gander you'll travel 'round straya in a van with your best mate. " << std::endl;
	std::cout << "    Starting in Albany, Western Australia, you'll head North and explore     " << std::endl;
	std::cout << "    big loop around the country.											   " << std::endl;
	std::cout << std::endl;
	std::cout << "    Stop at servos for fuel and supplies before your trip.		           " << std::endl;
	std::cout << "    Take photos along the way to make some money and keep your health up by  " << std::endl;
	std::cout << "    resting every now and then. Watch out for nasty cops, or as how we like  " << std::endl;
	std::cout << "    to call 'em, pigs.						   			    			   " << std::endl;
	std::cout << std::endl;
	std::cout << "    Follow the instructions below and be on your way. Drive safe!			   " << std::endl;
	std::cout << std::endl;
	
	enterPlayer();

    // to check if player quit already on the first enter player screen.
    unsigned int state = game.state();
    if (state != GAME_NOT_OVER) {
        gameOver(state);
    }

	// Date
	selectStartDate();

	// Servo
	std::cout << "    You've saved $1000 AUD to spend for the trip. You will need to spend     " << std::endl;
	std::cout << "    the rest of your money on food, fuel, spare vehicle parts, photos, and   " << std::endl;
	std::cout << "    a medical kit.														   " << std::endl;
	std::cout << std::endl;
	std::cout << "    Here is a rundown of what each item does:								   " << std::endl;
	std::cout << std::endl;
	std::cout << "    Food: The more you have, the less chance there is of getting sick        " << std::endl;	   
	std::cout << "    Fuel: Keeps your van running (duh!)									   " << std::endl;
	std::cout << "    Engine/Battery/Bumper/Tire: good to keep a spare in case of a misfortune " << std::endl;
	std::cout << "    Photos: Stop to take photos and sell them for money!					   " << std::endl;
	std::cout << "    Meical Kit: Good health booster before you can it.					   " << std::endl;
	std::cout << std::endl;

	servoScreen();

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
    std::cout << "4. Go to Servo" << std::endl;
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

// taken and modified from https://stackoverflow.com/questions/48711502/how-to-convert-stdstring-to-upper-case
void UI::toLower(std::string &str) {
    std::transform(str.begin()+1, str.end(), str.begin()+1,
    // lambda function λ(char c) -> convert character to uppercase
    // Transform applies the lambda function below to all the elements of a collection
    // in this case, the collection is a string, a collection of char.
                   [](char c) { return tolower(c); });
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
	std::cout << std::endl;
	std::cout << "    Today is September 1st, 2019.											   " << std::endl;
	std::cout << "    You have until December 2nd, 2019 to finish your loop and get back in time  " << std::endl;
	std::cout << "    for your flight back home.												  " << std::endl;
	std::cout << "    The default start date is September 5th, 2019.							  " << std::endl;
	std::cout << "    You have to start in September 2019 but the day is up to you. 			  " << std::endl;
	std::cout << "    On what day you like to start your journey? (q/quit to quit; d/D for default)" << std::endl;

	std::cout << std::endl;
	while (true) {
		std::cout << "Enter a start day (ie. 5): "; // day but I need to call Calendar()
										 // and use stoi for inputs. Do I just ask for a day or offer start date choices?
		std::string dateInput;
		getline(std::cin, dateInput);
		toLower(dateInput);
		trim(dateInput);

		// I want to set d to the default start date to work with the variable. 
		// std::string d = defaultStartDate;

		if (dateInput != "") {
			if (game.partyAlive() == 0 && (dateInput == UI_OPTION_QUIT_Q || dateInput == UI_OPTION_QUIT_QUIT)) {
				game.quit();
				return;
			}
			if (stoi(dateInput) > 0 && stoi(dateInput) < 31) {
				if (stoi(dateInput) == 1) {
					std::cout << "Is 'September " << dateInput << "st , 2019' correct? (y/n): ";
				}
				else if (stoi(dateInput) == 2) {
					std::cout << "Is 'September " << dateInput << "nd , 2019' correct? (y/n): ";
				}
				else if (stoi(dateInput) == 3) {
					std::cout << "Is 'September " << dateInput << "rd , 2019' correct? (y/n): ";
				}
				else {
					std::cout << "Is 'September " << dateInput << "th , 2019' correct? (y/n): ";
				}
			//else if (dateInput == "d")
				// HOW DO I CALL THE FUNCTION????
				// std::cout << " Is 'September " << DEFAULT << "th , 2019' correct? (y/n): ";
			}
			// DOESN'T WORK FOR LARGER NUMBERS

			std::string yn;
			getline(std::cin, yn);
			toLower(yn);
			trim(yn);
			std::cout << std::endl;
			if (yn == "y" || yn == "yes" || yn == "YES") {
				// TODO : What is the date alternative of enterPlayer?
				game.enterPlayer(dateInput);
				return;
			}
		}
		// I want to set the date
		//Calendar date(2019, 09, dateInput);

		// 0 to 100 >
		//
		// and again do the if above to check if game is over
	}
}

void UI::servoSupplyList() {			
	// TODO - Include prices but they increase per servo -- how do I not make a new one every time?
	std::cout << "    You can buy items or leave the store:						   			   " << std::endl;
	std::cout << "    1. Food................................[90 kilograms per person]		   " << std::endl;
	std::cout << " 	  2. Fuel................................[40 liters per tank]			   " << std::endl;
	std::cout << "	  3. Engine..............................								   " << std::endl;
	std::cout << "	  4. Battery.............................								   " << std::endl;
	std::cout << "	  5. Bumper..............................																   " << std::endl;
	std::cout << "	  6. Tire................................																   " << std::endl;
	std::cout << "	  7. Photos..............................[36 per package]				   " << std::endl;
	std::cout << "	  8. Medical Kit.........................								   " << std::endl;
	std::cout << "	  0. Exit servo..........................								   " << std::endl;
}

void UI::servoScreen() {
	std::cout << std::endl;
	std::cout << "    Ow ya goin mate! Welcome to the Servo. What can I get for ya? 		   " << std::endl;

	while (true) {

		servoSupplyList();

		// Enter item
		std::cout << "Enter an item number ";
		if (game.partyAlive() == 0) {
			std::cout << " ('q' or 'quit' to Exit the game)";
		}
		std::cout << " : ";
		std::string itemNumber;
		getline(std::cin, itemNumber);
		toLower(itemNumber);
		trim(itemNumber);

		if (itemNumber != "") {
			if (game.partyAlive() == 0 && (itemNumber == UI_OPTION_QUIT_Q || itemNumber == UI_OPTION_QUIT_QUIT)) {
				game.quit();
				return;
			}

			// Enter quantity
			servoSupplyList();
			std::cout << "How many units do you want?: ";
			std::string itemQuantity;
			getline(std::cin, itemQuantity);
			toLower(itemQuantity);
			trim(itemQuantity);
			// HOW DO I CALL THIS FUNCTION!???
			// servo.addSupplyToCart(itemNumber, itemQuantity);

			// Total bill
			// std::cout << "Do you wish to add more to your cart? (y/n)" << std::endl;
			std::string yn;
			getline(std::cin, yn);
			toLower(yn);
			trim(yn);
			std::cout << std::endl;
			// NOT SURE WHAT TO DO BELOW vvvv
			if (yn == "y" || yn == "yes" || yn == "YES") {
				//game.enterPlayer(playerName);
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

void UI::gameOver(const unsigned int reason) {
    std::cout << "Game Over Mofo, because of reasons " << reason << std::endl;
    std::cout << "Come again!!!" << std::endl << std::endl;
}
