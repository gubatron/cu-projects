#include <iostream>
#include <strings>
#include <cmath>
#include <math.h>
using namespace std;


/**
 * functionname function ...
 *  if score <+ to dealers score == 0
 *  
 * Input parameters: 3 - 
 * Output: nothing
 * Returns: paid   // if nothing - void function
*/

int Payout(int dealerScore, int playerScore, int bet)
{
    if (playerScore <= dealerScore)
    {
        return 0;
    }
    else
    {
        return ((playerScore - dealerScore) * bet)/2;
    }
}

int main()
{
    // tests
    
    return 0;
}