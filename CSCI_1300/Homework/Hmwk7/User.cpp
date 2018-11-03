#include "User.h" // header file "User.h"

//implementation file 

User::User()
{
    username = "";
    numRatings = 0;
    size = 200;
    for (int i = 0; i < size; i++)
    {
        ratings[i] = -1;
    }
}
// only passes 3 because size is fixed to 200
User::User(string username_input, int ratings_input[], int numRatings_input)
{
    username = username_input;
    for (int i = 0; i < 200; i++)
    {
        ratings[i] = ratings_input[i];
    }
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
    if (index >= numRatings || index < 0)
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
    if (index >= 0 && index < 200 && value >= 0 && value <= 5)
    {
        if(ratings[index] == -1)
        {
            numRatings++;
        }
        ratings[index] = value;
        return true;   
    }
    else
    {
        return false;
    }
}

int User::getNumRatings()
{
    return numRatings;
}

void User::setNumRatings(int numRatings_input)
{
    numRatings = numRatings_input;
}

int User::getSize() //const
{
    return size;
}