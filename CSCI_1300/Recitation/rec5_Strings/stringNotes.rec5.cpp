#include <iostream>
#include <math.h>
using namespace std;

/**
 NOTES 10/2 RECITATION
 
* string is an object and objects can have functions
* STRINGS START AT 0! NOT 1!

* "Cat"
*  012

* "Cat sleeps"
*  0123456789

*/
string returnAString(){
    string f = "Foo";
    return f;
    // return "Foo";
}

void takesAStringArgumant(string arg)
{
    cout << arg << endl;
}


int main()
{
    string s1 = "Cat eats"; // output length 3
    cout << s1.length() << endl;
    // string s2;         // output length 0
    // cout << s1.length() << " " << s2.length() << endl;
    // cin >> s1 >> s2;   // if input Elephant jumps
    // takesAStringArgumant(s1);  // output elephant
    // takesAStringArgumant(s2);  // output jumps (on next line)
    // // for string s length to find, it'll find functions of that string
    // cout << s1.length() << " " << s2.length() << endl;  // outputs 8 5  // lengths of "elephant" and "jump"
    
    // second argument is the length, not the end index
    // cout << s1.substr(0) << endl;   // print Cat
    // cout << s1.substr(0,1) << endl; // print C (from 0 to character 1)
    // cout << s1.substr(1,3) << endl; // print at (from 1 to character 3 (not existent in word "Cat")
    // cout << s1.substr(1) << endl; // print C (from 1 till it ends)
    // cout << s1.substr(1,2) << endl; // print at (from 1 till character 2)
    // cout << s1.substr(1,1) << endl; // prints a (start at index 1 of 1 character)
    // cout << s1.substr(1,0) << endl; // prints nothing
    // cout << s1.substr(1,30) << endl; // prints at (start at 1 till end of word)
    
    
    // cout << "The slow way to print a string:" << endl;
    // for (int i=0; i<s1.length();i++)
    // {
    //     cout << s1.substr(i,1);
    // }
    // cout << endl;
}


