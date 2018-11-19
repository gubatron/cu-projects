#include "Common.h"

#ifndef SUPPLIES_H
#define SUPPLIES_H

// where methods and member variables are defined
class Supplies {
public:
    Supplies();
    
    string getSupplies(string choiceName); // return string
    
    void setSupplies(string choiceName);

    // Each supply has it's own conditions
    // How do I connect Supplies.h with Supply.h
    
    
private: 
    Supply tires;
    Supply clothing;
    Supply film;
    Supply engine;
    Supply bumpers;
    Supply battery;
    Supply medicalKit;
    
};

#endif