#include <iostream>
using namespace std;

int example()
{
    int* myFive = 5;
    int *p = &myFive;
    return p;
}

int main()
{
    example();
}