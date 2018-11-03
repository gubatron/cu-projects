#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_SCORES = 5;

int main()
{
    int NUM_SCORES = 5;
    int score[NUM_SCORES];
    
    cout << "Enter 5 scores: \n";
    cin >> score[0];
    cin >> score[1];
    cin >> score[2];
    cin >> score[3];
    cin >> score[4];
    
    // copying to another array
    int newArray[NUM_SCORES];       // it has to be less than the number of elements NUM_SCORES
    for (int i = 0; i < 5; i++)
    {
        newArray[i] = score[i];
    }
    // now let's see if we copied correctly. Print newArray
    for (int i = 0; i < 5; i++)
    {
        cout << newArray[i] << endl;        // PRINTS THE INPUTED NUMBERS
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////    
    // the SUM of all scores
    int total = 0;
	for (int i = 0; i < NUM_SCORES; i++)
	{
	   total = total + score[i];            // SUMS ALL ELEMENTS
	   // cout << total << endl;    // gives the sum as it goes along. 1st + 2nd = x; x + 3rd = y, and so on
	}
	cout << "Total: " << total<< endl;
   
//////////////////////////////////////////////////////////////////////////////////////////////////////// 
    // Find average                         // SUMS AND DIVIDES BY NUMBER OF ELEMENTS (AVERAGE)
    cout << "Average: " << double(total)/NUM_SCORES << endl;  // cast as double to get decimal answer
 
////////////////////////////////////////////////////////////////////////////////////////////////////////   
    // Find PRODUCT of all scores
//     int total = 1;    //initiaize at 1, not zero or you'll get all zeros
// 	for (int i = 0; i < NUM_SCORES; i++)
// 	{
// 	   total = total * score[i];            // MULTIPLIES ALL ELEMENTS
// 	   // cout << total << endl;    // gives the product as it goes along. 1st * 2nd = x; x * 3rd = y, and so on
// 	}
// 	cout << "Total: " << total<< endl;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////   
    // Find max score
    int max = score[0];                     // GIVES THE HIGHEST OF ELEMENTS
    //int pos = 0;
    for (int i = 1; i < NUM_SCORES; i++)
    {
        if (score[i] > max)   
        {
            max = score[i];
            //pos = i;
        }
    }
    cout << "The highest score is " << max << endl;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Find the position of the highest score
    // int pos = 0;
    // bool found = false;
    // while (pos < NUM_SCORES && !found)      // GIVES INDEX OF HIGHEST ELEEMENT
    // {
    //     if (score[pos] == 10) // looking for 100
    //     {
    //         found = true;
    //     }
    //     else
    //     {
    //         pos++;
    //     }
    // }
    // if (pos < NUM_SCORES)
    {
        cout << "The index for 10 is: " << pos << endl;
    }
    // else
    {
        cout << "10 not found" << endl;
    }

    return 0;
}