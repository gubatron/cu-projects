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
        time_t rawtime;
        time(&rawtime);
        my_tm = localtime(&rawtime); // properly initializes the struct tm
        my_tm->tm_year = year - 1900;
        my_tm->tm_mon = month - 1;
        my_tm->tm_mday = day;
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
        my_tm = localtime(&date_as_long);
    }

    std::string to_string() {
        return std::to_string(getYear()) + "/" + std::to_string(getMonth()) + "/" + std::to_string(getDay());
    }

	// int daysTo(Calendar days) {
	// 
	// }
private:
    struct tm* my_tm;
    time_t date_as_long;
};

#endif //CALENDAR_H
