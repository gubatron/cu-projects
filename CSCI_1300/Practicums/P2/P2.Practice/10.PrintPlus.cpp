#include <iostream>
using namespace std;

/**
 * PrintPlus takes in no parameters nor returns any value, but prints 4 rows of 3 plus sign each.
                                    +++ 
                                    +++ 
                                    +++
                                    +++
 * Input parameters: nothing
 * Output: nothing
 * Return: nothing
*/

void PrintPlus()
{
    for (int i = 0; i < 4; i++) // from 0 to 3
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "+" ;
        }
        cout << endl;
    }
}


int main()
{
    PrintPlus();
    return 0;
}

