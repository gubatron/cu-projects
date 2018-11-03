#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/**
 * diagonalSum function finds sum of main diagonal elements of a 2D array
 *      column size is always 3
 * @param int : arr[][3]
 *        int : row
 * @output
 * @return  int : sum of main diagonal items
 */ 
 
int diagonalSum(int arr[][3], int row)
{
    int sum = 0;
    for (int i = 0; i < row; i++) // checks rows
    {
        for (int j = 0; j < 3; j++) // checks columns
        {
            if (i == 0 && j == 0)
            {
                sum += arr[i][j];
            }
            if (i == 1 && j == 1)
            {
                sum += arr[i][j];
            }
            if (i == 2 && j == 2)
            {
                sum += arr[i][j];
            }
        }
    }
    
    // OR
    // int sum = arr[0][0] + arr[1][1] + arr[2][2]; 
    return sum;
}


int main()
{
    int arr[3][3] = {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    cout << diagonalSum(arr,3);
    return 0;
}