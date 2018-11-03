// Author: Nicole Leon-Molina
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Homework 2 - Problem # 4

#include <iostream>
#include <math.h>   // must include library to use pow(base,exponent) function
using namespace std;


/**
 * Algorithm: calculate total amount of energy L emitted astronomically
 *  1. Using the formula, the inputs for brigtness and distance are evaluated in the function
 *  2. The luminocity function is an integer
 * Input parameters:brigthness (double), distance (double)
 * Output: nothing
 * Returns: value of luminosity
*/

int luminosity(double b, double d)
{
   int L = 4 * b * 3.14159 * pow(d,2);
   return L;
}


int main()
{
    cout << luminosity(1.5,17.8) << endl;   // values to test
    cout << luminosity(5.1,8.71);   // values to test
    return 0;
}
