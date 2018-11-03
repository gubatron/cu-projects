#include "Library.h"

//implementation file

Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}
// PROBLEM 1
////////////////////////////////////////////////////////////////////////////////
// SPLIT
int split (string str, char c, string array[])
{
if (str.length() == 0) {
     return 0;
 }
string word = "";
int count = 0;
str = str + c;
for (int i = 0; i < str.length(); i++)
{
    if (str[i] == c)
    {
        if (word.length() == 0)
            continue;
        array[count++] = word;
        word = "";
    } else {
        word = word + str[i];
    }
}
return count ;
}
//////////////////////////////////////////////////////////////////////////////// 
int Library::readBooks(string booksFile)
{
    if (numBooks == 200)
    {
        return numBooks;
    }
    
    ifstream in;
    in.open(booksFile);
    if (in.fail()){
        return -1;
    }
    string line = "";
    string store[2]; // array to store what split() finds; same size as booksData[]
    
    while (numBooks < 200 && getline(in, line))
    {
        if (line != "")
        {
            // use split() to separate each component at the ',' ; returns 2.
            split(line, ',', store); // says how many pieces it created (2)
            books[numBooks].setTitle(store[1]);
            books[numBooks].setAuthor(store[0]);
            numBooks++;
        }
    }
    
    in.close(); 
    return numBooks;
}

// PROBLEM 2
int Library::readRatings(string ratingsFile)
{
    if (numUsers == 200)
    {
        return numUsers;
    }
    
    ifstream in;
    in.open(ratingsFile);
    if (in.fail()){
        return -1;
    }
    string line = "";
    string store[2]; // array to store what split() finds 1st time
    string rate[200];  // array to store what split() finds 2nd time
    
    while (numUsers < 200 && getline(in, line))
    {
        if (line != "")
        {
            split(line, ',', store); // split() separates first time at the ','
            users[numUsers].setUsername(store[0]); // setUsername assigns username to value of input string
            cout << users[numUsers].getUsername() << "..." << endl; //getUsername return username
            int numCount = split(store[1], ' ', rate); // split() separates second time at the ' '
            for (int j = 0; j < numCount; j++)
            {   
                users[numUsers].setRatingAt(j, stoi(rate[j])); 
            }
            numUsers++;
        }
    }
    in.close();
    return numUsers;
}

// PROBLEM 3
void Library::printAllBooks() 
{
    if (numBooks >= 1)
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
    else
    {
        cout << "Database has not been fully initialized" << endl;
    }
    cout << endl;
}

// PROBLEM 4
////////////////////////////////////////////////////////////////////////////////    
//HELPER FUNCTION
string Library::lowercase(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower); // help problem 6; found online
    return s;
}

void Library::getFreshRatings(int ratings[])
{
    for (int i = 0; i < 200; i++)
    {
        ratings[i] = -1;
    }
}

int Library::HelperUserArraySearch(string username)
{
    string lUname = lowercase(username);
    for (int i = 0; i < numUsers; i++)
    {   
        if (lowercase(users[i].getUsername()) == lUname)
        {
            return i; // index of the username
        }
    }
    return -1;
}
////////////////////////////////////////////////////////////////////////////////    
int Library::getCountReadBooks(string username)
{   
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }

    int booksRead = 0;
    int userindex = HelperUserArraySearch(username);
    
    if (userindex == -1)
    {
        cout << username << " does not exist in the database" << endl;
        booksRead = -2;
    }
    
    for (int ratingindex = 0; ratingindex < numBooks; ratingindex++) // ratingindex = column
    {
        if (users[userindex].getRatingAt(ratingindex) > 0) 
        {
            booksRead++;
        }
    }
    
    return booksRead;
}

// PROBLEM 5
////////////////////////////////////////////////////////////////////////////////    
// HELPER FUNCTION
int Library::HelperTitleArraySearch(string bookTitle)
{
    for (int i = 0; i < numBooks; i++)
    {   
        if (books[i].getTitle() == bookTitle)
        {
            return i; // index of the book title
        }
    }
    return -1;
}
////////////////////////////////////////////////////////////////////////////////    
double Library::calcAvgRating(string bookTitle)
{
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return -1;
    }
    
    double titleindex_value = 0.0;
    double count = 0.0;
    
    int titleindex = HelperTitleArraySearch(bookTitle);
    
    if (titleindex == -1)
    {
        cout << bookTitle << " does not exist in the database" << endl;
        return -2;
    }
   
    for (int userindex = 0; userindex < numUsers; userindex++)  // userindex = row
    {
        int score = users[userindex].getRatingAt(titleindex);
        if (score > 0) 
        {
            titleindex_value += score;
            count++;
        }
    }
    if (count == 0)
    {
        return 0;
    }
    return titleindex_value/count;
}

// PROBLEM 6
bool Library::addUser(string username)
{ // HELPER FUNCTION THAT COMPARES USERNAMES
/**
 * start with empty library and imediately add an user
 * user created with a name but all ratings are -1
 * new hasn't read or rated any books so books read = 0 
 * as you add a user, increase number of users 
 * check for the name of the user
 * if name already exists, say invalid and don't add to database
 *      print message and convert all characters to lower case in order to be able to compare them
 *      method 2: function tolower function to convert every character to lowercase
 *          // compare each character individually and convert them to lowercase one at a time
            // for loop to go through each character; make sure same length
            // if not same lenght, exit?
            // make string temp and use for loop to go through each characters and convert the 
            // current character to a lowercase letter - use function tolower */
            
    if (numUsers == 200) //number of users is greater than 200
    {
        cout << "Database full" << endl;
        return false; 
    }
    
    if (HelperUserArraySearch(username) != -1)
    {
        cout << username << " already exists in the database" << endl;
        return false;
    }
    
    int ratings[200]; 
    getFreshRatings(ratings);
    User user(lowercase(username), ratings, sizeof(ratings));
    users[numUsers++] = user;
    return true;
} 

// PROBLEM 7
bool Library::checkOutBook(string username, string bookTitle, int newRating)
{
    /**
     * value for rating between 0 and 5
     * check if has been fully initialized
     * check if rating is updated. if not
     *      1. user not found; 2. title not found; 3. rating value not valid (must be 0-5)
     *      can print one, two or three at once (use if statements. no elses)
    */
}

// PROBLEM 8
void Library::viewRatings (string username)
{
    /**
     * if exists, print all ratings
     * if not rated any books, make a loop
     * if new user, user name not rated any books
     * use getCountRead - if 0, hasn't rated anything. Else print titles and ratings by traversing
    */
}

// PROBLEM 9
void Library::getRecommendations(string username)
{
    /**
     * 
    */
}