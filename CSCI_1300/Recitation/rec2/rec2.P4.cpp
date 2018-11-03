#include <iostream>
using namespace std;

/**
 * This function called classGreeting asks for an integer argument
 * It prints the greeting "Hello, CS (integer) Worl56d!" to the user
*/

int classGreeting(int number)
{
    //cout << "Enter a CS course number: " << endl;
    cin >> number;
    cout << "Hello, CS " << number << " World!" << endl;
    return 0;
}

/**
int main()
{
    int number;
    classGreeting(number);
    return 0;
}
*/