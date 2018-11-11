#include <iostream>
#include <string>

using namespace std;

#ifndef SUPPLY_H
#define SUPPLY_H

// where methods and member variables are defined
class Supply {
public:
    

// private to the class
private:
  const string name; // "bullets", the name won't change
  const float cost; // in dollars, the cost won't change
  int amount; // how many you got left, this will change
}; 

#endif
