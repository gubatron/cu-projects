#include <iostream>
using namespace std;

/**
 * IsAllAlpha takes a string as input and returns true 
 *      if all the characters are alphabetic characters 
 *      in the string. The function returns false otherwise.
 * Input parameters: str : string  
 * Output: nothing
 * Return: true or false : bool
*/

// Example:

bool IsAllAlpha(string str)
{
    if(str.length() == 0) // if empty don't bother going through code
    // if (str.empty()) // another way to say the same thing
    {
        return true;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
        // if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
        {
            return false;
        }
    }
    return true; // only gets here if NO number is found
} 

// Method 2
// * create int counter = 0;
// * have for loop reading through line
// * if it is a letter, increase counter++
// * then outside of loop:
// *   if counter == str.length() -> return true;
// *   else, false

int main()
{
    cout << IsAllAlpha("O1ne two"); // return false
    cout << IsAllAlpha("Onetwo"); // return true
    cout << IsAllAlpha("one2"); // return false
    cout << IsAllAlpha(""); // return true
}
// Calling function with string "ONETWO", should return true.
// Calling function with string "One two", should return false.
// Calling function with string "one2", should return false.

// Edge Case:
// If the string is empty, return true.