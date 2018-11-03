// custom countdown using while
#include <iostream>
using namespace std;

int main ()
{
  int n = 10;
  int goal = 1000000; //microseconds
  int t;
  
  //example clock() function behavior
  // cout << "clock = " << clock() << endl;
  // cout << "clock = " << clock() << endl;
  // cout << "clock = " << clock() << endl;
  
  while (n>0)
  {
    cout << n << "\n";
    --n;
    t = goal + clock(); //start

    while (t > clock())
    {
        //cout << ".";
    }
  }
  cout << "liftoff!\n";
  return 0;
}