#include <iostream>
using namespace std;

/**
 * Function called getMatchCount
 *      takes a long string and a candidate substring
 *      and returns the number of times the substring
 *      occured in the longer string.
 * Input parameters: needle (string); haystack (string)
 * Output: nothing
 * Returns: number of times the substring occurs in the string (int)
*/

int getMatchCount(string needle, string haystack)
{
    if (needle.empty() || haystack.empty()) // nothing in string or haystack
    {
        return -1;
    }
    if (needle.length() > haystack.length())
    {
        return -2;
    } 
    int i = 0; // i is the beginning
    int matches = 0; 
    int end = haystack.length()-needle.length();
    int needleLength = needle.length();
    while (i < end)
    {
        if (haystack.substr(i, needleLength) == needle)  // substr(pos, length)
        {
            matches++;
        }
        i++;    // goes forwards
    }
    return matches;
}


int main()
{
    cout << getMatchCount("si","Mississippi");
    
    return 0;
}
