#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * fileLoadRead reads a file and counts the number of lines whether they're empty
 * or not
 * @param   string : filename
 * @output  nothing
 * @return  number of lines; -1 if not open succesfully
 */ 
 
int fileLoadRead(string filename)
{
    ifstream filestream;
    filestream.open(filename);
    int linecount = 0;
    if (filestream.fail())
    {
        linecount = -1;
    }
    else // if it's open
    {
        string line = "";
        while (getline(filestream, line))
        {
            linecount++;
        }
    }
    return linecount; 
    filestream.close();
}
 
int main()
{
    fileLoadRead("rec7.Notes");
    return 0;
}