#pragma once // makes stuff in header included once in .h file
#include <iostream>
using namespace std; 

// where methods and member variables are defined
class User
{
public:
   User();
   User(string username_input, int ratings[], int numRatings_input);
   string getUsername(); 
   void setUsername(string username_input);
   int getRatingAt(int index);
   bool setRatingAt(int index, int value); // bool or void?
   int getNumRatings(int numRatings_input); // should it be int?
   void setNumRatings(int index); 
   int getSize(int size);
   
private: //data members that are constantly being displayed; implicitly passed into function 
   string username;
   int ratings[200]; // number of elements should be size
   int numRatings; // number of books in database
   int size; // capacity of the ratings array [200]. constant
}; // <-- DON'T FORGET ";"


   // // default constructor : sets username to empty string, numRatings to 0, size to 200, 
   // //                       and all elements of ratings array to -1
   // User();
   
   // // parameterized constructor : takes a string, an array of integers, and one integer 
   // //                             for initializing username, ratings, and numRatings, respectively.
   // //                             Make sure the value passed into the constructor for numRatings 
   // //                             doesn't exeed the value of the data member size
   // User(string username, int ratings[], int numRatings);
   
   // // @return username
   // string getUsername(); // 
   
   // // assigns username the value of the input string
   // void setUsername(string username);
   
   // // @param: int index. 
   // // @returns rating stored at specified index. If index is larger than size of ratings array, return -1
   // int getRatingAt(int index);
   
   // // @param: int index, int value
   // // sets rating to value at specified index, if index is within bounds of array and value is btwn 0 and 5. 
   // // @return boolean, true if rating is successfully updated, false otherwise
   // bool setRatingAt(int index, int value);
   
   // // @return numRatings
   // getNumRatings(numRatings) // WHAT IS THE PARAMETER?
   
   // // assigns numRatings the value of the input int
   // void setNumRatings(int index); // IS INDEX CORRECT?
   
   // // @return size
   // getSize(); 
   
