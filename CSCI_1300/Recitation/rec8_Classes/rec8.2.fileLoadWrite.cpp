#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * fileLoadWrite opens a file and writes to it the squaes of the numbers 1-10, 
 * each on its own line.
 * @param   string : filename
 * @output: print squares of integers 1 to 10 to file, each on its own line
 *          ofstream
 * @return: 0 if opened successfully, -1 otherwise
 */ 
 
int fileLoadWrite(string filename)
{
    ofstream filestream; // WRITING to a file; creates output file stream
    filestream.open(filename); 
    
    if (filestream.fail())
    {
        return -1;
    }
    else // if it's open
    {
        for (int linenumber = 1; linenumber < 11; linenumber++)
        {
            int x = linenumber * linenumber;
            filestream << x << endl; // here "filestream" behaves like cout
        }
    }
    return 0;
    filestream.close();
}
    


int main()
{
    fileLoadWrite("rec8.txt");
    return 0;
}
