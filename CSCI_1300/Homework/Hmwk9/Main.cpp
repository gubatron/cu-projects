// CSCI1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: <202> � John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Hmwk9 / Final Project


#include "Common.h"
#include "Tests.h"
#include "UI.h"

int main(int numberOfArguments, char **arguments) {
	/* initialize random seed using time seconds so game outcomes are always different */
	srand(static_cast<unsigned int>(time(nullptr)));

	// If you want to run tests, pass "--tests" to the executable.
    if (numberOfArguments == 2 && strcmp(arguments[1], "--tests") == 0) {
        if (!runTests()) {
            return 1;
        }
        return 0;
    }

    // added debug mode to skip player initialization
    bool debug = false;
    if (numberOfArguments == 2 && strcmp(arguments[1], "--debug") == 0) {
        debug = true;
    }

    UI ui;
    ui.start(debug);
    return 0;
}
