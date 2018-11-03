#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

/**
 * replaceNums that replaces each element except the first and last by the
larger of its two neighbors.
 * Input Parameters: array[] : int //// integer array
 *                   size    : int //// length of given array
 * Output: nothing
 * Return: nothing
 */
 
void replaceNums(int array[], int size)
{
    int i = 0; 
    int temp[size]; // create a temp array size of original array
    for (i = 0; i < size; i++)
    {
        // pass array[] by reference -- sharing memory location
        temp[i] = array[i]; // fill in temp with contents of original array
    }
    for (i = 0; i < size; i++)
    {
        if (!(i == 0 || i == size - 1)) // if it's NOT the first or last value do... (if it is, do nothing)
        {
            if (temp[i-1] >= temp[i+1]) // value on left > value on right
                        // ^ if both are the same
            {
                // copy i and i+2 to tempArray
                // replace i with i-1
                array[i] = temp[i-1];
            }
            else if (temp[i-1] < temp[i+1]) // value on left < value on right
            {
                // copy i and i+2 to tempArray
                // replace i with i+1 
                array[i] = temp[i+1];
            } 
        }
    }
}
 
 
int main(){
    int array[5] = {5,4,3,2,1};
    replaceNums(array, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << array [i] << " ";
    }
    return 0;
}