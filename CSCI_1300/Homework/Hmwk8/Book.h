#include <iostream>
#include <string>

using namespace std;

#ifndef BOOK_H
#define BOOK_H

// where methods and member variables are defined
class Book {
public:
    Book();

    Book(string title_input, string author_input);

    string getTitle();

    void setTitle(string title_input);

    string getAuthor();

    void setAuthor(string author_input);


private: //data members that are constantly being displayed; implicitly passed into function 
    string title; // each book has a title
    string author;// each book has an author
}; // <-- DON'T FORGET ";"

#endif
