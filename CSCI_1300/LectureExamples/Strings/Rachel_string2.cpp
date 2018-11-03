#include <iostream>
#include <string>
using namespace std;

int main()
{
    //declaration and initialization
    string str1, str2, str3;
    str1 = "Nine";
    str2 = "tales";

    str3 = str1 + str2; //concatenation

    cout << "One of Rachel's favorite pokemon is " << str3 << endl;
    double l = str3.length(); //length function
    cout << "The length of the new string is: " << l << endl;
    
    cout << "The first 3 letters of str3 are " << str3.substr(2,0) << endl;

    string str5 = "slowpoke";
    string str6 = "slowbro";
    string str7 = "slowking";

    // compare function 
    // cout << str5.compare(str6) << endl; //p > b
    // cout << str5.compare(0,3,"slow") << endl; //slow is longer
    // cout << str5.compare(0,4, "slow") << endl;
    // cout << str5.compare(0,4,str6,0,4) << endl;
    
    // replace function
    // cout << str5.replace(4,4,"down") << endl;
    // cout << str7.replace(0,4,"") << endl;
    // cout << str6.replace(4,3,"") << endl;
    // cout << str5 << endl; // str5 has changed
    
    // // find function
    // cout << str5.find("s") << endl;
    // cout << str5.find("sl") << endl;
    // cout << str5.find("lo") << endl;
    // cout << str5.find("ow") << endl;
    // cout << str5.find("ow", 3) << endl;

}
