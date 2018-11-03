#include <iostream>
using namespace std;

/**
 * Function called printMultiples
 *   Prints all positive multiples of an integer
 *   <= a maxValue
 * Input parameters: n (integer); maxValue (integer)
 * Output: positive multiples of n <= to maxValue
 * Returns: nothing
*/

int printMultiples(int n, int maxValue)
{
  //cin >> n ;            // use this line of code for any integer value
  //cin >> maxValue;      // use this line of code for any maximum value
    int count = 0 ;
    while (count < maxValue)
    {
        count = count + n;
        if (count <= maxValue)
        {
           cout << count << endl;
        }
    }
    
}

int main()
{
    // test 1
    // expected output
    // 3 6 9
    printMultiples(3,10);
    
    // test 2
    // expected output
    // 2 4 6 8 10
    //printMultiples(2,10);
    
    // test 3
    // expected output
    // 5 10 15
    //printMultiples(5,19);
}
 