#include <iostream>
using namespace std;

//do while loops
int main()
{
    int j = 1; 
    do 
    { 
        int value = j * 2; 
        j++; 
        cout << value << ", "; 
    } while (j <= 5);
    
    return 0;
}