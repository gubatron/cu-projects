#include "User.h" // header file "User.h"

//implementation file 

User::User()
{
    username = "";
    ratings[size] = -1;
    numRatings = 0;
    size = 200;
}
// only passes 3 because size is fixed to 200
User::User(string username_input, int ratings[], int numRatings_input)
{
    username = username_input;
    ratings[200]; //what do I equate the array to??
    numRatings = numRatings_input;
}

string User::getUsername()
{
    return username;
}

void User::setUsername(string username_input)
{
    username = username_input;
}

int User::getRatingAt(int index)
{
    if (index > 200)
    {
        return -1; 
    }
    else
    {
        return ratings[index];
    }
}

bool User::setRatingAt(int index, int value)
{
    if (index < 200 && value > 0 && value < 5)
    {
        return true;   
    }
    else
    {
        return false;
    }
}

int User::getNumRatings(int numRatings_input)
{
    return numRatings_input;
}

void User::setNumRatings(int numRatings_input)
{
    numRatings = numRatings_input;
}

int User::getSize(int size) //const
{
    return size;
}