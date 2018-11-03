#include <iostream>
using namespace std;

// Function should printout/display "Good Morning" or "Good evening" 
// or "Good afternoon"
void wishGreetings(int hourOfDay);

main() {
    int hour;
    cout << "Please enter the current hour:";
    cin >> hour;
    
    wishGreetings(hour);
}


void wishGreetings(int hourOfDay) 
{
    if (hourOfDay == 0)
    {
        cout << "It's midnight!"<< endl;
    }
    if (hourOfDay < 12) 
    {
        cout << "Good Morning"<< endl;
    } 
    else if  (hourOfDay < 17) 
    {
        cout << "Good Afternoon"<< endl;
    } 
    else 
    {
        cout << "Good Evening"<< endl;
    }
}



// void wishGreetings(int hourOfDay) 
// {
//     if (hourOfDay < 12) 
//     {
//         cout << "Good Morning";
//     } 
//     else if  (hourOfDay < 17) 
//     {
//         cout << "Good Afternoon";
//     } 
//     else 
//     {
//         cout << "Good Evening";
//     }
// }