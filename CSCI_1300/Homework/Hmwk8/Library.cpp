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
        return -2;
    }
    
    for (int ratingindex = 0; ratingindex < numBooks; ratingindex++) // ratingindex = column
    {
        int rating = users[userindex].getRatingAt(ratingindex);
        if (rating > 0 && rating < 6) 
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
    string lTitle = lowercase(bookTitle);
    for (int i = 0; i < numBooks; i++)
    {   
        if (lowercase(books[i].getTitle()) == lTitle)
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
    
    double titleScore = 0.0;
    double count = 0.0;
    
    int titleindex = HelperTitleArraySearch(bookTitle);
    
    if (titleindex == -1)
    {
        cout << bookTitle << " does not exist in the database" << endl;
        return -2;
    }
    
    for (int userindex = 0; userindex < numUsers; userindex++)  // userindex = row
    {
        // for a userindex, gets rating of a book at the index from the helper
        int score = users[userindex].getRatingAt(titleindex); 
        if (score > 0 && score <= 5) 
        {
            titleScore += score;
            count++;
        }
    }

    if (titleScore == 0 || count == 0)
    {
        return 0;
    }
    return titleScore/count;
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
    User user(username, ratings, 0);
    users[numUsers++] = user; // increase numUsers after line is executed
    return true;
} 

// PROBLEM 7
bool Library::checkOutBook(string username, string bookTitle, int newRating)
{
    bool errored = false; // reverse logic
    /**
     * value for rating between 0 and 5
     * check if has been fully initialized
     * check if rating is updated. if not
     *      1. user not found; 2. title not found; 3. rating value not valid (must be 0-5)
     *      can print one, two or three at once (use if statements. no elses)
    */
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return false;
    }
    
    int userindex = HelperUserArraySearch(username);
    if (userindex == -1)
    {
        cout << username << " does not exist in the database" << endl;
        errored = true;
    }
    
    int titleindex = HelperTitleArraySearch(bookTitle);
    if (titleindex == -1)
    {
        cout << bookTitle << " does not exist in the database" << endl;
        errored = true;
    }
    
    if (newRating < 0 || newRating > 5)
    {
        cout << newRating << " is not valid" << endl;
        errored = true;
    }
    
    // if nothing goes wrong, update rating
    if (!errored)
    {
        // These 2 lines only update a copy of the user in the array
        //User user = users[userindex];
        //user.setRatingAt(titleindex, newRating);

        // then we'd have to update the users array with the updated copy
        // users[userindex] = u;
        
        // but why make an unnecessary copy? (inneficient)
        // just update the user in the array directly!!!
        users[userindex].setRatingAt(titleindex, newRating);
    }
    return !errored;
}

// PROBLEM 8
void Library::viewRatings(string username)
{
    /**
     * if exists, print all ratings
     * if not rated any books, make a loop
     * if new user, user name not rated any books
     * use getCountRead - if 0, hasn't rated anything. Else print titles and ratings by traversing
    */
    
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }
    
    int userindex = HelperUserArraySearch(username);
    if (userindex == -1)
    {
        cout << username << " does not exist in the database" << endl;
        return;
    }
    
    User user = users[userindex];
    if (user.getNumRatings() == 0)
    {
        cout << user.getUsername() << " has not rated any books yet" << endl;
        return;
    }
    
    // if read
    cout << "Here are the books that " << user.getUsername() << " rated" << endl;
    for (int i = 0; i < 200; i++)
    {
        int rating = user.getRatingAt(i);
        if (rating > 0 && rating < 6)
        {
            Book book = books[i];
            cout << "Title : " << book.getTitle() << endl;
            cout << "Rating : " << user.getRatingAt(i) << endl;
            cout << "-----" << endl;
        }
    }
}

// PROBLEM 9
////////////////////////////////////////////////////////////////////////////////
User Library::getUser(string username)
{
    return users[HelperUserArraySearch(username)];
}

int Library::ssd(User a, User b)
{
    int result = 0;
    for (int i = 0; i < 200; i++)
    {
        if (a.getRatingAt(i) == -1 || b.getRatingAt(i) == -1)
        {
            continue;
        }
        result += pow((a.getRatingAt(i) - b.getRatingAt(i)),2);
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////
void Library::getRecommendations(string username)
{
    /*
     * generate recommendations for user based on user's similarity ratins with others
     * if user is a new user, ignore them - use getCountReadBooks to weed them out 
    */
    
    if (numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }
    
    int userindex = HelperUserArraySearch(username);
    if (userindex == -1)
    {
        cout << username << " does not exist in the database" << endl;
        return;
    }
    
    // new user cannot be most similar user
    User user = users[userindex];
    int numReadBooks = getCountReadBooks(username);
    bool isNewUser = numReadBooks == 0;
    // if (isNewUser)
    // {
    //     cout << "There are no recommendations for " << user.getUsername() << " at the present" << endl;
    //     return;
    // }
    
    // compare SSD values for all users 
    int bestSSD = 999999; // initialized to big value to make comparison easier for first iteration 
    int bestUserIndex = -1; // the index of the best user found so far given the bestSSD
    for (int i = 0; i < numUsers; i++)
    {
        if (i == userindex)
        {
            continue; // don't compare against same user
        }
        if (getCountReadBooks(users[i].getUsername()) == 0)
        {
            continue; // don't compare against new users
        }
        
        int currentSSD = ssd(user,users[i]);
        if (currentSSD < bestSSD)
        {
            bestSSD = currentSSD;
            bestUserIndex = i;
        }
    }
    if (bestUserIndex == -1) // no one else has read any books
    {
        cout << "There are no recommendations for " << user.getUsername() << " at the present" << endl;
        return;
    }
    
    // I have someone similar, let's see if they have books rated from 3 to 5
    User bestUser = users[bestUserIndex];
    int num_recommendations = 0;
    string recommendations[200];
    for (int i = 0; i < 200 && num_recommendations < 5; i++)
    {
        if (user.getRatingAt(i) != 0)
        {
            continue;
        }
        int rating = bestUser.getRatingAt(i);
        if (rating > 2 && rating < 6)
        {
            // print only if we have > 1 rec
            recommendations[num_recommendations++] = books[i].getTitle() + " by " + books[i].getAuthor();
        }
    }
    
    if (num_recommendations == 0) // best match has no books to recommend
    {
        cout << "There are no recommendations for " << user.getUsername() << " at the present" << endl;
        return;
    }
    
    if (num_recommendations > 0) // at least 1 recommendation
    {
        sort(recommendations, recommendations + num_recommendations);
        
        cout << "Here are the list of recommendations:" << endl;
        for (int i = 0; i < num_recommendations; i++)
        {
            cout << recommendations[i] << endl;
            
        }
    }
}