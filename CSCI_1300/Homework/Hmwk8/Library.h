#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> // for transform function (6)

#include "Book.h"
#include "User.h"
using namespace std; 

#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{
public:
    Library();  // sets both numBooks and numUsers to value 0
    
    int readBooks(string booksFile);            // populates books[] with string (name of file to be read); returns total num books in books[] as int
    int readRatings(string ratingsFile);        // popluates users[] with string (name of file to be read); returns total number of users in users[] as int
    void printAllBooks();  // prints all books stored in books[]; void
    string lowercase(string s); // HELPER
    void getFreshRatings(int ratings[]); // HELPER
    int HelperUserArraySearch(string username);  // HELPER
    int getCountReadBooks(string username);     // takes string (username); returns number of books read by that user as an integer
    int HelperTitleArraySearch(string bookTitle); // HELPER
    double calcAvgRating(string bookTitle);     // takes string (title of book); returns avg rating of specified book as DOUBLE
    bool addUser(string username);              // takes string (username); returns TRUE if username is successfully added to database. FALSE otherwise
    bool checkOutBook(string username, string bookTitle, int newRating); //takes username, title of book, new rating respectively. Return TRUE if rating successfully updated. FALSE otherwise
    void viewRatings(string username);         // takes string (username); prints all books a user has provided ratings for; void
    User getUser(string username);  // returns a copy of the user
    int ssd(User a, User b);    // return SSD score between two users
    void getRecommendations(string username);   // takes string username; prints first 5 book recommendations from most similar (other) user; void
    
private:
    Book books[200];   // array of Book objects
    User users[200];   // array of User objects
    int numBooks;   // Number of books in the database (library)
    int numUsers;   // Number of users in the database (library)
    int sizeBook;   // capacity of books array (200) constant
    int sizeUser;   // capacity of users array (200) constant
    
};
#endif

// in library.h int size user = 200