// Author: Nicole Leon-Molina
// Recitation: 202 – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// Homework 2 - Problem # 2

#include <iostream>
#include <iomanip> // std::setprecision
using namespace std;


/**
 * Algorithm: convert Celsius to Fahrenheit
 *  1. Takes celsius temperature input
 *  2. Uses formula to convert Celsius to Fahrenheit
 *  3. Pritns temperature in Fahrenheit with two digit precision
 *  4. Format: "The temperature of (celsius) in fahrenheit is (fahrenheit)"
 * Input parameters: temperature in Celsius (int)
 * Output: print resulting temperature Fahrenheit value 
 * Returns: nothing
*/

void celsiusToFahrenheit(int tempInCelsius)
{
    double tempInFahrenheit = tempInCelsius * (9.0/5.0) + 32; // 9.0 and 5.0 have decimals to get answer in decimals and not integers
    cout << "The temperature of " << tempInCelsius;
    cout << " in fahrenheit is " ;
    cout << fixed << setprecision(2) << tempInFahrenheit << endl; // sets decimal precision to two points
}

int main()
{
    cout << "Enter temperature in Celsius: " << endl;
    //int celsius;
    //cin >> celsius;
    //celsiusToFahrenheit(celsius);
    celsiusToFahrenheit(38);
    celsiusToFahrenheit(-22);
    
/**
 * To test for any input of temperature in celsius, 
 *      remove comment from lines 34, 35, and 36 and comment lines 37 and 38.
 *      Run code and it will ask user to enter a temperature in celsius.
*/
}
