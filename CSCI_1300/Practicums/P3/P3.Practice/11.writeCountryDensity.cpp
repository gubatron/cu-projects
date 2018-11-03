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
int split (string str, char c, string array[])
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
 * writeCountryDensity function will read the country name, population, and 
 * area from the file and output the names of the country with the density 
 * less than or equal to the value given. 
 *  - if cannot open in_filename return -1
 *  - read each line, parse data, process data, write required info into output file
 *  - population density = population/area
 * @param   string : in_filename
 *          int : maxD
 *          string : out_filename
 * @output names of coutnry with density <= maxD
 * @return int number of entries written in out_file
 */ 
int writeCountryDensity(string in_filename, int maxDensity, string out_filename)
{
    ifstream first_filestream;
    first_filestream.open(in_filename);
    
    if (first_filestream.fail())
    {
        return -1;
    }
    // now that it's open
    // open file to write to
    ofstream second_filestream;
    second_filestream.open(out_filename);
    
    if (second_filestream.fail())
    {
        return -1;
    }
    // now that it's open
    string line = "";
    int count = 0; // number of entries to write in output file
    double density = 0;
    int linecount = 0;
    string store[3];
    while (getline(first_filestream, line))
    {
        if (line != "")
        {
            split(line, ',', store, 3);
            density = stod(store[1])/stod(store[2]); // string to double
            if (density <= maxDensity)
            {
                if (second_filestream.fail())
                {
                    return -1;
                }
                // now that it's open
                for (int i = density; i <= density; i++)
                //for (int i = 0; i < line; i++)
                {
                    second_filestream << store[0] << ", " << density << endl;
                    linecount++;
                    if (linecount > i)
                    {
                        i++;
                    }
                }
            }
        }
    } 
    return linecount;
}
