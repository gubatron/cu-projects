#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * checkFile function opens file and tells you whether a file was opened, true.
 * False otherwise
 * @param:  filename : string
 * @output: nothing
 * @return: boolean true or false
 */ 
 
bool checkFile(string filename)
{
    ifstream filestream; // reading and writing, not specified which
    filestream.open(filename);
    
    if (filestream.fail())
    {
        return false;
    }
    else
    {
        return true;
    }
    filestream.close();
}
 
int main()
{
    checkFile("rec8.NOTES");
    return 0;
}