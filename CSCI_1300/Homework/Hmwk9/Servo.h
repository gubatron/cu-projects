#include "Common.h"

#ifndef SERVO_H
#define SERVO_H

class Servo {
public:
    // default constrctor - initialize variables
    Servo();
    
    string getItem(int purchaseInput); // purchace choice 
    
    float printBill(int purchaseInput) // adds/subtracts items
    // money *** should I make a Money Class??
    
    // Supplies
    

private:
    int amount; // how many are left, this will change
    Supplies name; // "film", the name won't change CONSTANT
    const float cost; // in dollars, the cost won't change
    // money --
    
    // double money;
    // double food; // pounds
    // int tires; 
    // int film;
    // int van parts;
    
};

#endif
