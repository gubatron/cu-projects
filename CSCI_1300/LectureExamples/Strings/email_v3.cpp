#include <iostream>
#include <string>
using namespace std;

// see if it has ".com"
int main()
{
    string email = "io@edu.com";
    // .com has four characters so have it look in chuncks of four 
    // io@e
    // o@ed
    // @edu
    // edu.
    // du.c
    // u.co
    // .com  <-- thats the one you want
    // com...garbage
    bool flag = false;
    int i = 0; 
    string mySubstring;
    
    string lookup = ".com";   // look for ".com"
    
    // email.substr( 0 , 4 ) // (starting index, no of characters)  - start at index 0 and look for 4
    for (int i = 0; i < email.length(); i++)
    {
        // get a substring
        email.substr( i , 4 ); // (starting index, no of characters)
        //beginning character keeps changing if it matches the lookup string
        if (email.substr( i , 4 ) == lookup)
        {
            flag = true; // turn the flag
        }
    }
    if (flag == true)
    {
        cout << "You have mail!";
    }
    return 0;
}


// int main()
// {
//     string email = "io@edu.com";
//     bool flag = false;
//     int i = 0;
//     string mySubstring;

//     string lookup = ".com";     // look for ".com"

//     for(i=0; i < email.length() - lookup.length() + 1; i++)
//     {
//         mySubstring = email.substr(i,lookup.length());
//         if (mySubstring == lookup)
//         {
//             flag = true;
//         }
//     }
//     if (flag == true)
//     {
//         cout << "You have mail!!!";
//     }
//     else
//     {
//         cout << "Invalid input";
//     }

//     return 0;
// }