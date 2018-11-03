#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

/**
 * printTotalMedals function takes an array for olympic sports and arrays for 
 * gold, silver, and bronze medals and prints the total number of medals by 
 * discipline.
 *  - if size < 1, print "Invalid size. Size must be at least 1."
 * @param string : disciplines[]
 *        int : gold[]
 *        int : silver[]
 *        int : bronze[]
 *        int : size
 * @output
 * @return
 */ 

void printTotalMedals(string disciplines[], int gold[], int silver[], int bronze[], int size)
{
    int tot_gold = 0;
    int tot_silver = 0;
    int tot_bronze = 0;
    int medal_sum[size];
    
    if (size < 1)
    {
        cout << "Invalid size. Size must be at least 1." << endl;
    }
    
    // going through array and giving them values
    for (int i = 0; i < size; i++)
    {
        medal_sum[i] = gold[i] + silver[i] + bronze[i];
        cout << disciplines[i] << ": " << medal_sum[i] << endl;
    }
}
