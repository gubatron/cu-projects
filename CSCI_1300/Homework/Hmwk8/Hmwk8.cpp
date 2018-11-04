// CSCI1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: <202> – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// hmwk8 / Project2

#include <iostream>
#include <iomanip>

#ifdef __APPLE__ // Mac build

#include "User.h"
#include "Library.h"

#else // Moodle
#include "Book.cpp"
#include "User.cpp"
#include "Library.cpp"
#endif
using namespace std;


/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu() {
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read book file" << endl;
    cout << "2. Read user file" << endl;
    cout << "3. Print book list" << endl;
    cout << "4. Find number of books user rated" << endl;
    cout << "5. Get average rating" << endl;
    cout << "6. Add a User" << endl;
    cout << "7. Checkout a book" << endl;
    cout << "8. View Ratings" << endl;
    cout << "9. Get Recommendations" << endl;
    cout << "10. Quit" << endl;
    //5cout << "11. Automated test" << endl;
}


int main(int argc, char const *argv[]) {
    //////////////////////////////////////////////////////////////////////////
    // Your code here. Call the appropriate function(s).

    Library library;

    string choice;
    int nb = 0; // number of books (1) 
    int nu = 0; // number of users (2)
    int count = 0; // (4)
    double count1 = 0; // (5)

    string filename; // (1)(2)
    string username; // (4)(6)(8)
    string title; // (5)(7)
    int rating = 0; // (7)

    User a, b; //(11)   TEST


    while (choice != "10") {
        displayMenu();
        getline(cin, choice);
        switch (stoi(choice)) {
            case 1:
                // read book file
                cout << "Enter a book file name:" << endl;

                //////////////////////////////////////////////////////////////////////////
                getline(cin, filename); //read from file
                //"books.txt"
                nb = library.readBooks(filename);

                if (nb != -1) {
                    cout << "Total books in the database: " << nb << endl;
                } else {
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
                nu = library.readRatings(filename);
                if (nu != -1) {
                    cout << "Total users in the database: " << nu << endl;
                } else {
                    cout << "No users saved to database" << endl;
                }
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 3:
                // print the list of the books

                //////////////////////////////////////////////////////////////////////////
                library.printAllBooks();
                //////////////////////////////////////////////////////////////////////////
                break;

            case 4:
                // find the number of books user read
                cout << "Enter username:" << endl;

                //////////////////////////////////////////////////////////////////////////
                getline(cin, username);
                count = library.getCountReadBooks(username);
                if (count != -1) {
                    cout << username << " rated " << count << " books" << endl;
                }
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 5:
                // get the average rating of the book
                cout << "Enter book title:" << endl;

                //////////////////////////////////////////////////////////////////////////
                getline(cin, title);
                count1 = library.calcAvgRating(title);
                if (count1 != -1) {
                    cout << "The average rating for " << title << " is ";
                    cout << fixed << setprecision(2) << count1 << endl;
                }
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 6:
                // make a new account
                cout << "Enter a username:" << endl;
                //////////////////////////////////////////////////////////////////////////
                // CODE HERE
                cin >> username;
                library.addUser(username);
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 7:
                // check out book
                //////////////////////////////////////////////////////////////////////////
                // CODE HERE

                cout << "Enter a username: " << endl;
                getline(cin, username);

                cout << "Enter a book title: " << endl;
                getline(cin, title);

                cout << "Enter a rating for the book: " << endl;
                cin >> rating;

                library.checkOutBook(username, title, rating);

                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 8:
                // view ratings

                // library.readBooks("books.txt");
                // library.readRatings("ratings.txt");

                cout << "Enter a username: " << endl;
                //////////////////////////////////////////////////////////////////////////
                // CODE HERE
                getline(cin, username);
                library.viewRatings(username);
                //////////////////////////////////////////////////////////////////////////

                cout << endl;
                break;

            case 9:
                // get recommendations
                cout << "Enter a username: " << endl;
                //////////////////////////////////////////////////////////////////////////
                // CODE HERE
                getline(cin, username);
                library.getRecommendations(username);
                //////////////////////////////////////////////////////////////////////////
                break;

            case 10:
                // quit
                cout << "good bye!" << endl;
                break;
            case 11:
                // TESTER CASE
                library.readBooks("b.txt");
                //library.readRatings("r.txt");
                library.addUser("newUser1");
                library.addUser("newUser2");
                library.addUser("newUser3");
                library.checkOutBook("newUser2", "The Five People You Meet in Heaven", 3);
                library.getRecommendations("newUser1");

                //a = library.getUser("joanna");
                //b = library.getUser("barbara");
                cout << library.ssd(a, b) << endl;
                break;
            default:
                cout << "invalid input" << endl << endl;
        } // switch
    } // while
    return 0;
} // main



// file:///C:/Users/nicol/Downloads/Hmwk8.pdf
// https://moodle.cs.colorado.edu/pluginfile.php/113446/mod_resource/content/5/hmwk7.pdf
