#include <iostream>
using namespace std;

/**
 * Function called printEvenNums
 *   Prints all positivve even integers <= maxValue
 *   max represents maxalue
 * Input parameters: maxValue (integer)
 * Output: positive integers <= maxValue
 * Returns: nothing
*/


int printEvenNums(int maxValue)
{
  //cin >> maxValue;      // use this line of code for any value
    int count = 0 ;
    while (count < maxValue)
    {
        count = count + 2;
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
    // 2 4 6 8 10
    printEvenNums(10);
    
    // test 2
    // expected output
    // 2 4 6 8 10 12 14
    //printEvenNums(15);
}