#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
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

/**
 * countPrimes function returns the count of the number of prime elements 
 * in the array.
 * 
 * @param int : arr[]
 *        int : size
 * @output
 * @return int : count of primes
 */ 
 
int countPrimes(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        int yeet = IsPrime(arr[i]);
        if (yeet == 1)
        { 
            count++;
            //temp[i] = IsPrime(arr[i]);
        }
    }
    return count;   
}

int main(){
    int array[8] =  {1, 2, 3, 4, 5, 7, 10, 12};
    int size = 8;
    cout << countPrimes(array, size);
    return 0;
}