#include <iostream>
using namespace std;

/**
 * PrintAsterisks takes in no parameters nor returns any value, but prints 3 rows of 4 Asterisks each.
 * Input parameters: nothing   
 * Output: nothing
 * Return: nothing
 * 
*/

void PrintAsterisks()
{
    for (int i = 1; i < 4; i++) // i rows from 1 to 3
        //   i > 0; i <= 3
    {
        for (int j = 1; j < 5; j++) // j columns (*) from 1 to 4
            //   j > 0; j <= 4
        {
            cout << "*";
        }
        cout << endl;
    }
}


int main()
{
    PrintAsterisks();
}


// PrintAsterisks();

// **** 
// **** 
// ****
