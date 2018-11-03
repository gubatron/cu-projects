#ifndef PLAYER_H
#define PLAYER_H
#include "Dice.h"

class Player
{

  private:
    Dice myDice[5];             // an array of Dice objects
    int nDice;                  // number of Dices player has

  public:
    Player(int nD);          // parameterized constructor with nDice
    void playerRoll();          // roll all the dices
    void setNumDice(int nDice); // set number of dices
    int getDiceValueAtIndex(int i) const;   // get value of Dice i
    
};
#endif