#include <iostream>
using namespace std;

/**
 * MultiplicationTableWhile will print a multiplication table for 1, 2, 3, 4, and 5 using only while loops
 * Input parameters: nothing     
 * Output: nothing
 * Return: nothing
*/

void MultiplicationTableWhile()
{
    int mult = 1; // start at 1
    while (mult < 6) // from 1 to 5
    {
        int i = 1; // start at 1
        while (i <= mult) // from i to mult
        {
            cout << mult * i << " " ;
            i++;
        }
        mult++;
        cout << endl; // end line after every i is over
    }
}

int main()
{
    MultiplicationTableWhile();
    return 0;
}