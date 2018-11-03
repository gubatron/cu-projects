#include <iostream>
#include <string>
using namespace std;
//106975077

/**
 * CountAtoJ - counts A to J chars
 * Input Parameters: string
 * Output:
 * Return: int
 */

int CountAtoJ(string str)
{
    int count = 0;
    int i = 0;
    if (str.empty())
    {
        count = -1;
    }
    for (i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'J'))
        {
            count++;
        }
    }
    if (count == 0)
        {
            count = -2;
        }   
    return count;
}

int main()
{
    cout << CountAtoJ("word ending with");
    return 0;
}
