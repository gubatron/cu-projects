#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

// Rec7 Notes - Streams

// 2D ARRAY
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void twoDimensionalFunction(int matrix[][3], int rows)
                                     // ^ columns
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    int twoDTest[3][3] = {{5, 2, 1}, {1, 2, 3}, {9, 8, 7}};
    twoDimensionalFunction(twoDTest, 3);
    // int outputArr[6] = {24, 11, 66, 352, -24, -48};
    // outputTest(outputArr, 6);
    return 0;
}

// Streams
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


void inputTest()
{  
    ifstream myFile;
    myFile.open(".../rec6_Arrays/rec6.Array.Notes.cpp"); // not just a file but a path
    int i=0;
    // if (myFile.is_open()){  // check if it is open -- boolean -  false if it is not open
        while(!myFile.eof())
        {
            string line;
            myFile>> line;
            cout << line << endl;
            if(line.length() != 0) // check if it's empty
            {
                int lineVal = stoi(line); // convert string to integer
                cout << lineVal << endl;
            }
        }
        myFile.close(); // close file when you're done
        }
        // else 
        // {
        //      cout << "Couldn't open file." << endl;
        // }

   
