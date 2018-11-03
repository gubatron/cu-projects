#include <iostream>
using namespace std;

int main()
{  
   const int CAPACITY = 10; // can be any value  -- constants are all CAPS. 
   double values[CAPACITY]; // declaration
   //int size = 10; // not a constant! so some compilers will not let you use a non-constant for an array
   
   for (int i = 0; i < CAPACITY; i++) // Creates array of integers w every value set to zero
   //for (int i = 0; i < size; i++)  // <-- This is wrong (read li. 8)
   {
      //values[i] = 0;  // first set to zero and then, li. 15
      values [i] = i+1; // gives me increasing
      cout << values[i] << endl; // print values in array
   }
   return 0;
}