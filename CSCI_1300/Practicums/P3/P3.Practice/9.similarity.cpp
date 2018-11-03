#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/**
 * similarity function takes in 2 arrays of int type and their sizes and returns 
 * true if the two arrays are identical and returns false if two arrays are not
 * same.
 * @param   int : arr1[]
 *          int : size1
 *          int : arr2[]
 *          int : size2
 * @output
 * @return  bool true if identical, false if not the same
 */ 
 
bool similarity(int arr1[], int size1, int arr2[], int size2)
{   
    bool ans = false;
    if (size1 == size2)
    {
        if (size1 == 0) // both arrays are empty
        { 
            return true;
        }
        for (int i = 0; i < size1; i++)
        {
            if (arr1[i] == arr2[i])
            {
                ans = true;
            }
            else
            {
                // as soon as it enters the else, it will be false
                return false;
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
    // int arr1[]= {1, 4, 6, 7, 23, 3};
    // int arr2[]= {1, 4, 6, 7, 23, 3};
    // cout << similarity(arr1, 6, arr2, 6) << endl;
    // // 1
    
    // int arr1[]= {1, 4, 16, 7, 23, 3};
    // int arr2[]= {1, 4, 6, 7, 23, 3};
    // cout << similarity(arr1, 6, arr2, 6) << endl;
    // // 0
    
    // int arr1[]= {1, 7, 23, 3};
    // int arr2[]= {1, 4, 6, 7, 23, 3};
    // cout << similarity(arr1, 4, arr2, 6) << endl;
    // // 0
    
    // int arr1[]= {1, 4, 6, 7, 23, 3};
    // int arr2[]= {};
    // cout << similarity(arr1, 6, arr2, 0) << endl;
    // // 0
    
    // int arr1[]= {1, 1, 1, 1, 1};
    // int arr2[]= {1, 1, 1, 1, 1};
    // cout << similarity(arr1, 5, arr2, 5) << endl;
    // // 1
    
    int arr1[]= {};
    int arr2[]= {};
    cout << similarity(arr1, 0, arr2, 0) << endl;
    // // 1
}