#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

int writeAvg(string filename, int arr[], int length)
{
    ofstream filestream;
    filestream.open(filename);
    
    if (!(filestream.is_open()))
    {
        return -1;
    }
    
    string line = "";
    // int sum[length];
    int total = 0;
    for (int linenumber = 0; linenumber < length; linenumber++)
    {
            for (int i = 0; i < length; i++)
            {
                total = total + arr[i]; 
                filestream << total/length << endl;
            }

            
    }
    return 1;
}

int main()
{
    
    
    return 0;
    
}
