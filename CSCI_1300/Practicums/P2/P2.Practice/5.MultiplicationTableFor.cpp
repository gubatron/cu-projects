#include <iostream>
using namespace std;

/**
 * MultiplicationTableFor will print a multiplication table for 1, 2, 3, 4, and 5 using only for loops
 * Input parameters:  nothing   
 * Output:  nothing
 * Return:  nothing
 * 
 */
 
void MultiplicationTableFor()
{
    int mult, i;
    for (mult = 1; mult < 6; mult++) // from 1 to 5 incrementing mult
    {
        for (i = 1; i <= mult; i++) // from i to mult incrementing i
        {
            cout << mult * i << " "; // multiply mult * i 
        }
        cout << endl; // end line after every i is over
    }
}
 
int main()
{
    MultiplicationTableFor();
    return 0;
}
 
//  MultiplicationTableFor();

// 1 
// 2 4 
// 3 6 9 
// 4 8 12 16 
// 5 10 15 20 25 
