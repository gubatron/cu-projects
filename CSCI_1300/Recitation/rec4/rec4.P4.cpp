#include <iostream>
using namespace std;

/**
 * Function called printDiamond
 *   Given side legnth to screen
 * Input parameters: n (integer -- side length of diamond)
 * Output: diamond with correct s
 * Returns: nothing
*/

int printDiamond(int n)
{
    cin >> n;  // use for arbitrary n input
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
    // bottom half 
    for (int i = n - 2 ; i >= 0; i--) // loop has same content as upper half
                                      // i starts at n-2 and becomes zero at the end
    {
        // first dashes
        for (int j = 0; j < n - (i+1); j++) 
        {
            cout << " ";
        }
        // then stars
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


int main()
{
    int n;
    printDiamond(n);
    // test 1
    // expected output
    //    *   
    //   ***  
    //  ***** 
    // *******
    //  ***** 
    //   ***  
    //    *
    //printDiamond(4);
    
    // test 2
    // expected output
    //    *   
    //   ***  
    //    *
    //printDiamond(2);
   
}