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

	/** converts string to lower case except for the first character */
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

	/** Asks the question and takes into account as valid answers a min and a max value.
	 * if validMin is UI_NO_LIMIT (999999999), then there's no minimum to consider
	 * if validMax is UI_NO_LIMIT (999999999), then there's no maximum to consider
	 *
	 * This function assumes that all user input will be positive integers aka unsigned int.
	 * Therefore we can safely use -1 and other negative numbers as error or special code outputs.
	 *
	 * The user can respond with 'q','quit'
	 *
	 * Returns:
	 *  UI_INVALID_INPUT (-1) if the response is invalid
	 *  UI_QUIT_CODE if the user entered 'q' or 'quit'
	 *  A valid int response
	 * */
	int askIntQuestion(std::string question, unsigned int validMin, unsigned int validMax);

	void clearScreen() const;
    Game game;
    Player nullPlayer;
};


#endif //UI_H
