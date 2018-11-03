#include <iostream>
using namespace std;

/**
 * Function called getLastIndex
 *      returns last index at which a character 
 *      is used in a string
 * Input parameters: c (char), s (string)
 * Output: nothing
 * Returns: last index (int)
*/

int getLastIndex(char c, string s)
{
    if (s.empty()) // nothing in string
    {
        return -1;
    }
    int i = s.length() - 1; // i is the last index
    while (i >= 0)
    {
        if (s[i] == c)
        {
            return i;
        }
        i--;    // goes backwards
    }
    return -2;
}

int main()
{
    cout << getLastIndex('z',"");
    
    return 0;
}