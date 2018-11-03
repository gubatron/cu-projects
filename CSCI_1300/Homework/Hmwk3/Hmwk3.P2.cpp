// CS1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: 202 John Clingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Homework 3 - Problem # 2

#include <iostream>
using namespace std;

/**
* Algorithm: called countDigits and it takes a number and 
*   tells how many digits the number has
*   1. All numbers are less than 1000 and greater than -1000
*   2. If number is negative, multiply by -1 first to make it positive
* Parameters: number (integer)
* Output: nothing
* Returns: number of digits
*/

int countDigits (int n)
{
    int dig; 
    
// single digit positive and negative
    if (n >= 0 && n <= 9)
    {
        return 1; 
    }
    else if (n >= -9 && n <= -1)
    {
       // dig = (-1)*n;
        return 1; 
    }
    
// double digit positive and negative   
    else if (n >= 10 && n <= 99)
    {
        return 2; 
    }
    else if (n >= -99 && n <= -10)
    {
       // dig = (-1)*n;
        return 2; 
    }
    
// tripple digit positive and negative
    else if (n >= 100 && n <= 999)
    {
        return 3; 
    }
    else if (n >= -999 && n <= -100)
    {
       // dig = (-1)*n;
        return 3; 
    }
    
// quadruple digit positive and negative
    else if (n == 1000)
    {
        return 4;
    }
    else if (n == -1000)
    {
       // dig = (-1)*n;
        return 4;
    }
    
// zero, less than zero, greater than 1000, and less than 1000
    else if (n > 1000 || n < -1000) 
    {
        return 0;
    }
}

int main()
{
    // test 1
    // expected output
    // 3
    cout << countDigits(-143) << endl;
    
    // test 2
    // expected output
    // 4
    cout << countDigits(1000) << endl;
    
    // test 3
    // expected output
    // 1
    cout << countDigits(0) << endl;
    
    // test 4
    // expected output
    // 0
    cout << countDigits(-1234) << endl;
    
    // test 5
    // expected output
    // 0
    cout << countDigits(-90644) << endl;
    
    // test 6
    // expected output
    // 2
    cout << countDigits(025) << endl;
    
    return 0;
}

