#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/**
 * findDuplicate prints duplicate element of given array of integers
 *  - if a number in array is repeated, print that number
 *  - if there are no duplicates, print -1
 * @param int : arr[]
 *        int : size
 * @output repeated number or -1
 * @return VOID
 */ 
 
void findDuplicate(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] == arr[i])
            {
                cout << arr[j] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
     int array[] = {2,3,5,6,11,20,4,8,4,9};
     findDuplicate(array, 10);
}