#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

/**
 * floodMap takes 3 arguments and prints out a "map" of which points in the array are below the water level.
 *  3 Parameters:
 *      1) a two-dimensional array of doubles indicating the height of the terrain at a particular point in space 
*               (assume that there are 4 columns), 
*       2) an int indicating the number of rows in the map, 
*       3) and a double indicating the current water level. 
*  if the position is at or below the water level, represent with a *
*  if the position is above the water level, represent with _
 * Input Parameters: array[][] : double //// 2D array
 *                        rows : int    //// rows in map
 *                       water : double //// water level (vertical)
 * Output: flood map
 * Return: nothing
 */
 
void floodMap(double array[][4], int rows, double water)
{
    for (int i = 0; i < rows; i++) // horizontally, row number
    {
        for (int j = 0; j < 4; j++) // vertically, position in array 0, 1, ...
        {
            if (array[i][j] <= water)
            {
                cout << "*";
            }
            else if (array[i][j] > water)
            {
                cout << "_";
            }
        }
        cout << endl;
    }
}

int main()
{
    double map[1][4] = {{5.0, 7.6, 3.1, 292}};
    floodMap(map, 1, 6.0);
    return 0;
}