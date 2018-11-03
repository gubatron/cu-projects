// CSCI1300 Fall 2018
// Author: Nicole Leon-Molina
// Recitation: <202> – John Klingner
// Cloud9 Workspace Editor Link: https://ide.c9.io/nile8832/nicole-csci1300
// hmwk8 / Project2

#include <iostream>
#include <iomanip>
#include "Book.cpp"
#include "User.cpp"
#include "Library.cpp"
using namespace std;

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
     cout << "6. Add a User" << endl;
     cout << "7. Checkout a book" << endl;
     cout << "8. View Ratings" << endl;
     cout << "9. Get Recommendations" << endl;
     cout << "10. Quit" << endl;
 }


int main(int argc, char const *argv[])
{
	//////////////////////////////////////////////////////////////////////////
	// Your code here. Call the appropriate function(s).
	
	Library call;
	
	string choice;
    int nb = 0; // number of books (1) 
    int nu = 0; // number of users (2)
    int count = 0; // (4)
    double count1 = 0; // (5)
    
    string filename = ""; // (1)(2)
    string username = ""; // (4)
    string title = ""; // (5)
    
    // Book booksData[200]; //
    // User userData[200]; // 
    
    // string titles[50]; // 
    // string authors[50]; // 
    // string usernames[100]; // 
    // int ratings[100][50]; // 

    while (choice != "10") 
    {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) 
            {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, filename); //read from file
                    //"books.txt"
                    nb = call.readBooks(filename);
                    
                    if (nb != -1)
                    {
                        cout << "Total books in the database: " << nb << endl;
                    }
                    else
                    {
                        cout << "No books saved to the database" << endl;
                    }
                     //////////////////////////////////////////////////////////////////////////
                    
                    
                    cout << endl;
                    continue;
                    break;

                case 2: 
                    // read user file
                    cout << "Enter a rating file name:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, filename);
                    //"ratings.txt"
                    nu = call.readRatings(filename);
                    if (nu != -1)
                    {
                        cout << "Total users in the database: " << nu << endl;
                    }
                    else
                    {
                        cout << "No users saved to database" << endl;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    continue;
                    break;

                case 3: 
                    // print the list of the books
                    
                    //////////////////////////////////////////////////////////////////////////
                    call.printAllBooks();
                    //////////////////////////////////////////////////////////////////////////
                    
                    continue;
                    break;

                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    
                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, username);
                    count = call.getCountReadBooks(username);
                    if (count != -1)
                    {
                        cout << username << " rated " << count << " books" << endl;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    continue;
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;

                    //////////////////////////////////////////////////////////////////////////
                    getline(cin, title);
                    count1 = call.calcAvgRating(title);
                    if (count1 != -1)
                    {
                        cout << "The average rating for " << title << " is ";
                        cout << fixed << setprecision(2) << count1 << endl;
                    }
                    //////////////////////////////////////////////////////////////////////////
                    
                    cout << endl;
                    continue;
                    break;
                    
    //             case 6:
    //                 // make a new account 
    //                 cout << "Enter a username:" << endl;
    //                 //////////////////////////////////////////////////////////////////////////
    //                 // CODE HERE
                    
    //                 //////////////////////////////////////////////////////////////////////////
                    
    //                 cout << endl;
    //                 break;
                
    //             case 7:
    //                 // check out book
    //                 cout << "Enter a username: " << endl;
    //                 cout << "Enter a username: " << endl;
    //                 cout << "Enter a username: " << endl;
    //                 //////////////////////////////////////////////////////////////////////////
    //                 // CODE HERE
    //                 //////////////////////////////////////////////////////////////////////////
                    
    //                 cout << endl;
    //                 break;
                    
    //             case 8:
    //                 // view ratings 
    //                 cout << "Enter a username: " << endl;
    //                 //////////////////////////////////////////////////////////////////////////
    //                 //////////////////////////////////////////////////////////////////////////
                    
    //                 cout << endl;
    //                 break;
                    
    //             case 9:
    //                 // get recommendations
    //                 cout << "Enter a username: " << endl;
    //                 //////////////////////////////////////////////////////////////////////////
    //                 //////////////////////////////////////////////////////////////////////////
                    
    //                 cout << endl;
    //                 break;
                    
    //             case 10:
    //                 // quit
    //                 cout << "good bye!" << endl;
    //                 break;

    //             default:
    //                 cout << "invalid input" << endl << endl;
    //         }
    // }
	//////////////////////////////////////////////////////////////////////////

            }
            return 0;
    }
}



// file:///C:/Users/nicol/Downloads/Hmwk8.pdf
// https://moodle.cs.colorado.edu/pluginfile.php/113446/mod_resource/content/5/hmwk7.pdf