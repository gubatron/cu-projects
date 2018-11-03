#include <iostream>
using namespace std;

/**
 * Function called printSquares
 *      Print a filled and a hollow square 
 *      Given width, fills side by side to the screen
 *      Two squares separated by single space
 * Input parameters: width (integer)
 * Output: two squares (one filled, one hollow)
 *  separated by a space
 * Returns: nothing
*/

int printSquares(int width)
{
    cin >> width;
    int columns = 0;
    int rows = 0;
    for (rows = 0; rows < width; rows++)
    {
        for (columns = 0; columns < width; columns++) // prints first width# of * for first square
        {
            cout << "*" ;
        }
        if (columns >= width)
        {
            cout << " ";    // prints space between squares
        }
        
        if (rows == 0 || rows == width - 1)     // prints for rows equal to zero and rows equal to width
        {
            for (columns = 0; columns < width; columns++) // prints second width# of *
            {
                cout << "*" ;
            }
        }
        else                                    // prints for rows not equal to zero or width    
        {
            cout << "*";    // * before loop for first column of second square
            for (columns = 1; columns < width - 1; columns++) // prints empty spaces in between columns of second square
            {
                cout << " ";  
            }
            cout << "*";    // * after loop for last column of second square
        }
    cout << "\n";
    }
}

int main()
{
    int width;
    printSquares(width);
    
    // test 1
    // expected output
    // ***** *****
    // ***** *   *
    // ***** *   *
    // ***** *   *
    // ***** *****
    //printSquares(5);
    
    // test 2
    // expected output
    // *** ***
    // *** * *
    // *** ***
    //printSquares(3);
}