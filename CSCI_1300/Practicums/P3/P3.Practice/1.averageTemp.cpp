#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
#include <cmath>
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
 * averageTemp function takes a filename as string argument and returns the
 * avg temp as float type for the week. Input file contains temperature readings 
 * for each day of the week. 
 *  - Reads each line form filename, parse and processes data, and returns 
 *      required information. 
 *  - ignore empty lines
 *  - if cannot open file, return -1
 *  - temp readings can be decimals and negative numbers
 *  - each line has two elements separated by commas (use split)
 * 
 * @param: string = filename
 * @output: nothing
 * @return avg temp for whole week rounded to 2 digits floating point precision
 */ 

float averageTemp(string filename)
{
    double tempSum = 0.0;
    double avg = 0.0;
    int count = 0;
    int n = 7; // number of days
    
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
                tempSum = tempSum + stof(store[1]); // temperature[] takes index 1 from split
                               //   ^ string to float
                count++;
            }
        }
        avg = tempSum/count;
    }
    return avg;// << fixed << setprecision(2);
    in.close(); 
}
 
int main()
{
    cout << fixed << setprecision(2) << averageTemp("averageTemp_EXAMPLE.txt");
    return 0;
}
 
 