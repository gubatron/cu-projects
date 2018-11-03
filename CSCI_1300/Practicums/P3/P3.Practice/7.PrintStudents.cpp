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
int split (string str, char c, string array[3])
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
 * PrintStudents function read the student scores and names from the file and 
 * output the names of the students with scores greater than or equal to the 
 * value given.  returns the integer number of entries read from the file.  
 * If the input file cannot be opened, return -1 and do not print anything to 
 * the file.
 * @param  string : in_filename
 *         int : minScore
 *         string : out_filename
 * @output
 * @return how many people are in the file; and put names > minScore in out_filename
 */ 
int PrintStudents(string in_filename, int minScore, string out_filename)
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
    // now that both are open
    string line = "";
    int count = 0;
    int smartkids = 0;
    int linecount = 0;
    string store[3];
    while (getline(first_filestream, line))
    {
        if (line != "")
        {
            split(line, ',', store);
            if (minScore <= stoi(store[1]))
            {
                for (int i = smartkids; i <= smartkids; i++)
                {
                    second_filestream << store[0] << ", " << store[2] << endl;
                    linecount++;
                    if (linecount > i)
                    {
                        i++;
                    }
                }
            }
            count++;
        }
    }
    return count;
    first_filestream.close();
    second_filestream.close();
}

int main()
{}