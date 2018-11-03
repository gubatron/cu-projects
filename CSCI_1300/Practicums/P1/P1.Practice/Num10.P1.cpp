#include <iostream>
#include <iomanip>
using namespace std;


/**
 * LeavesPerTree function 
 *      pounds always positive
 *      Last year university estimated 10,000 leaves per tree
 *      1. each leaf weighs 0.001 pounds
 *      2. there are 1,031 trees on campus
 *      3. if the trees are producing more laves per tree,
 *      print "More leaves than last year"
 * Input parameters: pounds (double) -- pounds of leaves raked up
 * Output: number of leaves per tree
 * Returns: nothing   // void function
*/

void LeavesPerTree(double poundLeaves)
{
    double numLeaves;
    numLeaves = poundLeaves / 0.001;
    double leavesPer;
    leavesPer =  numLeaves / 1031;
    if ((leavesPer >= 0) && (leavesPer <= 10000))
    {
        cout << leavesPer << endl;
    }
    else
    {
        cout << leavesPer << endl;
        cout << "More leaves than last year" << endl;
    }
}

int main()
{
    LeavesPerTree(10000);
}

// PROBLEM STATEMENT
// The university wants to know if their trees are producing more leaves on average since last year based on how many leaves they rake up this fall.

// Write a function LeavesPerTree which takes a single input argument, the pounds of leaves the university raked up, as a double argument . Using the input value, the function will calculate the leaves per tree and print if it is more than last year.


// Your function should be named LeavesPerTree

// Your function takes one input argument: the pounds of leaves raked, as a double (assume always positive)

// Your function does not have a return value

// Your function prints/displays/outputs the number of leaves per tree and, if the trees are producing more leaves per tree, it also displays "More leaves than last year", on the next line.

// Last year the university estimated 10,000 leaves per tree.

// Each leaf weighs 0.001 pounds and there are 1,031 trees on campus.


// Example output:

// If the function is called with 100,000 as the input argument:  

// 96993.2

// More leaves than last year



// If the function is called with 10,000 as the input argument:  

// 9699.32