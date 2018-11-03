#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

// Write a function named matrixThreshold that takes as input pairs of integers as a 2D array, the total number pairs (i.e. number of rows/first dimension of the array), and a threshold and then returns the number of elements in the array that are greater than or equal to said threshold as an int.
// The function must be named matrixThreshold
// The function must have three input parameters:
// 2D integer array : list of numbers where the second dimension is always of size 2 
// Integer : represents the size of the first dimension of the 2D array
// Integer : defining the threshold
// Returns the number of elements in the 2D array greater than the threshold as an int.


// Example with one pair:

// int array[1][2]={{13,15}}; 

// matrixProduct(array, 1, 14) returns 1


int matrixThreshold(int numlist[][2], int size1, int threshold)
{
    // return # elements in array ? threshold
    int count = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (numlist[i][j] >= threshold)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int array[1][2] = {{13,15}};
    matrixThreshold(array, 1, 14);
}
