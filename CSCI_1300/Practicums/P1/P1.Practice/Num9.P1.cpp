#include <iostream>
using namespace std;


/**
 * DayOfWeek function tells you type of day of week
 *      1. takes an integer for the day of the week 
 * and returns with a string depending on the day of he week. 
 * Input parameters: day (int)
 * Output: nothing 
 * Returns: weekday (string)   // SWITCH STATEMENT
*/


string DayOfWeek (int day){
    switch (day) {
        case 1: return "MONDAY";
            break;
        case 2: 
        case 3:
        case 4: return "WORKDAY";
            break;
        case 5: return "FUNDAY";
            break;
        case 6: 
        case 0: return "SLEEPDAY";
            break;
        default: return "INVALID";
    }
}

int main(){
    DayOfWeek(1);
    DayOfWeek(3);
    DayOfWeek(6);
    DayOfWeek(7);
}
