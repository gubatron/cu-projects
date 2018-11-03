#ifndef DICE_H
#define DICE_H

class Dice {
    
    private:
        int faceValue;      // dice value variable

    public:
        Dice();             // default constructor
        void roll();        // to roll the dice
        int getFaceValue() const; // to get the dice face value

};
#endif