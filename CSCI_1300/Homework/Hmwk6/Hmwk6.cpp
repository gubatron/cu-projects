// CSCI1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation:<202> - John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// hmwk6 

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;


/* split function
 * the function to split the given string into array of string with respect to a delimiter
 *
 * @param : string , the string we are going to split
 * @param : char, the delimiter
 * @param : string array, the array of string we save after spliting
 * @param : int, size of the  indicates the maximum number of split-apart string pieces
*/
 int split (string str, char c, string array[], int size)
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
//////////////////////////////////////////////////////////////////////////

// (1)
/* readBooks function
 * the function reads a book file from the text and stores them 
 * in title array and author array
 *      reads line by line
 * @param: string, the name of the file to be read
 * @param: string array, titles
 * @param: string array, authors
 * @param: int, the number of books currently stored in the arrays
 * @param: int, capacity of the authors/titles arrays [assume to be 50]
 * @return: the total number of books in total
 */
int readBooks(string filename, string title[], string author[], int numBooks, int capacity)                     
{
    ifstream in;
    in.open(filename);
    if (in.fail()) // if the file open was unsuccessful
    {
        return -1;
    }
    // now that it's open, read through it
    string line = "";
    int i = 0;
    string store[capacity]; // array to store what split() finds; same size as title[] and author[]
    while (getline(in, line))
    {
        if(line != "")
        {
            // use split() to separate each component at the ',' ; returns 2.
            split(line, ',', store, capacity); // says how many pieces it created
            // <author> , <title>
            author[i] = store[0]; // author[] takes index 0 from split
            title[i] = store[1]; // title[] takes index 1 from split
            i++;
        }
    }
    return i;
    in.close(); 
}
//////////////////////////////////////////////////////////////////////////

// (2)
/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: string, the name of the file to be read
 * @param: string array, usernames
 * @param: 2D int array, list of ratings for each user (first index specifies user)
 * @param: int, the number of users currently stored in the array
 * @param: int, row capacity of the 2D array (convention: array[row][column]) [assume to be 100]
 * @param: int, column capacity of the 2D array [assume to be 50]
 * @return: the number of users in total
 */
int readRatings(string filename, string username[], int ratings[][50], int numUsers, int i, int j)
{
    ifstream in;
    in.open(filename);
    if (in.fail()) // if the file open was unsuccessful
    {
        return -1;
    }
    // now that it's open, read through it
    string line = "";
    string store[100]; // array to store what split() finds; same size as ratings [][50] with 100 numUsers
    string rate[100];
    int usernumber = 0;
    while (getline(in, line))
    {
        if (line != "")
        {
            if (usernumber > i)
            {
                return i; // i is number of users in total
            }
            // split() separates each component and retunrs 2. 
            split(line, ',', store, 100);     // 1st piece (0) into usernumber, 2nd piece (1) into j
            username[usernumber] = store[0];
            cout << store[0] << "..." << endl;
            split(store[1], ' ', rate, 100);
            for (j = 0; j < 50; j++) // assumed to be 50 books
            {
                ratings[usernumber][j] = stoi(rate[j]); // convert text into integer values and put them into array
            }
            usernumber++;
        }
    }
    return usernumber;
    in.close();
}
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
 // OTHER HELPER FUNCTIONS
 
// (3)
 /* printAllBooks function
  * displays contents of library
  * 
  * @param: string array: titles
  * @param: string array: authors
  * @param: int: number of books
  * @print: list of books or no books
  */
void printAllBooks(string titles[], string authors[], int numBooks)
{
    if (numBooks != 0 && numBooks != -1)
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            cout << titles[i] << " by " << authors[i] << endl;
        }
    }
    else
    {
        cout << "No books are stored" << endl;
    }
    cout << endl;
}
//////////////////////////////////////////////////////////////////////////

// (4a)
/* HelperUserArraySearch function
 * searches user array for a particular username and returns its index
 * @param: string array: user
 * @param: int size of array
 * @return: int: index
*/
int HelperUserArraySearch(string username, string all_users[], int size)
{
    for (int i = 0; i < size; i++)
    {   
        if (all_users[i] == username)
        {
            return i; // index of the username
        }
    }
    cout << username << " does not exist in the database" << endl;
    return -1;
}

