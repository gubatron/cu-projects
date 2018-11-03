#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <math.h>
#include <fstream>
#include "Book.h"
#include "User.h"
using namespace std;

// nile8832:~/workspace/Homework/Hmwk7 $ g++ -std=c++11 Book.cpp User.cpp Hmwk7.cpp

// int test()
// {
//     Book book1 = Book("A Title", "An Author");
//     cout << book1.getTitle() << endl;
//     cout << book1.getAuthor() << endl;
//     book1.setTitle("Another title.");
//     cout << book1.getTitle() << endl;
//     cout << book1.getAuthor() << endl;
//     book1.setTitle("A Different Author");
//     cout << book1.getTitle() << endl;
//     cout << book1.getAuthor() << endl;
//     //book1.clear();
//     cout << book1.getTitle() << endl;
//     cout << book1.getAuthor() << endl;
    
//     return 0;
// }

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
// (1) PROBLEM 3
/** readBooks populates array of Book objects with the title and author data
 *      found int the file books.txt
 *  1) if file cannot open return -1
 *  2) for each line in the file
 *      - instantiate a Book object
 *      - fill in the author and title data members
 *      - append the object to your array of Book objects
 *  3) function must support multiple calls in a row upon testing
 *  4) Use ifstream, split(), and getline to read and parse data from the file.
 * @param: string : filename
 * @param: Book : booksData[]
 * @param: int : numBookObjects
 * @param: int : capacity (200)
 * @return: int : totNumBooks = i (in the system)
 */
int readBooks(string filename, Book booksData[], int numBookObjects, int capacity)
{
    ifstream in;
    in.open(filename);
    if (in.fail()){
        return -1;
    }
    string line = "";
    int i = numBookObjects;
    string store[capacity]; // array to store what split() finds; same size as booksData[]
    while (getline(in, line))
    {
        if(line != "")
        {
            // use split() to separate each component at the ',' ; returns 2.
            split(line, ',', store, capacity); // says how many pieces it created (2)
            booksData[i].setTitle(store[1]);
            booksData[i].setAuthor(store[0]);
            i++;
        }
    }
    return i;
    in.close(); 
}
                    
////////////////////////////////////////////////////////////////////////////////
// (2) PROBLEM 4
/** readRatings populates an array of User objects with the name and rating
 *      values from the file ratings.txt
 *      Each username represented in ratings.txt is followed by list of
 *      integers -- ratings of each book in books.txt
 *  1) if file cannot open return -1
 *  2) for each line in the file
 *      - instantiate a User object
 *      - fill in the username data member
 *      - set the size data member equal to the capacity parameter
 *      - populate the ratings array with the data in the file, and fill the rest
 *          of the values in the array with the value -1
 *      - store a count for the number of ratings that are not -1 in the numRatings
 *          data member
 *      - append the object to your array of User objects
 *  3) function must support multiple calls in a row upon testing
 *  4) Use ifstream, split(), and getline to read and parse data from the file.
 * @param: string : filename
 * @param: User : userData[]
 * @param: int : numUserObjects
 * @param: int : capacity (200)
 * @return: int : totNumUsers (as they are added to the system)
 * @print username of each user as they are added to the system
 */
int readRatings(string filename, User userData[], int numUserObjects, int capacity)
{
    ifstream in;
    in.open(filename);
    if (in.fail()){
        return -1;
    }
    string line = "";
    string store[2]; // array to store what split() finds 1st time
    string rate[200];  // array to store what split() finds 2nd time
    int usernumber = numUserObjects;
    while (getline(in, line))
    {
        if (line != "")
        {
            
            if (usernumber > capacity)
            {
                return capacity; // i is number of users in total
            }
            // split() separates each component into two pieces the first time at the ','
            split(line, ',', store, 2);
            userData[usernumber].setUsername(store[0]);
            cout << userData[usernumber].getUsername() << "..." << endl;
            // split() separates each component into many pieces the second time at the ' '
            int numCount = split(store[1], ' ', rate, 200);
            for (int j = 0; j < numCount; j++)
            {   
                userData[usernumber].setRatingAt(j, stoi(rate[j])); // where does the bool come in??
            }
            usernumber++;
        }
    }
    in.close();
    return usernumber;
}

//////////////////////////////////////////////////////////////////////////////// 
// (3) PROBLEM 5 
/** printAllBooks function displays contents of library
  *     1) if number of books is 0, print "No books are stored"
  *     2) else, print "Here is a list of books" followed by each book in format:
  *             <book title> by <book author>
  * @param: Book : booksData[]
  * @param: int : numBookObjects (currently stored in array of Book objects)
  * @return: nothing/void
  */
void printAllBooks(Book booksData[], int numBookObjects)
{
    if (numBookObjects >= 1)
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBookObjects; i++)
        {
            cout << booksData[i].getTitle() << " by " << booksData[i].getAuthor() << endl;
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
    int numBooks = 0; // (1) *******
    int numUsers = 0; // (2) *******
    int count = 0;
    double count1 = 0;
    
    string filename = ""; // (1)(2)
    string user = ""; // (4)
    string title = ""; // (5)
    
    Book booksData[200]; // (1)(3) *******
    User userData[200]; // (2) *******
    
    string titles[50]; // (1)(3)
    string authors[50]; // (1)(3)(5)
    string usernames[100]; // (5)
    int ratings[100][50]; // (2)(4)(5)

    // if(argc == 2){
    //     numBooks = readBooks("books.txt", booksData, numBooks, 200);
    //     numUsers = readRatings("ratings.txt", userData, numUsers, 200);
    //     cout << userData[0].getNumRatings() << endl;
    //     cout << userData[0].getRatingAt(0) << endl;
        
        
    //     return 0;
    // }


    while (choice != "6") 
    {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) 
            {
                case 1: // HW7 NUMBER 3 GOES HERE
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, filename);
                    //"books.txt"
                    numBooks = readBooks(filename, booksData, numBooks, 200);
                    
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

                case 2: // HW7 NUMBER 4 GOES HERE
                    // read user file
                    cout << "Enter a rating file name:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, filename);
                    //"ratings.txt"
                    numUsers = readRatings(filename, userData, numUsers, 200);
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

                case 3: // HW7 NUMBER 5 GOES HERE
                
                    // print the list of the books
                    
                    //////////////////////////////////////////////////////////////////////////
                    printAllBooks(booksData, numBooks);
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
                        cout << "The average rating for " << title << " is ";
                        cout << fixed << setprecision(2) << count1 << endl;
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