#include <iostream>
#include <iomanip> 
using namespace std;


/**
 * calculator function prints out an answer based on arithmetic
 *      1. Assume: no overflow, underflow, and division by 0
 *      2. Set precision point to 2
 *      3. Use SWITCH CASE
 *      4. Answer format = <number1><operator><number2> = <answer>
 *      5. Invalid operators = "Invalid operator!"
 * Input parameters: n1 (double); n2 (double); O (char)
 * Output: format 
 * Returns: nothing // void
*/

void calculator (double n1, double n2, char c1)
{
    double n3 = n1 + n2;
    double n4 = n1 - n2;
    double n5 = n1 * n2;
    double n6 = n1 / n2;
    
    switch (n1, n2, c1)
    {
        case '+': cout << n1 << " " << c1 << " " << n2 << " " << "=" << " " << n3 << endl;
            break;
        case '-': cout << n1 << " " << c1 << " " << n2 << " " << "=" << " " << n4 << endl;
            break; 
        case '*': cout << n1 << " " << c1 << " " << n2 << " " << "=" << " " << n5 << endl;
            break;
        case '/': cout << n1 << " " << c1 << " " << n2 << " " << "=" << " " << fixed << setprecision(2) << n6 << endl;
            break;
        default: cout << "Invalid operator!" << endl;  
    }
    
    
}

int main()
{
    calculator(5,2,'+');
    calculator(5,2,'-');
    calculator(5,2,'*');
    calculator(3,7,'/');
    calculator(5,2,'!');
}