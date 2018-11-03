#include <iostream>
using namespace std;


/**
 * TuitionCost function calculates the cost of a student's tuition
 *  If student takes > 16 units, cost is 16 * cost per unit + 
 *  (number of units / 16) + (cost per unit/2)
 * Input parameters: units (int); unitcost (double)
 * Output: nothing
 * Returns: cost (double)   // not void function
*/

// double TuitionCost (int units, double unitcost)
// {
//     double cost;
//     if (units < 0 || unitcost < 0)
//     {
//         return -1;
//     }
//     else if (units >= 0 && units <= 16)
//     {
//         cost = units * unitcost;
//         return cost;
//     }
//     else
//     {
//         cost = (16 * unitcost) + (units - 16) + (unitcost / 2) - 1;
//         return cost;
//     }
// }

double TuitionCost (int units, double unitcost)
{
    double cost;
    if (units < 0 || unitcost < 0)
    {
        return -1;
    }
    else if (units >= 0 && units <= 16) //|| (unitcost >= 0 && unitcost <= 16))
    {
        cost = units * unitcost;
        return cost;
    }
    else
    {
        cost = (16 * unitcost) + (units - 16) * (unitcost / 2) ;
        return cost;
    }
}

int main(){
    cout << TuitionCost(-16,-200) << endl;
    cout << TuitionCost(17,300) << endl;
}


/// HIDDEN TEST CASES!