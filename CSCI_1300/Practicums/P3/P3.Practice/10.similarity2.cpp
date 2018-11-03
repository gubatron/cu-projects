#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/**
 * similarity2 function takes in two 2-D arrays of int type and their row sizes 
 * and returns true if the two arrays are identical and returns false if two 
 * arrays are not same. 
 * (Assume column size is always 3)
 * @param   int : arr1[][3]
 *          int : row1
 *          int : arr2[][3]
 *          int : row2
 * @output
 * @return bool true if identical, false if not
 */
bool similarity(int arr1[][3], int row1, int arr2[][3], int row2)
{
    bool ans = false;
    if (row1 == row2)
    {
        if (row1 == 0) // both arrays are empty
        {
            return true;
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr1[i][j] == arr2[i][j])
                {
                    ans = true;
                }
                else
                {
                    // as soon as it enters the else, it will be false
                    return false;
                }
            }
        }
        return ans;
    }
    else
    {
        return false;
    }
}

int main()
{
    int arr1[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    int arr2[3][3]= {{1, 4, 6}, {7, 23, 3}, {5, 15, 25}};
    cout << similarity(arr1, 3, arr2, 3) << endl;
    // 1
}