// (4)
 /* getUserReadCount
  * determines how many books a particular user has read and reviewed
  * 
  * @param: string : username
  * @param: string: username for whom we want a read counts
  * @param: string array: all users
  * @param: 2D int array: list of all ratings, one row for each user
  * @param: int: number of users in the arrays
  * @param: int: number of books accounted for in the 2D array
  * @return: int: number of books read/reviewed by specific user
  * 
  * NOTE: Write a helper function that searches the user array for a
  * particular username and returns its index -- use a for loop
  */
int getUserReadCount(string username, string all_users[], int all_ratings[][50], int numUsers, int numBooks)
{
    int booksRead = 0;
    int userindex = HelperUserArraySearch(username, all_users, numUsers);
    
    if (userindex != -1)
    {
        for (int ratingindex = 0; ratingindex < numBooks; ratingindex++) // ratingindex = column
        {
            if (all_ratings[userindex][ratingindex] > 0) 
            {
                booksRead++;
            }
        }
    }
    else
    {
        booksRead = -1;
    }
    return booksRead;
}   
//////////////////////////////////////////////////////////////////////////

// // (5a)
/* HelperTitleArraySearch furncion
 * searches titles array for a particular book and returns its index
 * @param: string : username
 * @param: string array: book
 * @param: int size of array
 * @return: int: index
*/
int HelperTitleArraySearch(string title, string all_titles[], int size)
{
    for (int i = 0; i < size; i++)
    {   
        if (all_titles[i] == title)
        {
            return i; // index of the book title
        }
    }
    cout << title << " does not exist in our database" << endl;
    return -1;
}

// (5)
 /*calcAvgRating calculates mean (average) rating for a particular book
  * 
  * @param string: book title for which you want the average rating
  * @param string array: titles
  * @param 2D int array: list of ratings for each user (same comment here)
  * @param int: number of users in the arrays
  * @param int: number of books accounted for in the 2D array
  * @return double: average rating of th specified book 
  * 
  * NOTE: Write a helper function that searches the titles array for a
  * particular book and returns its index. -- use a for loop
  */
double calcAvgRating(string title, string all_titles[], int all_ratings[][50], int numUsers, int numBooks)
{
    double titleindex_value = 0.0;
    double avg = 0.0;
    double count = 0.0;
    
    int titleindex = HelperTitleArraySearch(title, all_titles, numBooks);
    if (titleindex != -1)
    {
        for (int userindex = 0; userindex < numUsers; userindex++)  // userindex = row
        {
            double score = all_ratings[userindex][titleindex];
            if (score > 0) 
            {
                titleindex_value += score;
                count++;
            }
        }
        avg = titleindex_value/count; 
    }
    else
    {
        avg = -1;
    } 
    return avg;
}
    
//////////////////////////////////////////////////////////////////////////



/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}

 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
    string choice;
    int numBooks = 0; // (1)
    int numUsers = 0; // (2)
    int count = 0; // (4)
    double count1 = 0; // (5)
    
    string filename = ""; // (1)(2)
    string user = ""; // (4)
    string title = ""; // (5)
    
    string titles[50]; // (1)(3)
    string authors[50]; // (1)(3)(5)
    string usernames[100]; // (5)
    int ratings[100][50]; // (2)(4)(5)

    while (choice != "6") 
    {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) 
            {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, filename);
                    //"books.txt"
                    numBooks = readBooks(filename , titles, authors, numBooks, 50);
                    if (numBooks != -1)
                    {
                        cout << "Total books in the database: " << numBooks << endl;
                    }
                    else
                    {
                        cout << "No books saved to the database" << endl;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    
                    
                    cout << endl;
                    break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, filename);
                    //"ratings.txt"
                    numUsers = readRatings(filename , usernames, ratings, numUsers, 100, 50);
                    if (numUsers != -1)
                    {
                        cout << "Total users in the database: " << numUsers << endl;
                    }
                    else
                    {
                        cout << "No users saved to database" << endl;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    break;

                case 3:
                    // print the list of the books
                    
                    //////////////////////////////////////////////////////////////////////////
                    printAllBooks(titles, authors, numBooks);
                    //////////////////////////////////////////////////////////////////////////
                    
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, user);
                    count = getUserReadCount(user, usernames, ratings, numUsers, numBooks);
                    if (count != -1)
                    {
                        cout << user << " rated " << count << " books" << endl;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, title);
                    count1 = calcAvgRating(title, titles, ratings, numUsers, numBooks);
                    if (count1 != -1)
                    {
                        cout << "The average rating for " << title << " is " << fixed << setprecision(2) << count1 << endl;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    break;
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl << endl;
            }
    }
    return 0;
}