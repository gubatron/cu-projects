        
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // How many spoonfuls of cereal should I eat every morning
    // 145 fruit loops
    // 7 fruit loops in a spoon
    
    int spoon = 7;
    int target_fruit_loops = 145;
    int total = 0;
    int counter = 0;
    
    while ( total <= target_fruit_loops)  // haven't eaten more than 145 yet
    {
        // eat one more spoon
        total = total + spoon;
        // increment counter
        counter = counter + 1;
        //cout << "Yum!" << endl;
    }
    cout << "number of spoons: " << counter << endl;
    return 0;
}

    