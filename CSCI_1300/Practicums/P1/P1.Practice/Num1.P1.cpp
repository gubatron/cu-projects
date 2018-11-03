#include <iostream>
using namespace std;


/**
 * CoffeeCost function calculates cost of student 
 *  coffee consumption
 *  1. takes in the number of cups of coffee
 *  and a floating point value for the cost per cup
 *  2. free cup reward for every 12 cups of coffee bought. 
 *  3. cost = units * cost per unit
 * Input parameters: cups (int); cost (doulbe)
 * Output: nothing
 * Returns: cost (double)   // not void function
*/

/**
 * if returns a value, make sure there is ideally just ONE return statement
 *      note to declare that varialbe above. 
*/

// double CoffeeCost (int n, double price) //prototype, declaration, header
// {
//     double freeCups = n / 12; 
//     if (n > 0 && n % 12 == 0) 
//     {
//         freeCups--;
//     }
//     return (n - freeCups) * price;
// }

// OR

// double CoffeeCost (int n, double price)
// {
//     if (n <= 12)
//     {
//         price = n * price;
//     }
//     else if (n > 12)
//     {
//         int freeCups = n / 12;
//         n = n - freeCups;
//         price = n * price;
//     }
//      return price;
// }

// invalid input return -1
double CoffeeCost (int cups, double price)
{
    double totalPrice;
    if (cups < 0 || price < 0) // invalid input
    {
        totalPrice = -1 ; 
    }
    else
    {
        int rewards = cups/13; // how many free cups
        if (rewards >= 1) // have free coffee
        {
            totalPrice = (cups - rewards) * price;
        }
        else
        {
            totalPrice = cups * price; 
        }  
    }
    return totalPrice;
}

int main()
{
    cout << CoffeeCost(4,5) << endl; // expected value: 20
    cout << CoffeeCost(11,5) << endl;// expected value: 55
    cout << CoffeeCost(12,5) << endl;// expected value: 60
    cout << CoffeeCost(13,5) << endl;// expected value: 60
    cout << CoffeeCost(14,5) << endl;// expected value: 65
    cout << CoffeeCost(24,5) << endl;// expected value: 115
    cout << CoffeeCost(25,5) << endl;// expected value: 120
    cout << CoffeeCost(26,5) << endl;// expected value: 120
    cout << CoffeeCost(27,5) << endl;// expected value: 125
    return 0;
}