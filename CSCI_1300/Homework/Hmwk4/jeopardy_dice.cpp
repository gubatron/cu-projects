// Author: Nicole Leon-Molina
// Recitation: 202 John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Hmwk 4 - Project1


// PSEUDOCODE
/*

print "Welcome to Jeopardy Dice!"
///////////
Have an overlooking while loop with if else statements within it
While the turnTotal is < 100 -- show code for both human and computer
after while loop, it the turnTotal is >= 100 -- show whichever player has >= 100 playerTotal points
///////////
- make 2 integer variables called humanTotal and computerTotal

While the playerTotal for human or playerTotal for computer is < 100

    <code for human>
    If human playing:
    * define a turnTotal variable only under human only and do so also for computer only
    print "It is now human's turn"
    print "Do you want to roll a dice (Y/N)?"
        - this alludes to the rollDice function
    nested if statement:
        if yes,
            - y or Y is a starter for rollDice function
            - rollDice gives number between 1 and 6
            - the turnTotal from the diceRoll becomes humanTotal
            - print "Your turn total is x" 
            - print "Do you want to roll again (Y/N)?"
                - if yes, run if yes above again
                - if no, go to else
        else,
            - display current score "computer: x"; "human: y" by calling function scoreBoard
            - print "It is now computer's turn"
    
    <code for computer>
    If computer playing
    * define a turnTotal variable only under human only and do so also for computer only
    print "It is now computer's turn"
    make a function for computer code of randomly rolling a dice
        - the function will add up every value and accumulate it to their turnTotal
        - computer will continue rolling until their turnTotal = 10 or higher
        - turn ends and user goes again
    depending on the results of the function
        - print "Computer rolled a y"
        - print "Computer turn total is y" 
        - depending on that computerTotal score, the computer's turn continues or ends
        - when computer turn ends, display current score "computer: x"; "human: y" 
            by calling function scoreBoard
    SO Function for computer()
    while the turnTotal is less than 10
    call roll dice and print "Computer rolled a <value>"
    call dieCondition with r from random function and 
    print "Computer turn total is <sum of totals>"
        
    It is human's turn again. Code loops back to human
    This code is for as long as the turnTotal for both players is < 100.
    - when it gets >= 100, evaluate the if statement after

When loop ends:
If the playerTotal for human >= 100 or the playerTotal for computer >= 100
    - print "Congratulations! [human or computer] won this round of jeopardy dice!" 
    - insert the correct value depending on which player has the higher total. 
    
<score function>
    function called to display the updated score
    Should take two inputs.
    One from the computerTotal and one from humanTotal

//////////////////////
dieCondition function
- must take in r from dieRoll
    if they roll a 1 or 6
        turn ends
        turnTotal becomes 0
    if they roll a 3
        turnTotal = 0
        turn ends
        turnTotal becomes 15
    if they roll a 2, 4, 5
        accumulate value on dice to turnTotal
    returns turnTotal
    
//////////////////////

    
*/

/**
 * //QUESTIONS
 * 
 * 1. When printing scores, human yields huge number
 * and computer yields the sum. 
 * If I initialize it with zero it resets the opponent to zero but still adds. 
 * It remembers the score of the player after the player goes but it recalls
 * the opponent's score as zero. Even though it adds it up. 
 *
 * 2. Computer needs to stop playing when turnTotal is 0 or 15
 * 
 * 3. when either turn total >= 100 exit the while loop
 * 
 * 
 * TESTS 
 * human not rolling
 * human says yes only
 * human saying no and then yes yes yes no
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

/**
* rollDice
* returns a random integer between 1 and 6, works as rolling a dice.
* return value, int number (1-6)
*/
int rollDice() 
{
   	int r; 
   	r = random() % 6 + 1;
   	return r;
}


//////////////////////////////////////////////////////////////////////////

// 3 FUNCTIONS

// FUNCTION #1
/**
 * function named score
 *      takes inputs of computerTotal and humanTotal 
 *      and displays added values calculated in turnTotal 
 *      in the human() and computer() functions. 
 * Called in both human() and computer()
*/
void score(int computerTotal, int humanTotal)
{
    cout << "computer: " << computerTotal << endl;
    cout << "human: " << humanTotal << endl;
    //cout << endl;
}

