#include <iostream>
#include <string>
using namespace std;

/**
 * CountVowels function takes string as input and counts number of vowels
 *  (a,e,i,o,u either upper or lower case) alphabetic characters.
 *  - If no vowels in string, return 0
 *  - if empty string, return -1
 * Input parameters:    str:string
 * Output:  nothing
 * Return:  vowels:int
 * 
*/

//////////////////////////////////////
int CountVowels(string str)
{
    if (str.empty()) // or str.lentgh() == 0
        {
            return -1;
        }
    int count = 0;
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < str.length(); i++)  // reads through string
    {
        if(vowels.find(str[i]) != -1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    cout << CountVowels("qwrt");  // expected output: 0
}
