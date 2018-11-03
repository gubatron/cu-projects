#include <iostream>
#include <iomanip> // std::setprecision
using namespace std;

int mystery(int n) 
{ 
    n++; 
    n++; 
    return n; 
} 
int main() 
{ 
    int a = 5; 
    cout << mystery(a) << endl; 
    return 0; 
}