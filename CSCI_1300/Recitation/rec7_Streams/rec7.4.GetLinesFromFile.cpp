#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

/**
 * getLinesFromFile reads from a file of integers and stores its content in an array.
 * Each line in the file will either contain a single integer or be empty.
 *      1) Fills array with the integes in the file
 *      2) Once array is full (length integers have been added),
 *              subsequent integers in the file should be ignored
 *      3) If file does not exist - return -1
 * Input Parameters: filename : string
 *                   array[]  : int 
 *                   size     : int // length of array
 * Output: nothing
 * Return: number integers added to the array if file exists : int
 */
 
int getLinesFromFile(string filename, int array[], int size) 
{
    // need to bring file in to use in the program
    ifstream myfilestream; // variable to read from stream 
    myfilestream.open(filename); // calling filename variable to OPEN using the stream
    
    if (myfilestream.fail()) // if the file open was unsuccessful
    {
        return -1;
    }
    else if (myfilestream.is_open()) // check if it's open
    {
        // read line by line
        // 3 inputs for getline(filestream variable, string variable/1st line in file, optional character delimeter)
        string line = "";   // ---->------->------->------> ^ 2nd parameter
        int lineCount = 0;  // counts lines
        while(getline(myfilestream, line)) // getline reads one line at a time and loop reads whole thing
        {
            if (line != "") // if line is not empty
            {
                // fill array starting at zero with integers from file
                array[lineCount] = stoi(line); // for array at the line, stoi converts text int file into integers line by line
                lineCount++;
            }
        }
        return lineCount;
    }
    myfilestream.close();
}
 
 
int main()
{
    int arr[4];
    getLinesFromFile("fileName.txt", arr, 4);
        // if fileName.txt has these contents:
        //         1
        //         5
        //         23
                
        //         18
        // returns 4 and would look like: [1, 5, 23, 18]
    return 0;
}
 