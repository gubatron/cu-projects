
#include <iostream>
using namespace std;

/**
 * IsPrime returns true if the integer number given is a prime number, false otherwise. 
 * A prime Number can be divided evenly only by 1, or itself. 
 * A prime number must be a whole number greater than 1.
 * Input parameters: n : int
 * Output: nothing
 * Return: 1 if true, 0 if false : int
 *         1 if prime, 0 if not prime
*/

int IsPrime(int n)
{
    if (n <= 1) // 1 and 0 are not prime and neither are negative numbers
    {
        return 0;
    }
    for (int i = 2; i < n; i++) // will not reach final value (n)
    //start at 2 ^ b/c no need to check for 1 or itself because that is always true. 
    {
        if (n % i == 0) // number mod each number until it finds divisor
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    cout << IsPrime(1) << endl;
    cout << IsPrime(2) << endl;
    cout << IsPrime(0) << endl;
    cout << IsPrime(13) << endl;
    cout << IsPrime(-2) << endl;
    cout << IsPrime(1301081) << endl;
    
}

// Example: 5 can only be divided evenly by 1 or 5, so it is a prime number. 

// But 6 can be divided evenly by 1, 2, 3 and 6 so it is NOT a prime number.

// For example:

// Test	                            Result
// cout << IsPrime(3) << endl;      1
//                                      
// cout << IsPrime(4) << endl;      0