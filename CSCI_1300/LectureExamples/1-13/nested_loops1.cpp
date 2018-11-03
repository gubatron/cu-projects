/*
Prints 3 rows of 4 asterisks each.
**** 
**** 
****
*/
#include <iostream>
using namespace std;

int main()
{
    int i,j;
    for ( i = 0 ; i < 3 ; i++ )
    {
        for ( j = 0 ; j < 4; j++  )
        {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}

// EXAMPLE 2 
// /*
// Prints 4 rows of 3 asterisks each.
// *** 
// *** 
// ***
// ***
// */
// #include <iostream>
// using namespace std;

// int main()
// {
//     int i,j;
//     for ( i=0 ; i < 4 ; i++ )
//     {
//         for ( j =0  ; j < 3  ; j++  )
//         {
//             cout << "*";
//         }
//         cout << "\n";
//     }
    
//     return 0;
// }


// EXAMPLE 3
// /*
// Prints asterisks in even columns, dashes in odd columns
// -*-*- 
// -*-*- 
// -*-*-
// */

// #include <iostream>
// using namespace std;

// int main()
// {
//     int i,j;
//     for (i=0  ; i < 3 ; i++ )
//     {
//         for ( j=0  ; j<5  ; j++  )
//         {
//             // if j is even print *, if j is odd print _
//             if (j%2 == 1)  // if j is odd, then the column number is even
//             {
//                 cout << "*";
//             }
//             else
//             {
//                 cout << "_";
//             }
//         }
//         cout << "\n";
//     }
    
//     return 0;
// }