#include "Player.h"

Player::Player(int nD){
    nDice = nD; // initial value
    for (int i = 0; i < nDice; i++){
        Dice d1;
        // fill out array
        myDice[i] = Dice(); // makes a new instance of the object and puts it in array
        //myDice[i] = d1; // another way to do it
    }
}

void Player::setNumDice(int number){
    nDice = number;
}

void Player::playerRoll(){
    // roll die
    for (int i = 0; i < nDice; i++){ //nDice initilaized in line 4
        myDice[i].roll(); //rolls die
    }
}

int Player::getDiceValueAtIndex(int i) const{
    return myDice[i].getFaceValue();
}