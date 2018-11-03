#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Dice.h" 
using namespace std;

// driver code to run and verify dice class is working
int main(){

      Dice d1;
      Dice d2;
      srand(time(0));
      for (int i = 1; i <= 10; i++){  
            d1.roll();
            d2.roll();
            cout << d1.getFaceValue() << " " << d2.getFaceValue() << endl;
      }

      return 0;
}