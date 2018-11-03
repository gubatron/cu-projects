#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * saveData function saves intermediate results to a file. The results are
 * otherwhise lost when the program finishes executing.
 *      Use ofstream
 * @param   string      : filename
 *          string array: results
 *          int         : n (numerical values in results[])
 *          int         : size
 * @output: nothing if open successfully, if fail: "file open failed"
 * @return: nothing/void
 */  

//is the file im writing to different from the file im opening?
void saveData(string filename, string results[], int n, int size)
{
    ofstream filestream;
    filestream.open(filename);
    if (filestream.is_open())
    {
        if (n == -1)
        {
            filestream << "" << endl;
        }
        else if (n == 0)
        {
            if (results[0].length() > 0)
            {
                filestream << "Name: " << results[0] << endl; // first value in array
            }
        }
        // Separate value1, value2, and value3, from value4 (name)
        else if (n != 0)
        {
            double count = 0;
            for (int i = 0; i < n; i++) // DO I EVEN NEED i?
            { 
                double value = stof(results[i]);
                count += value; 
            }
            double avg = count/n;
            
            filestream << "Name: " << results[size-1] << endl; // last value in array
            filestream << "Avg: " << avg << endl; // divide by size of array minus 1 (values 1-3)
        }
    }
    else
    {  
        // since it's not opening, there's no way stream works so must use cout
        cout << "file open failed" << endl; 
    }
}
 
int main()
{
    string data[4] = {"2.3", "-1.5", "0.8", "Garth"};
    saveData("my_data.txt", data, 3, 4);
    
    // Expected Output:
    //      Name: Garth
    //      Avg: 0.5333
    
    return 0;
}