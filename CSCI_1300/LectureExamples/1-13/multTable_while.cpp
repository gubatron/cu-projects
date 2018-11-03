#include <iostream>
using namespace std;


int main()
{
    // write a multiplication table for 5
    /* Output:
    5 10 15 20 25 30 35 ... 50
    */
    
    // Option 1: addition/accumulation
    // int i = 5;
    // int total = 0;
    // while (total < 50)
    // {
    //     total = total + 5;
    //     cout << total << " ";
    // }
    
    // Option 2: multiplication
    //int i = 5;                       // use this w line 29 code
    // int j = 0; // 1, 2, ... 10
    // while (j < 10)
    // {
    //     j++;
    //     cout << i * j << " ";
    // }
    // for (int j = 0; j < 10; j++) // this loop runs 10 times
    // {
    //     cout << i * (j+1) << " ";
    // }
    
    
    
    
    // multiplication table for 1 through 8
    // 1 2 3 ... 10
    // 2 4 6 ... 20
    // ...
    // 8 16 24 ... 80
    
    //int i = 5;
    //int m = 1; 
    // outer loop for the number of rows
    for (int k = 0; k < 8; k++)
    {
        for (int j = 0; j < 10; j++) // this loop runs 10 times. (colums)
        {
            cout << (k+1) * (j+1) << " ";
        }  
        //m++;
        cout << endl;
    }
    
    return 0;    
}