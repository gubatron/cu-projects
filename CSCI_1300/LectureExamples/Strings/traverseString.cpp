#include <iostream>
#include <string>
using namespace std;


// how to write all of this v in a loop?
    // cout << "str1[0] reads " << str1[0] << endl << endl; //index 0 is 1st letter
    // cout << "str1[1] reads " << str1[1] << endl << endl; //index 1 is 2nd letter
    // cout << "str1[2] reads " << str1[2] << endl << endl;
    // cout << "str1[3] reads " << str1[3] << endl << endl;
    // cout << "str1[4] reads " << str1[4] << endl << endl; //index 4 is outside str1
    // cout << "str1[5] reads " << str1[5] << endl << endl; //index 5 is outside str1

// print each character in a given string

int main()
{
    string str = "ABCsdkjlfeifue";
    for (int i = 0; i < str.length(); i++) // loop that executes three times
                        // ^ should be length of string
    
        cout << "str[0] reads " << str[i] << endl << endl;
    }
    
    return 0;
}

// count each character in a given string

