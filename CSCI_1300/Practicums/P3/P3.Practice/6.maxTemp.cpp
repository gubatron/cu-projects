#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

 /* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
int split (string str, char c, string array[], int size)
{
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
 }


/**
 * maxTemp takes a filename as string argument and returns the maximum 
 * temperature as float type for the week.
 * 
 * @param  string : filename
 * @output
 * @return max temperature float; -1 if can't open
 */ 
  
float maxTemp(string filename)
{
    int n = 7; // number of days
    float max = 0;
    
    ifstream in; // reading from a file
    in.open(filename);
    
    if (in.fail())
    {
        return -1;
    }
    // now that it's open, read through it
    else if (in.is_open())
    {
        string line = "";
        string store[n]; // array to store what split() finds; same size as title[] and author[]
        
        while (getline(in, line))
        {
            if (line != "")
            {
                split(line, ',', store, n); // split at ','
                if (max <= stof(store[1]))
                {
                    max = stof(store[1]); // maximum
                }
            }
        }
    }
    return max;
    in.close(); 
}
 
int main()
{
    cout << maxTemp("averageTemp_EXAMPLE.txt");
    return 0;
}
