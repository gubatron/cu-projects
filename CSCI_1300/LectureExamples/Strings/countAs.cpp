#include <iostream>
#include <string>
using namespace std;

// how many As, Bs, and Cs are in a given string?

// int countAs(string s)
// {
//     int count = 0;
//     if (s.length() == 0) // empty string. if (s == "")
//     {
//         count = -1;
//     }
//     else 
//     {
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C')
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main()
// {
//     string str = "ABCaBCBsdfAAAasdf";
//     cout << countAs(str);
//     return 0;
// }

/////////////////////////////////////////////////////
// how many characters from A through P?
// Look at ASCII Table and think of characters as numbers!

int countAs(string s)
{
    int count = 0;
    if (s.length() == 0) // empty string. if (s == "")
    {
        count = -1;
    }
    else 
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'C') // or you can say (s[i] >= '65' && s[i] == '67') with ASCII table numbers
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string str = "ABCDCAA";
    cout << countAs(str);
    return 0;
}