#pragma once // makes stuff in header included once in .h file
#include <iostream>
#include <string>

using namespace std;  
// where methods and member variables are defined
class Book
{
public:
   Book();
   Book(string title_input, string author_input);
   string getTitle();
   void setTitle(string title_input);
   string getAuthor();
   void setAuthor(string author_input);
 

private: //data members that are constantly being displayed; implicitly passed into function 
   // each book has a title
   string title;
   // each book has an author
   string author;
}; // <-- DON'T FORGET ";"


// // constructors have same name as class; a function that creates an object
//    // default constructor : sets both title and author to empty strings
//    Book();
   
//    // parameterized constructor : takes two strings for initializing title and author, in this order
//    Book(string title, string author);
   
//    // @return title as a string
//    string getTitle();
   
//    // assigns title the value of the input string
//    void setTitle(string title);
   
//    // @return author as a string
//    string getAuthor();
   
//    // assigns author the value of the input string
//    void setAuthor(string author);
 