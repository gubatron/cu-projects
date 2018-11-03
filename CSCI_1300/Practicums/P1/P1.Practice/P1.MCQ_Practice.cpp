// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <cstdlib>
// #include <unistd.h>
// #include <stdio.h>
// using namespace std;

// * integer division
// * when one is double
// * function prototype
// * how to call a function (return or doesn't return value)
// * trace code 


//  * MCQ NOTES!
//  * 
// 1) Algorithm is a finite set of steps to sovlve a problem

// 2) cout << "This is the computer\n programming book\n";
//  == 
// This is the computer 
// programming book


// 3) C++ statements end with a semicolon; 

// 5) int number; == variable declaration

// 6) cout << "Hello Students/n"; == Hello Students/n
//     It has a / instead of a \

// 10? int x, y, z; 
//     y = 10; 
//     z = 3; 
//     x = y * z + 3;  // returns 33

// 11) int x; 
//     x = 0; 
//     x = x + 30;     // returns 30

// 12) int x; 
//     x = x + 30;     // returns garbage
 
// 13) float value; 
//     value = 33.5; 
//     cout << "value" << endl; // returns value

// 14) float x; 
//     x = 15/4;       // returns 3.0
    
// 15) int x; 
//     x = 15/4;       // returns 3
    
// 16) int x; 
//     x = 15 % 4;      // returns 3

// 17) float x; 
//     x = 3.0 / 4.0 + 3 + 2 / 5       // return 3.75
    
// 18) float x; 
//     x = 3.0 / 4.0 + (3 + 2 )/ 5     // return 1.75
    
// 21) If x has the value of 3, y has the value of -2, and w is 10, is the following condition true or false? 
//     if( x < 2 && w < y)
//     FALSE

// 22) y < x < z       ==    ((y < x) && (x < z))


// 23)
//  A     B   A || B
// true  true  true
// true  false false
// false true  false
// false false false
//                      || true if at least one of the operands is true

// 24)
// A      B   A && B 
// true  true  true
// true  false true
// false true  true
// false false false
//                       

// 24a)
// A      !A
// true   false
// false  true
//                      ! true if the operand is false


// 25) if x is 0, what is the value of (!x ==0)?           FALSE

// 26) (!(x<15 && y>=3))       ==      (x>=15 || y < 3)

// 27)  x is between 2 and 15 (including 2 and 15)     ==  (x >=2 && x <=15)

// 28) float x = 36.0; 
//     x = sqrt(x);
//     returns 6.0
    
// 29) cout << pow(4,2) << endl;
//     returns 16 -- 4^2
    
// 30) int value = 35;
//     return value + 5;
//     value += 10;             value+=10  ==> value + 10 
//     ANS == 50
    
// 31) Arguments to function are separated, by, commas

// 32) sqrt(sqrt(pow(2,4)));
//     returns 2

// 33) pow can be called with floating point values as well as integers

// 35) to call a void function 
//     ie. void displayOutput(int total);
//     called with -- displayOutput(myTotal);
//      Do not call with cout statement

// 36) void functions DON'T RETURN ANYTHING

// 38)
// int function()
// {
//   int number;
//   cout << "Please enter a number: ";
//   number = 5;
//   if (number > 20)
//   {
//       cout << "The number is LARGE!" << endl;
//   }
//   else
//   {
//       cout << "The number is SMALL!" << endl;
//   }
//   return 0;
// }
// int main()
// {
//     function();
// }
// ANSWER The number is SMALL!

// 39)
// int function()
// {
//   int age;
//   cout << "Please enter a number: ";
//   age = 25;
//   if (age > 30)
//   {      
//       cout << "You are wise!" << endl;
//   }
//   else
//   {
//       cout << "You have much to learn!" << endl;
//   }
//   return 0;
// }
// int main()
// {
//     function();
// }
// ANSWER == You have much to learn!

// 40)
// int x = 0;
// cout << "Enter number: ";
// cin >> x; // 25
// if (x < 100) 
// { 
//   x = x + 5; 
// }
// if (x < 500) 
// { 
//   x = x - 2; 
// }
// if (x > 10) 
// { 
//   x++; 
// }
// else 
// { 
//   x--; 
// }
// cout << x << endl;
// ANSWER == 29



// 41) In a switch statement, if a break statement is missing
//     Execution falls through the next branch until a break statement is reached
    
// 42)  !> is not an operator in C++

// 43) The switch statement is likea sequence of if statements that compares 
//      a single integer value against several constant alternatives

// 44) KidYoungAgedOld because no return statements or else's




// /**
// REVIEW SESSION
//  * formal parameter -- 42 = actual paramter but meaningOfLife() == formal

//  */