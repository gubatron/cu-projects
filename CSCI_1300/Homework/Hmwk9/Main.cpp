// CSCI1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: <202> � John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Hmwk9 / Final Project


#include "Common.h"
#include "Game.h"

bool testServoPurchase();

bool calendarTests();

bool runTests();

bool testRestTurn();

int main(int numberOfArguments, char **arguments) {
    if (numberOfArguments == 2 && strcmp(arguments[1], "--test") == 0) {
        if (!runTests()) {
            return 1;
        }
        return 0;
    }
//    UserInterface ui;
//    ui.startGame();
    return 0;
}

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
    std::cout << "calendarTests() - jan1-jan1_2020 diff = " << daysDifference << " == " << daysDifference2 << std::endl;
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

bool runTests() {
    bool passedAll = true;
    passedAll = passedAll && testServoPurchase();
    passedAll = passedAll && calendarTests();
    passedAll = passedAll && testRestTurn();

    if (!passedAll) {
        std::cout << "TESTS KO!";
    } else {
        std::cout << "TESTS OK!";
    }

    return passedAll;
}



//int main() {
/* print Welcome statement: Welcome to Outback Ganders....
    insert introduction on what the game is about

loadMilestones(std::string milestonesfilePath) : bool;
[Milestone] milestones;
Van van;
[Player] player;

int totalDistance(); // calculated from milestones
int distnaceToDestination() // calculated from van and total distance
int distanceToNextMilestone();

Date defaultDate;
Date startDate;
Date calendar; // current date
Date deadline;
int daysLeft();
int daysTranscurred();

Turn.travel();
    van.move( n kms);
    <if lucky, -PhotoFortune.rolls>
    <+ moneyEarned>
Turn.rest();
    currentDate.addDays(1);
    <van.money -= currentMlestone.getCostPerPerson * players.alive>
    int players.alive();
Turn.photos();
    PhotoFortune
Turn.quit();
    EndGame

Missfortune 40% chance
Pigs formula.chance
    run
    persuade
    surrender
*/


// }
//int main()
//{
//    Game OutbackGanders
/*
- initialize
    - read files -- ifstream attraction and fort files
- enterPlayer
    - enter main player and companion names
- visitServo
    - get supplies
    - options to purchase more than one, not at all, apply min/max purhcases, buy same item many times, don't leave store without at least without fuel.
- setDate
    - give option of default date
    - if say no, give option of other starting date ranges.

loop (!Game.end())
{
    // print status
        - Current date
        - Player 1 health
        - Player 2 health
        - Food left
        - Money left
        - Fuel left
        - Km traveled
        - Km left
        - Km until next fort/attraction
        - Days left until flight leaves
    // choice to travel, rest, take photos
        - if travel -- display status, 2 days go by, 800km
        - if rest -- remove 1 kg food/person and 1 day goes by
        - if take photos -- film amount goes down, $ goes up per photo taken (bc you sold them)
                            1 day goes by, 200km
    // check misfortunes
        - random 40% chance of misfortune occurring
        - if sickness (happens to one of the two players at one time)
            - drop bear attack -- use med kit or keep going -- health is affected
            - motion sickness -- use med kit or keep going -- health is affected
            - dehydration -- use med kit or keep going -- health is affected
            - snake bite -- use med kit or keep going -- health is affected
        - kidnapping -- GAME OVER
        - ran into kangaroo
            - use spare bumper. If no number, have a second chance but if hit another roo... GAME OVER
        - ran out of fuel
            - if no spare in van... GAME OVER
        - tires pop
            - if no spare... GAME OVER
        - van engine or battery not working
            - if no spare... GAME OVER
        // Fortunate things can happen
            - found vegemite -- health up by .2!
            - "Mum Venmoed you $20!"
    // check piggies
        - probability of meeting pigs -- use formula
        - run -- lost 1/2 tank of fuel running away; -5 kg of food
        - persuade
            - if pass puzzle --  lose 1/8 cash on ticket; gain 20 film
        - surrender -- loose 1/4 cash on ticket
    // (turn ends only after these things happen)
}

// Causes for end game
    - no food left
    - health == 0.0
    - no spare parts for van (engine, bumper, battery, fuel)
    - first player dies
    - print Leader name, km traveled, food remaining, cash remaining
    - ofsteam stats to results.txt (as players die, update file with highest score at the top)
*/
// }

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
/*
IN CLASS QUESTIONS:
Keeping track of probabilities: main or class?
    - probs don't change
    - ie. misfortunes -- probability of having one is not in the class.
    - ie. hunting animals - animals have things in common -- have animal class... each with name, probability, how much food, bullets...
    - but probability of encoutering a misforutne or having a raider attack, have a funciton in the main; constant

Milestones
- reasons to create a class
    - similar characteristics
- 2 types of milestones
- Inheritance - base class that has everything a class has but

- name, km, depth (+ / -)
- forts don't have a toll

Map function?
- would be nice to show ppl what you're trying to do

Store
- Supplies
    - food
    - money
    - ...
    // get
    // setFood()
- Store (separate shopping activity from ppl)
    - how many of food, oxen, ... , you bought
    // printMenu
    // printBill
    // getTotalFood -- goes to setFood() ^^^
- Game (main)
    - Store myStore
    - Supplies mySupplies
    // initialize functions
    // visitStore
* how do we make sure these two classes communicate with eachother?
    - update setFood()
*/
