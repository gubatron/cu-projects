#include <iostream>
#include <math.h>
#include <fstream>
#include "Book.h"
using namespace std;

int main()
{
    Book book1 = Book("A Title", "An Author");
    cout << book1.getTitle() << endl;
    cout << book1.getAuthor() << endl;
    book1.setTitle("Another title.");
    cout << book1.getTitle() << endl;
    cout << book1.getAuthor() << endl;
    book1.setTitle("A Different Author");
    cout << book1.getTitle() << endl;
    cout << book1.getAuthor() << endl;
    //book1.clear();
    cout << book1.getTitle() << endl;
    cout << book1.getAuthor() << endl;
    
    return 0;
}

// nile8832:~/workspace $ cd Homework/Hmwk7
// nile8832:~/workspace/Homework/Hmwk7 $ g++ -std=c++11 Book.cpp User.cpp Hmwk7.cpp