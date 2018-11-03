#include <iostream>
#include <string>
using namespace std;

/**
 * 
 * Input Parameters:
 * Output:
 * Return:
 */

void dotsAndStars(int n)
{
  for (int i = 1 ; i <= n; i++)
  {
    for (int j = n; j >= i; j--)
    {
      if (i % 2 != 0)
      {
        cout<<"*";
      }
      else
      {
        cout<< "." ;
      }
    }
    cout << endl;
  }
  //cout << ".";
}


// void dotsAndStars(int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = n; j )
//     }
// }



int main()
{
    dotsAndStars(5);
    return 0;
}