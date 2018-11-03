#include <iostream>
using namespace std;


/**
 * PizzaParty function calculates the cost of a students pizza party
 *     Assume all input parameters are positive
 * Input parameters: numberOfPizzas (int); costPerPizza (double); discount (double)
 * Output: nothing
 * Returns: totalCost (double)   // not void function
*/

double PizzaParty (int numberOfPizzas, double costPerPizza, double discount)
{
    double cost;
    if (numberOfPizzas < 10)
    {
        cost = (numberOfPizzas * costPerPizza) + 10;
        return cost;
    }
    else
    {
        cost = numberOfPizzas * (costPerPizza - (discount * costPerPizza));
        return cost;
    }
}

int main()
{
    cout << PizzaParty(10,10,0.1) << endl;
    cout << PizzaParty(5,10,0.2) << endl;
}