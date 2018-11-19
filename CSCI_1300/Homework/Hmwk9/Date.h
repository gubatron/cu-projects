#include "Common.h"

#ifndef DATE_H
#define DATE_H


class Date {
public:
    Date();
    
    int dateCount(int dayInput, int monthInput, int yearInput);

// GAME LASTS X AMOUNT OF DAYS

private: 
    int day;
    int month;
    int year;
    
    // turns (2 days long)
    // rest (1 day)
    // calendar count
}; 

#endif

/**
 * count as each day goes by
 * consider months with 30 days vs 31 days
 */