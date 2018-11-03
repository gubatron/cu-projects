#include <iostream>
#include <string>
using namespace std;

/**
 * 
 * Input Parameters:
 * Output:
 * Return:
 */
 
string removeDigits(string str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' '))
        {
            temp = temp + str[i]; 
        }
    }
    return temp;
}

int main()
{
   cout << removeDigits("123132Hello Computer Science World21324");
   return 0;
}