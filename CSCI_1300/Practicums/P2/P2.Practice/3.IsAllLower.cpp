#include <iostream>
using namespace std;

/**
 * IsAllLower takes a string as input and 
 * returns true if ALL the alphabetic characters in the string 
 * are lowercase alphabetic characters. 
 * The function returns false otherwise. 
 * If input string contains non-alphabetic character, return false.
 * Input parameters: str : string
 * Output: nothing
 * Return: true or false : bool
 * 
*/

bool IsAllLower(string str)
{
    if(str.length() == 0)
    {
        return true;
    }
    for(int i = 0; i < str.length(); i++)
    {
        if (!(str[i] >= 97 && str[i] <= 122)) // NOT an alphabetic LOWERCASE character
        {
            return false;
        }
    }
    return true; // only gets here if no number is found
} 

int main()
{
    cout << IsAllLower("onetwo") << endl;
    cout << IsAllLower("onEtwo") << endl;
    cout << IsAllLower("^#$%123") << endl;
    cout << IsAllLower("") << endl;
}

// Example:

// Calling function with string "onetwo", should return true.
// Calling function with string "onEtwo", should return false.
// Calling function with string "^#$%123", should return false.
// Edge Case:

// If the string is empty, return true.

