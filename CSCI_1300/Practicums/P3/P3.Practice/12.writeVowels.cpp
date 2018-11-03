#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/**
 * writeVowels function will read the strings from the array and output to the 
 * file the number of vowels contained in each string along-with the string 
 * itself. 
 * The function should skip writing for empty strings and should return the 
 * total number of lines that were written to the file.
 * @param   string : filename
 *          string : array[]
 *          int : length
 * @output WRITES total number of lines written to file (count variable)
 * @return 
 */ 

// does NOT read a file
// read arrat and only WRITES TO FILE
int writeVowels(string filename, string array[], int length)
{
    ofstream outstream;
    outstream.open(filename);
    
    int vowelcount = 0;
    int linecount = 0;
    char ch;
    string str = "";
    
    // read through array looking for words
    for (int i = 0; i < length; i++)
    {
        // count vowels for words
        str = array[i];
        for (int j = 0; j < str.length(); j++) // per index of string
        {
            ch = str[j];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                vowelcount++; // increase every time you find a vowel
            }
        }
        if (!(str.empty())) // not empty
        {
            outstream << str << "," << vowelcount << endl;
            linecount++;
        }
    }
    outstream.close();
    return count;
    //outstream << "Number of lines written: " << linecount << endl;
    // loop through words in array and print "word,"
    //outstream << array[i] << "," 
    // if string is not empty:
    // write vowels to filename "Number of lines written: " #, and the "string, " #
    // 
}