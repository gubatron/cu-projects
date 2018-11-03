#include <iostream>
#include <strings>
#include <cmath>
#include <math.h>
using namespace std;


/**
 * functionname function ...
 * 
 * Input parameters: 
 * Output: 
 * Returns:    // if nothing - void function
*/

void cardSuit (int suitNum){
    switch (suitNum) {
        case 0: cout << "Suit " << suitNum << ": " << "Clubs" << endl;
        break;
        case 1: cout << "Suit " << suitNum << ": " << "Diamonds" << endl;
        break;
        case 2: cout << "Suit " << suitNum << ": " << "Spades" << endl;
        break;
        case 3: cout << "Suit " << suitNum << ": " << "Hearts" << endl;
        break;
        default: cout << "Suit " << suitNum << ": " << "Invalid" << endl;
    }
}

int main()
{
    // tests
    
    return 0;
}