// FUNCTION # 2 
/** 
 * function named human
 *      Asks user if they want to roll a dice
 *      calls rollDice function and scoreBoard function
 *      called from game()
 * Input: nothing
 * Ouput: questions and prompts for human player
 * Return: nothing
*/
int human(int computerTotal, int humanTotal) 
{
    cout << "Do you want to roll a dice (Y/N)?:" << endl;

    int turnTotal = 0;
    char starter;
    cin >> starter;
    
    while (starter == 'y' || starter == 'Y') 
    {
        int r = rollDice();
        if (r == 1 || r == 6) // TURN ENDS
        {
            cout << "You rolled a " << r << endl;
            turnTotal = 0;
            cout << "Your turn total is " << turnTotal << endl;
            humanTotal = humanTotal + turnTotal;
            score(computerTotal, humanTotal);
            return humanTotal;
        }
        else if (r == 3) // TURN ENDS
        {
            cout << "You rolled a " << r << endl;
            turnTotal = 15;
            cout << "Your turn total is " << turnTotal << endl;
            humanTotal = humanTotal + turnTotal;
            score(computerTotal, humanTotal);
            return humanTotal;
        }
        else if (r == 2 || r == 4 || r == 5)
        {
            cout << "You rolled a " << r << endl;
            turnTotal = turnTotal + r;
            cout << "Your turn total is " << turnTotal << endl;
            cout << "Do you want to roll again (Y/N)?:" << endl;
            cin >> starter; 
        }
    }
    if (starter == 'n' || starter == 'N')
    {
        humanTotal = humanTotal + turnTotal;
        score(computerTotal, humanTotal);
        return humanTotal;
    }
}   

// FUNCTION # 3
/**
 * Function called computer runs diceRoll function for computer
 *      calls rollDice function and scoreBoard function
 *      called from game()
 * Input: nothing
 * Ouput: statements saying what the computer rolled
 *          and what its turnTotal equals until it is >= 10
 * Return: nothing
*/
int computer(int computerTotal, int humanTotal)
{   
    int turnTotal = 0;
    
    while (turnTotal <= 10) 
    {
        int r = rollDice();
        if (r == 1 || r == 6) // TURN ENDS
        {
            cout << "Computer rolled a " << r << endl;
            turnTotal = 0;
            cout << "Computer turn total is " << turnTotal << endl;
            score(computerTotal, humanTotal);
            computerTotal = computerTotal + turnTotal;
            return computerTotal;
        }
        else if (r == 3) // TURN ENDS
        {
            cout << "Computer rolled a " << r << endl;
            turnTotal = 15;
            cout << "Computer turn total is " << turnTotal << endl;
            computerTotal = computerTotal + turnTotal;
            score(computerTotal, humanTotal);
            return computerTotal;
        }
        else if (r == 2 || r == 4 || r == 5)
        {
            cout << "Computer rolled a " << r << endl;
            turnTotal = turnTotal + r;
            cout << "Computer turn total is " << turnTotal << endl;
        }
    }
    if (turnTotal > 10)
    {
        computerTotal = computerTotal + turnTotal;
        score(computerTotal, humanTotal);
        return computerTotal;
    }
}

//////////////////////////////////////////////////////////////////////////

/**
* game ()
* driver function to play the game
* the function does not return any value
*/
void game()
{
    // My game solution
    cout << "Welcome to Jeopardy Dice!" << endl;
    //cout << endl;
    
    int humanTotal = 0;
    int computerTotal = 0;
    
    while (humanTotal < 100 && computerTotal < 100)
    {
        // call human function and run code until human turn ends
        cout << endl;
        cout << "It is now human's turn" << endl;
        cout << endl;
        humanTotal = human(computerTotal, humanTotal);
            if (humanTotal >= 100)
            {
                break;
            }
        // call computer function and run code until computer turn ends
        cout << endl;
        cout << "It is now computer's turn" << endl;
        cout << endl;
        computerTotal = computer(computerTotal, humanTotal);
            if (computerTotal >= 100)
            {
                break;
            }
        
        // loop until conditions above are not true
    }
    // game ends immediately and other player does not get another turn
    if (humanTotal >= 100)
    {
        cout << endl;
        cout << "Congratulations! human won this round of jeopardy dice!" << endl;
    }
    if (computerTotal >= 100)
    {
        cout << endl;
        cout << "Congratulations! computer won this round of jeopardy dice!" << endl;
    }
}


// DO NOT TOUCH CODE BELOW!
int main()
{
    // start the game!
    game();
    return 0;
}