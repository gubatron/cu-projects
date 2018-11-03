#include <iostream>
using namespace std;

// change problem: either double the initial 
// investment or at 13 years, whichever comes first

int main()
{  
   // what should we modify above while loop?
   const double RATE = 5;
   const double INITIAL_BALANCE = 10000;
   const double TARGET = 3 * INITIAL_BALANCE; // test INITIAL_BALANCE with value you can verify
   const int TARGET_YEAR = 50;
   double balance = INITIAL_BALANCE;
   int year = 0;
//   int z = 1; // flag --- if statements below

   // what should we modify in while loop?
   while (balance < TARGET && year < TARGET_YEAR) // a semicon after condition will never execute the loop. 
                                                  // it will be stuck in an infinite loop. NO SEMICONON AFTER!
//   while (z==1)
   {
      year++;
      double interest = balance * RATE / 100;
      balance = balance + interest;
      // you can add a cout statement here to check that test case works
      
      // if (balance >= TARGET)
      // { 
      //    z = 0;
      //    cout << "loop ended because" << balance;
      // }
      // if (year >= TARGET_YEAR)
      // {
      //    Z = 0;
      // }
   }

   cout << "The investment doubled after "
        << year << " years." << endl;

   return 0;
}

    