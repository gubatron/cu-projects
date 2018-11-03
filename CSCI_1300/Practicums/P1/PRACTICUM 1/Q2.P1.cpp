#include <iostream>
//#include <string>
#include <cmath>
#include <math.h>
using namespace std;


/**
 * functionname function ...
 * 
 * Input parameters: 
 * Output: 
 * Returns: cupsize name  // if nothing - void function
*/


string coffeeCupSize (int oz)
{
    if (oz >= 0 && oz <= 12)
    {
        return "SMALL";
    }
    else if (oz >= 13 && oz <= 24)
    {
        return "MEDIUM";
    }
    else if (oz >= 25 && oz <= 36)
    {
        return "LARGE";
    }
    else if (oz >= 36)
    {
        return "HUGE";
    }
    else
    {
        return "INVALID";
    }
}

int main()
{
    coffeeCupSize(2);
    
    return 0;
}