#include <iostream>
#include <string>
using namespace std;

int main()
{
    //declaration and initialization at the same time
    string str1 = "Vile";
    string str2 = "plume";
    string str3 = "Gloom";
    int len1;
    string str4, str5;
    
    //str4 = "Vile" + "plume"; // not allowed; instead = "Vileplume"
    
    str5 = " "; // a space
    str4 = "Vile" + str5 + "plume"; // allowed
    
    //instead, + combines strings one and two with no white space in between
    str4 = str1 + str2; //concatenate
    cout << "New string reads " << str4 << endl << endl;
    len1 = str4.length(); //length function
    cout << "The length of the string is: "<< len1 << endl << endl;
    str5 = str3; //reassignment
    cout << "New string reads " << str5 << endl << endl;

    //referencing different characters in the string
    cout << "str1[0] reads " << str1[0] << endl << endl; //index 0 is 1st letter
    cout << "str1[1] reads " << str1[1] << endl << endl; //index 1 is 2nd letter
    cout << "str1[2] reads " << str1[2] << endl << endl;
    cout << "str1[3] reads " << str1[3] << endl << endl;
    cout << "str1[4] reads " << str1[4] << endl << endl; //index 4 is outside str1
    cout << "str1[5] reads " << str1[5] << endl << endl; //index 5 is outside str1
        // for 4 and 5, c++ let us run empty values because Vile only has 4 characters 
        // never use an index >= to length of string
    return 0;
}