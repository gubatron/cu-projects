        
#include <iostream>
using namespace std;

void convertSeconds(int sec)
{
    int hours = sec/3600;
    int minute = (sec%3600)/60;
    int seconds = sec%60;
    cout << hours << " hour(s) " << minute << " minute(s) " << seconds << " second(s)";
}

int main()
{

   return 0;