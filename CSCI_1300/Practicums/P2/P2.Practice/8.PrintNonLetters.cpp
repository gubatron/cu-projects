#include <iostream>
using namespace std;

/**
 * PrintNonLetters, takes a string as input and only prints the NON-alphabetic characters. 
 *      If the string is empty, print "NULL"
 *      If there are no NON-alphabetic characters in the string, print "-2"
 * Input parameters:  str : string   
 * Output: NON-aplphabetic characters from str
 * Return: nothing
 * 
 */

void PrintNonLetters(string str)
{
    if (str.empty())
    {
        cout << "NULL";
        return;
    }
    string tempString = ""; // use tempString to store values
    for (int i = 0; i < str.length(); i++)
    {
        // if character in string is NOT a letter, print the character
        if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)))
        {
            tempString = tempString + str[i]; // add character of index into tempString
        }
    }
    // if string is all letters / tempString is empty at the end, print -2
    if (tempString.empty())
    {
        cout << "-2";
    }
    else // otherwise, if tempString is not empty, print tempString
    {
        cout << tempString << endl;
    }
}
 
int main()
{
    PrintNonLetters("one1, two2"); // 1, 2
    PrintNonLetters("Test3: 2 String."); // 3: 2 .
    PrintNonLetters(""); // -2
    return 0;
}