#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/**
 * countCharacter function counts the number of times a given character 
 * appeared in the whole array.
 * @param   string : str[]
 *          int : size
 * @output
 * @return  int number of times character appears in str[]
 */ 

int countCharacter(string str[], int size, char ch)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        string word = str[i];
        for (int j = 0; j < word.length(); j++)
        {
            if (word[j] == ch)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string array[] = {"elephant", "english", "elegant", "america", "united", "apple"};
    char ch = 'e';
    // return value: 8
    cout << countCharacter(array, 6, ch) << endl;
}