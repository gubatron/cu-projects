#include <iostream>
using namespace std;


/**
 * checkLeapYear tells user if the integer representing a year is
 *  a leap year (1) or not (0)
 *  leap years are:
 *      1. divisible by 4 until 1582
 *      2. divisible by 400 and not by 100
 * Input parameters: one number (integer)
 * Output: nothing
 * Returns: 0 or 1
*/

int checkLeapYear (int year)
{
    if (year <= 0)
    {
        return 0; 
    }
    if (year <= 1582)
    {
        if (year % 4 == 0)
        {
            return 1;
        }
        else
        {
            return 0;    
        }
    }    
    else if (year % 4 == 0)
    {
        if (year % 400 == 0)
        {
            return 1; 
        }
        else if (year % 100 == 0)
        {
            return 0; 
        }
        else
        {
            return 1;
        }
    }
    else
        return 0; 
}

int main()
{
    // test 1
    // expected output 
    // 0
    int a = checkLeapYear(1900);
    cout << a;
    
    // test 2
    // expected output 
    // 1
    //int b = checkLeapYear(1600);
    //cout << b;
    return 0;
}
