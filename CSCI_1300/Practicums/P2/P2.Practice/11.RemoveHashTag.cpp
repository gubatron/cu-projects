#include <iostream>
using namespace std;

/**
 * RemoveHashTag takes a string as input and removes all the hashtags (#) characters.
 * The function returns a string value without the hashtag characters.'
 * Input parameters: str : string
 * Output: nothing
 * Return: string without hashtags : string
 * 
 */
 
string RemoveHashTag(string str)
{
    string tempString = ""; // start with an empty tempString 
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '#') // if it's not a #
        {
            tempString += str[i]; // add character to the tempString
        }
    }
    return tempString;
}

 
int main()
{
    cout << RemoveHashTag("#SKO #Buffs"); // SKO Buffs
    return 0;
}