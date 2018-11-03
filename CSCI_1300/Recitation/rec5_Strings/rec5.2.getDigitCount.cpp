#include <iostream>
using namespace std;

/**
 * Function called getDigitCount
 *   Counts the number of digits in a string
 * Input parameters: s (string)
 * Output: nothing
 * Returns: number of digit characters in the string (int)
*/

int getDigitCount(string s)
{
    int count = 0;
    if (s.length() > 0) // empty string. if (s == "")
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9') // or you can say (s[i] >= '65' && s[i] == '67') with ASCII table numbers
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string str = "ABCD0597CAA";
    cout << getDigitCount(str);
    return 0;
}