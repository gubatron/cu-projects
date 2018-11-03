#include <iostream>
using namespace std;

// from https://en.cppreference.com/w/cpp/language/switch
int main()
{
    int i = 2;
    
    // switch = compare a single value against several constant alternatives
    switch (i) 
    {
        case 1: cout << "1";
        case 2: cout << "2";   //execution starts at this case label
        case 3: cout << "3";
        case 4:
        case 5: cout << "45";
                break;              //execution of subsequent statements is terminated
        case 6: cout << "6";
    }
 
    cout << '\n';
 
    // switch (i) {
    //     case 4: cout << "a";
    //     default: cout << "d"; //there are no applicable constant_expressions 
    //                               //therefore default is executed
    // }
 
    cout << '\n';
 
    // switch (i) {
    //     case 4: cout << "a";  //nothing is executed
    // }
 
    // pathological examples
 
    // the statement doesn't have to be a compound statement
    // switch(0)
    //     cout << "this does nothing\n";
 
    // labels don't require a compound statement either
    // switch(int n = 1)
    //     case 0:
    //     case 1: cout << n << '\n';
 
}

    