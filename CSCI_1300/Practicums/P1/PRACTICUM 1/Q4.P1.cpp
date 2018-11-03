#include <iostream>
#include <strings>
#include <cmath>
#include <math.h>
using namespace std;


/**
 * functionname function ...
 * 
 * Input parameters: 
 * Output: 
 * Returns:    // if nothing - void function
*/

double smallestNumber(double n1, double n2, double n3)
{
    if (n1 < n2 && n1 < n3)
    {
        return n1;
    }
    if (n2 < n1 && n2 < n3)
    {
        return n2;
    }
    if (n3 < n1 && n3 < n2)
    {
        return n3;
    }
    
}

int main()
{
    // tests
    
    return 0;
}