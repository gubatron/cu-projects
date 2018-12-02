#include "Common.h"
#ifndef CALENDAR_H
#define CALENDAR_H
class Calendar {
public:
    Calendar(int year, int month, int day) {
        //Reference: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
        // time saves the number of seconds since 1970 to a long (time_t)
        // mktime converts tm structure to long (time_t)
        // localtime converts a long (time_t) to a tm structure
        time_t rawtime = 0;
        time(&rawtime); // currently set to seconds since 1970 jan 1st - epoch time

        my_tm = new tm(*localtime(&rawtime)); // properly initializes the struct tm, it needs a pointer, so we pass &rawtime
        // important: every time localtime is called, it will return a pointer to the same object,
        // we use "new tm()" to allocate a new copy in memory of the struct.
        // if we don't make a copy of this pointer with new tm(reference to that same pointer) all our Calendar
        // objects will point to the same struct tm* and all our Calendar objects will look the same

        // we now have a time structure set to the current moment in time
        // we want it to be, what's been passed in the constructor (year, month, day)

        // we rewrite the fields of the struct tm*
        my_tm->tm_year = year - 1900; // struct tm years are not based in our current year, gotta subtract 1900
        my_tm->tm_mon = month - 1; // months are zero based, so we subtract 1
        my_tm->tm_mday = day; // days are fine, very inconsistent.

        // now that we have a struct tm* with the values we want, we convert it to a time_t, aka, long
        // and this is the number we use to perform time operations.
        // we will add or subtract the seconds in a day (24*60*60) to move back and forth in time
        // and then we'll convert back to a struct tm* to obtain the year, month, and date.
        date_as_long = mktime(my_tm);
    }

    int getYear() {
        return my_tm->tm_year + 1900;
    }

    int getMonth() {
        return my_tm->tm_mon + 1;
    }

    int getDay() {
        return my_tm->tm_mday;
    }

    void addDays(int nDays) {
        date_as_long += nDays * (24*60*60);
        delete(my_tm); // avoid memory leaks
        my_tm = new tm(*localtime(&date_as_long)); // get a new pointer every time
    }

    std::string to_string() {
        // TODO: Put names of months in an array of std::string and return the actual month name instead
        // MONTHS[getMonth()-1]
        return std::to_string(getYear()) + "/" + std::to_string(getMonth()) + "/" + std::to_string(getDay());
    }

    /** Subtract two calendar and return number of days! */
    long subtractDays(const Calendar &other) const {
        // substract second difference, and then divide by the seconds in a day
        long differenceInSeconds = date_as_long - other.date_as_long;
        long secondsInADay = 3600*24;
        return differenceInSeconds / secondsInADay;
    }
private:
    struct tm* my_tm;
    time_t date_as_long;
};

#endif

