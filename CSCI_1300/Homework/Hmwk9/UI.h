#include "Game.h"

#ifndef UI_H
#define UI_H


class UI {
public:
    UI() : nullPlayer(Player(9999999,"Quiter"))  {}
    void start();
private:
    unsigned int milestoneScreen();
   
	std::string askForValidMilestoneScreenOption(bool servoOptionShown, bool enterPlayerMenuOptionShown);
	
	bool printFile(std::string filePath) const;
    
	void enterPlayer();
	
	void selectStartDate();
    
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

	void gameOver(const unsigned int reason);
    
	/** converts string to lower case */
    void toLower(std::string &str);
	
	void toTitle(std::string &str);

    /** trims empty space characters on both sides of a string */
    void trim(std::string &str);

    /** returns the int value expressed by a string. The string is not manipulated therefore we guarantee it will
     * remain intact, by only accepting strings that cannot be chaged in the first place
     *
     * returns -1 if a string that does not represent an int was passed
     * */
	int toInt(const std::string &str);

	int readInt(); 

	int askIntQuestion(std::string question);

    Game game;
    Player nullPlayer;
};


#endif //UI_H
