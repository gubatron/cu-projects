// CS1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: 202 John Clingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Homework 3 - Problem # 1

#include <iostream>
using namespace std;

/**
* Algorithm: called collatzStep and takes one number
*   and returns a number. 
*   1. If the number is even, 
*   the next value is that number divided by two
*   2. If the number is odd, 
*   the next value is (3 * number) + 1
*   3. If the result is not positive, 
*   it will return 0
* Parameters: number (integer)
* Output: nothing
* Returns: number evaluated after collatz conjecture
*   is applied (integer)
*/

int collatzStep (int n)
{
    int new_n;
    
    if (n <= 0) // is n less than or equal to zero?
    {
        return 0;
    }
    if (n % 2 == 0) // is n even?
    {
        new_n = n/2;
        return new_n;
    }
    if (n % 2 == 1) // is n odd?
    {
        new_n = (3*n)+1;
        return new_n;
    }
}

int main()
{
    // test 1
    // expected output
    // 2
    cout << collatzStep(4) << endl;
    
    // test 2
    // expected output
    // 22
    cout << collatzStep(7) << endl;
    
    // test 3
    // expected output
    // 0
    cout << collatzStep(-5) << endl;
    
    // test 4
    // expected output
    // 0
    cout << collatzStep(0);
    
    return 0;
}