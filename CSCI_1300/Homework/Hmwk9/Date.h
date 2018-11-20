#include "Common.h"
#ifndef DATE_H
#define DATE_H
class Date {
public:
    Date(int year, int month, int day) {
        //Reference: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
        // time saves the number of seconds since 1970 to a long (time_t)
        // mktime converts tm structure to long (time_t)
        // localtime converts a long (time_t) to a tm structure
        time_t rawtime;
        time(&rawtime);
        my_tm = *localtime(&rawtime); // properly initializes the struct tm
        my_tm.tm_year = year - 1900;
        my_tm.tm_mon = month - 1;
        my_tm.tm_mday = day;
        date_as_long = mktime(&my_tm) + 60*60*12;
    }

    int getYear() {
        return my_tm.tm_year + 1900;
    }

    int getMonth() {
        return my_tm.tm_mon + 1;
    }

    int getDay() {
        return my_tm.tm_mday;
    }

    void addDays(int nDays) {
        date_as_long += nDays * (24*60*60);
        struct tm * stack_tm = localtime(&date_as_long);
        my_tm = *stack_tm;
    }

    std::string to_string() {
        return std::to_string(getYear()) + "/" + std::to_string(getMonth()) + "/" + std::to_string(getDay());
    }

private:
    struct tm my_tm;
    time_t date_as_long;
};

#endif //DATE_H
