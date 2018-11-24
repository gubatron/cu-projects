// CSCI1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: <202> � John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Hmwk9 / Final Project


#include "Common.h"
#include "Game.h"

int main() {
    Game game;
    std::cout << game.getVan().distanceFromOrigin() << std::endl;
    std::vector<Supply> possibleSupplies = Supply::possibleSupplies();
    game.getServo().addSupplyToCart(possibleSupplies[0], 4);
    game.getServo().addSupplyToCart(possibleSupplies[3], 5);
    game.getServo().addSupplyToCart(possibleSupplies[0], 1);
    game.getServo().checkout(game.getVan(), game.getCurrentMilestoneOffset());
    std::cout << "===============" << std::endl;
    game.getVan().move(400);
    std::cout << game.getVan().distanceFromOrigin() << std::endl;

    std::cout << game.getVan().distanceFromOrigin() << std::endl;


    return 0;
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
