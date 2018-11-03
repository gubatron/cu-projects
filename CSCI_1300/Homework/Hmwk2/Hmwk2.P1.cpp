// Author: Nicole Leon-Molina
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Homework 2 - Problem # 1

#include <iostream>
using namespace std;

/**
 * Algorithm: convert seconds to hours
 *  1. Take input of seconds from the user and use as integer
 *  2. Print a string in format: x hour(s) y minute(s) z second(s)
 *          for the z input of seconds
 * Input parameters: seconds (int)
 * Output: print hours (int)
 * Returns: nothing
*/

void convertSeconds(int seconds)
{
    int x = seconds/3600;// divide input by 3600 to get hours
    seconds = seconds%3600; // to get the remainder
    int y = seconds/60; // divide new seconds value by 60 to get minutes
    seconds = seconds%60; // to get remainder
    int z = seconds; // no division needed since we have the remainder value of seconds from line above
    cout << x << " hour(s) " << y << " minute(s) " << z << " second(s)" << endl;
    
}


int main()
{
    cout << "Enter seconds: " << endl;
   // int seconds;
   // cin >> seconds;
   // convertSeconds(seconds);
    convertSeconds(3671); 
    convertSeconds(360);
/**
 * To test for any input of seconds, remove comment from lines 34, 35, and 36
 *      and comment lines 37 and 38. Run code and it will ask user to enter seoconds.
*/

}
