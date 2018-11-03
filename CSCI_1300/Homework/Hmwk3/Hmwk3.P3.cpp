// CS1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: 202 John Clingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Homework 3 - Problem # 3

#include <iostream>
using namespace std;

/**
* Algorithm: called daysOfMonth and takes 
*   the month as an integer value. 
*   It calculates the number of days
*   in that particular month and prints out
*   the number of days it found. 
* Parameters: month (integer) - ALWAYS POSITIVE
* Output: number of days in the month
*   Format: "'Month' <month> has x days"
*   Invalid number format: "Invalid month number"
* Returns: nothing
*/

// use switch statement!

void daysOfMonth (int month)
{
    switch (month)
    {
        case 2: cout << "Month " << month << " has 28 or 29 days" << endl;
            break;
        case 1:
        case 3: 
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: cout << "Month " << month << " has 31 days" << endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11: cout << "Month " << month << " has 30 days" << endl;
            break;
        default: cout << "Invalid month number" << endl;
    }
}

    
int main ()
{
    cout << "Please enter a number representing a month " << endl;
    //cin >> month; // use this line to test any value
    
    // test 1
    // expected output
    // Month 2 has 28 or 29 days
    daysOfMonth(2); 
    
    // test 2
    // expected output
    // Month 5 has 31 days
    daysOfMonth(5);
    
    // test 3
    // expected output
    // Month 9 has 30 days
    daysOfMonth(9);
    
    // test 4
    // expected output
    // Invalid month number
    daysOfMonth(15); 
    
    return 0;
}    