#include "Game.h"

#ifndef UI_H
#define UI_H


class UI {
public:
    UI() : nullPlayer(Player(9999999,"Quiter"))  {}
    void start();
private:
    int milestoneScreen();
    std::string askForValidMilestoneScreenOption(bool servoOptionShown, bool enterPlayerMenuOptionShown);
    void gameOver(const unsigned int reason);
    void enterPlayer();
	void selectStartDate();
	void servoSupplyList();
    void servoScreen();

    void travel();
    void rest();
    void takePhotos();


    //void selectStartDate();
    //void pigs();

    void showBasicMenuOptions();
    void showEnterPlayerMenuOptions();
    void showServoMenuOptions();
    void showQuitMenuOptions();

    /** Shows the basic menu options
     *  Depending on the milestone shows option to go to servo
     *  and to enter player (first milestone and party < 2)
     *  And it lets us know if these options were shown via the two boolean reference variables
     *  passed.
     * */
    void showMilestoneMenuOptions(bool &servoOptionShown, bool &enterPlayerMenuOptionShown);

    /** converts string to lower case */
    void toLower(std::string &str);

    /** trims empty space characters on both sides of a string */
    void trim(std::string& str);

    Game game;
    Player nullPlayer;
};


#endif //UI_H
