#include <iostream>

using namespace std;

#ifndef USER_H
#define USER_H

// where methods and member variables are defined
class User {
public:
    User();

    User(string username_input, int ratings_input[], int numRatings_input);

    string getUsername();

    void setUsername(string username_input);

    int getRatingAt(int index);

    bool setRatingAt(int index, int value);

    int getNumRatings();

    void setNumRatings(int index);

    int getSize();

private: //data members that are constantly being displayed; implicitly passed into function 
    string username;
    int ratings[200]; // number of elements should be size
    int numRatings; // number of books in database
    int size; // capacity of the ratings array [200]. constant
}; // <-- DON'T FORGET ";"

#endif
