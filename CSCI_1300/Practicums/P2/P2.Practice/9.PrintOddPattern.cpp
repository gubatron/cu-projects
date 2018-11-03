#include <iostream>
using namespace std;

/**
 * PrintOddPattern takes in no parameters nor returns any value, and prints 3 rows and 5 columns as follows: 
 *      asterisk('*') in even columns, dollar('$') in odd columns.
 *      PrintOddPattern();
                            $*$*$
                            $*$*$
                            $*$*$
 * Input parameters: nothing
 * Output: nothing
 * Return: nothing
 * 
 */

void PrintOddPattern()
{
    for (int i = 1; i < 4; i++) // i rows 1 - 3
    {
        for (int j = 1; j < 6; j++) // j columns 1 - 5
        {
            if (j % 2 == 0)
            {
                cout << "*";
            }
            else
            {
                cout << "$";
            }
        }
        cout << endl;
    }
}


int main()
{
    PrintOddPattern();
    return 0;
}