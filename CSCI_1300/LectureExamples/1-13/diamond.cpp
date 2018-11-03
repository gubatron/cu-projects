#include <iostream>
using namespace std;

// n = 4
// ---*---
// --***--
// -*****-
// *******

// n = 3
// --*--
// -***-
// *****


int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        // first dashes --- n - i [row number]
        for (int j = 0; j < n - (i+1); j++) // runs n-row# times
        {
            cout << " ";
        }
        // then stars --- 2*row# - 1
        for (int k = 0; k < (2 * (i+1) - 1); k++)
        {
            cout << "*";
        }
        // then dashes again
        for (int j = 0; j < n - (i+1); j++) // runs n-row# times
        {
            cout << " ";
        }
        
        cout << endl;
    }
}