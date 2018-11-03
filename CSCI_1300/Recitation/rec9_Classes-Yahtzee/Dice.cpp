#include <cstdlib>
#include "Dice.h"       // including Dice class header file

using namespace std;

Dice::Dice(){
      faceValue = 0;    // initialize dice value to 0
}

void Dice::roll(){
      // generating random number between 1 to 6
      int value = rand() % 6 + 1;
      faceValue = value;
}

int Dice::getFaceValue() const{
      return faceValue;
}
