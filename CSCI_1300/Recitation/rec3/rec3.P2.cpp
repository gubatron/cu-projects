#include <iostream>
using namespace std;


/**
 * calcPay takes two paramters:
 *      1. One is the number of hours worked
 *      2. The other is the hourly pay rate
 *   Worked over 40 hours calculated at 1.5x the pay rate
 * Input parameters: hours (double), rate (double)
 * Output: nothing
 * Returns: calculated total pay
*/

double calcPay (double hours, double rate)
{
    double regularPay = hours * rate ;
    double overtimePay = (40 * rate) + ((hours - 40) * (rate * 1.5));
    double totalPay;
    
    if (hours < 0 || rate < 0)
    {
        return -1;
    }
    else if (hours <= 40)
    {
        totalPay = regularPay;
        return totalPay; 
    }
    else //if (hours > 40)
    {
        totalPay = overtimePay;
        return totalPay;
    }
}

int main()
{
    // test 1
    // expected output
    // 400
    cout << "Total pay is: " << calcPay(40,10) << endl;
   
    // test 2
    // expected output 
    // 415
    cout << "Total pay is: " << calcPay(41,10) << endl;
    
}
