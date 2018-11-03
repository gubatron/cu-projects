#include <iostream>
using namespace std;

/**
 * ReplaceHashTag takes a string as input and replaces all the hashtags (#) characters with @ character.
 * Returs a string representing input string containing # character replaced with @ character
 * Input parameters: str : string   
 * Output: nothing
 * Return: string with # replaced with @ : string
 */

string ReplaceHashTag(string str)
{
    string tempString = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '#') // if you find a #
        {
            tempString += '@'; // add an @ to tempString
        }
        else if (str[i] != '#') // if it's not a #
        {
            tempString += str[i]; // add the character to tempString
        }
    }
    return tempString;
}

int main()
{
    cout << ReplaceHashTag("#SKO #Buffs"); // @SKO @Buffs
    return 0;
}