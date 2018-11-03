#include <iostream>
#include <string>
using namespace std;


/**
 * GolfName function gives the golf name for a given score
 *      Scores -2, -1, 0, 1, 2, and 3, all have names
 * Input parameters: score (int)
 * Output: nothing
 * Returns: term (string)
*/

string GolfName (int score)
{      
    switch (score)
    {
        case -2:
                return "EAGLE"; //<< endl;  
                break;
        // case -1: 
        //         return "BIRDIE";// << endl; 
        //         break;
        // case 0: 
        //         return "PAR" ;//<< endl;
        //         break;
        // case 1: 
        //         return "BOGIE";// << endl; 
        //         break;
        // case 2: 
        //         return "DOUBLE BOGIE" ;//<< endl; 
        //         break;
        // case 3: 
        //         return "TRIPLE BOGIE"; //<< endl; 
        //         break;
        default: return "NO COMMENT"; //<< endl;
    }
}

    
int main ()
{
    cout << GolfName(-2); 
    cout << GolfName(2);
    cout << GolfName(99); 
}