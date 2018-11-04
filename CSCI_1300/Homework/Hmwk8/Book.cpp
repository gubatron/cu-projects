#include "Book.h"

//implementation file 

Book::Book() {
    title = "";
    author = "";
}

Book::Book(string title_input, string author_input) {
    title = title_input;
    author = author_input;
}

// add class name between name and type of function
string Book::getTitle() {
    return title;
}

void Book::setTitle(string title_input) {
    title = title_input;
}

string Book::getAuthor() {
    return author;
}

void Book::setAuthor(string author_input) {
    author = author_input;
}
