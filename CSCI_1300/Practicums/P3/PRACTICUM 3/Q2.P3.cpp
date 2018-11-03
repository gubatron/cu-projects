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
 
 
double smallestNumber(double n1, double n2, double n3)
{
    if (n1 < n2 && n1 < n3)
    {
        return n1;
    }
    if (n2 < n1 && n2 < n3)
    {
        return n2;
    }
    if (n3 < n1 && n3 < n2)
    {
        return n3;
    }
    
}


int parseScores(string filename)
{
    ifstream first_filestream;
    first_filestream.open(filename);
    
    if (first_filestream.fail())
    {
        return -1;
    }
    // now that it's open
    // open file to write to
    // now that both are open
    string line = "";
    int count = 0; // #student entries read
    int kids = 0;
    int linecount = 0;
    string store[3];
    while (getline(first_filestream, line))
    {
        if (line != "")
        {
            count++;
            split(line, ',', store, 3);
            int minScore = smallestNumber(stoi(store[0]), stoi(store[1]), stoi(store[2]));
            cout << store[3] << ": " << minScore << endl;
        }
    }
    return count;
}
int main()
{
    
}


STUDENT NAME: MIN SCORE