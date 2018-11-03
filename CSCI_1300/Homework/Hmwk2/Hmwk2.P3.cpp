// Author: Nicole Leon-Molina
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Homework 2 - Problem # 3

#include <iostream>
using namespace std;


/**
 * Algorithm: U.S. population in exactly one year (365 days)
 *  For a given initial population and a time of 365 days these are the rates to follow:
 *      1. Birth rate is 8 seconds
 *      2. Death rate is 12 seconds
 *      3. Immigration rate is 27 seconds
 *  Values 1, 2, and 3 above will be assigned to varialbes.
 *  The function returns the value a year later.
 * Input parameters: initial population (int)
 * Output: nothing
 * Returns: population value in a year
*/

int population (int currentPop)
{
    int T = 365; // time input in days
    int birth_rate = (86400*T)/8;    // use 86400 for seconds in a day
    int death_rate = (86400*T)/12;
    int immig_rate = (86400*T)/27;
    int us_pop = birth_rate - death_rate + immig_rate + currentPop;
}

int main()
{
    cout << population(1000000) << endl;
    cout << population(328411687);
}


// code passes all tests but doesn't work on cloud 9 