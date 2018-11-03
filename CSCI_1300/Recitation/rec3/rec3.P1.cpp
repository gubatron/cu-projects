#include <iostream>
using namespace std;


/**
 * numberSign function takes one integer paramter and prints whether
 * integer is negative, positive, or zero.
 * Input parameters: one number (int)
 * Output: negative, positive, zero
 * Returns: nothing
*/

void numberSign (int number)
{
    if  (number > 0)
    {
        cout << "positive";
    }
    else if (number < 0)
    {
        cout << "negative";
    }
    else 
    {
        cout << "zero";
    }
}

int main()
{
    cout << "Please enter a number" << endl;
    int number;
    cin >> number;
    numberSign(number);
    
    // test 1 with input of 500
    // expected output
    // positive
    
    // test 2 with input of -500
    // expected output
    // negative
}
