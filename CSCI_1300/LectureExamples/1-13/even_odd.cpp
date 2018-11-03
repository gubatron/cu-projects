        
#include <iostream>
using namespace std;


/*
Function to know if given number is even or odd.
Parameters: An integer number
Return: No return
Algorithm:
    1. Get the number as parameter.
    2. Check if the remainder by dividing number by 2 is 0.
        2a. If yes:
            print "Number is even."
        2b. If no:
            print "Number is odd."
*/
void isNumberEven(int num) {
    
    if (num % 2 == 0) 
    {
        cout << "Number is even.";
    } else 
    {
        cout << "Number is odd.";
    }
}

main() {
    int number;
    cout << "Please enter a number:";
    cin >> number;
    
    isNumberEven(number);
}

    