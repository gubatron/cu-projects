#include <iostream>
using namespace std;

// how do we know how many valies the user has entered?
// have them type Q or q to quit

/*Please enter values, Q to quit:
1 2 3 4 5 6 q
1
2
3
4
5
6 <== largest value*/

int main()
{  
   const int CAPACITY = 1000; // we know user won't type 1000 values
   double values[CAPACITY];
   double input;
   int array_size = 0;
   double largest = -10000000000;
   
   cout << "Please enter values (separated by spaces), Q to quit:" << endl;
   int i = 0;
   
   // need to remember how many elements we entered
   // this part fills the array
   while (cin >> input)  // as long as I can read a double from keyboard input, loop will run
                        // if you give it something other than a double (like Q) it will stop,
                           // so no need to make statement for Q
   {
      // check if we haven't entered more than 1000 numbers
      if (i < CAPACITY)
      {
         values[i] = input;
         i++;
      }
   }
   array_size = i;
   cout << array_size << endl;
   
   // this part finds the largest value in the array
   for (i=0; i < array_size; i++)
   {
      if (values[i] > largest) //largest holds max value so far
      {
         largest = values[i];
      }
   }
   //print them
   for (i=0; i < array_size; i++)
   {
      cout << values[i];
      if (values[i] == largest)
      {
         cout << " <== largest value";
      }
      cout << "\n";
   }
   
   return 0;
}