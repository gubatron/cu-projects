#include <iostream>
using namespace std;


/**
 * GasBill function calculates cost with following conditions:
 *      1. first 100 units are charged at $1.23 per unit
 *      2. next 100 units are $1.14 per unit
 *      3. any units above 200 are charged at $1.08 per unit
 * Print "Incorrect input" for invalid parameters and return 0
 * Input parameters: gas (int)
 * Output: nothing
 * Returns: cost (double)   // not void function
*/

double GasBill (int gas)
{
    double cost; 
    if (gas < 0)
    {
        cout << "Incorrect input" << endl;
        return 0;
    }
    else if (gas <= 100)
    {
        cost = gas * 1.23; 
        return cost;
    }
    else if (gas <= 200)
    {
        cost = (100*1.23) + ((gas - 100) * 1.14);
        return cost;
    }
    else
    {
        cost = (100*1.23) + (100 * 1.14) + ((gas - 200) * 1.08);
        return cost; 
    }
}

int main()
{
    cout << GasBill(244) << endl;
    cout << GasBill(82) << endl;
    cout << GasBill(-23) << endl;
    cout << GasBill(0) << endl;
}