#include <iostream>
using namespace std;


/**
 * shampeName function takes number of surfaces of a shape
 *      returns the name of the shape
 *      use SWITCH CASES
 * Input parameters: n (int)
 * Output: nothing
 * Returns: shape name (string) // not void function
*/

string shapeName(int n)
{
    switch (n)
    {
        case 2: return "CONE";
            break;
        case 3: return "CYLINDER";
            break;
        case 4: return "TRIANGULARPYRAMID";
            break;
        case 6: return "CUBOID";
            break;
        default: return "UNKNOWN";
    }
}