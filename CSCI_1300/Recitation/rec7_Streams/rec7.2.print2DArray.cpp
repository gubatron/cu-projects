#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

/**
 * printTwoDArray prints all the integers in a two dimensional array. 
 *      Each row of the array should be printed on a separate line with the integers separated by commas. 
 *      Assume that the array has 5 columns.
Edge Cases:
If the length is 0 your function should print 0.
If the length is a negative number your function should print -1.

 * Input Parameters: array[][5] : int //// 2D integer array with 5 columns
 *                   size       : int //// length of given array
 * Output: values in array[]
 * Return: nothing
 */
 
void printTwoDArray(int array[][5], int size)
{
    if (size == 0)
    {
        cout << 0;
        return;
    }
    if (size < 0)
    {
        cout << -1;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 4)
            {
                cout << array[i][j];
            }
            else 
            {
                cout << array[i][j] << ",";
            }
        }
        cout << endl;
    }
}

int main()
{
    int array[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    printTwoDArray(array, 3);
    return 0;
}

