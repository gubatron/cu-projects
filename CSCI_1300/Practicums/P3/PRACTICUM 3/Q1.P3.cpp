#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

// A normal resting heart rate for newborns (0 - 1 months old) is in the range [70, 190] bpm including both the values.

// Write a function printAbnormalHeartRates that takes in two arrays, one of patient names and one of heart rates and prints out the patients with abnormal heart rates.

// Your function should have three parameters in this order:

// an array of strings patients
// an array of ints for heart_rate
// an integer numPatients (the number of elements in the array)
// Your function should not return anything.

// Your function should print out all abnormal patients in the format below:


void printAbnormalHeartRates(string patients[], int heart_rate[], int numPatients)
{
    int linecount = 0;
        for (int j = 0; j < numPatients; j++)
        {
            if (heart_rate[j] < 70 || heart_rate[j] > 190)
            {
                for (int i = 0; i < numPatients; i++)
                {
                    if (i == j)
                    {
                        cout << patients[i] << " " << heart_rate[j] << endl;
                        linecount++;
                        if (linecount > i)
                            {
                                i++;
                            }
                    }
                }        
            } 
        }    
}




// for (int i = smartkids; i <= smartkids; i++)
//                 {
//                     second_filestream << store[0] << ", " << store[2] << endl;
//                     linecount++;
//                     if (linecount > i)
//                     {
//                         i++;
//                     }
//                 }


int main()
{
    string patients[] ={"Joe", "Jack", "Amy", "Bob"};
    int heart_rate[] = {90, 60, 200, 100};
    printAbnormalHeartRates(patients, heart_rate, 4);
}
