// custom countdown using while
#include <iostream>
using namespace std;

int main ()
{
  int n = 10;

  // I want to countdown: 10, 9, 8, ..., 2, 1, Liftoff!
  while (n < 0)  // n >= 1
  {
    cout << n << ", ";
    n = n -1; // n--
  }
  cout << "Liftoff!" << endl;
  
  return 0;
}