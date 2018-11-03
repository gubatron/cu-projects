#include <iostream>
using namespace std;

/**
 * Not a function. Declaring and populating
 *      three arrays in main():
● temps - an array of 10 floating point numbers initialized with -459.67 (absolute
zero in Fahrenheit)
● colors - an array of the strings “Red”, “Blue”, “Green”, “Cyan”, and “Magenta”, in
that order.
● sequence - an array of the first 100 positive integers in order; 1, 2, 3, 4, … etc.

*/

int main()
{
    float temps[10] = {-459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67, -459.67};
    
    string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
   
    int sequence[100];
    for(int i = 0; i < 100; i++)
    {
        sequence[i] = i+1;
        cout << sequence[i] << " ";
    }
    
    
    
    return 0;
}