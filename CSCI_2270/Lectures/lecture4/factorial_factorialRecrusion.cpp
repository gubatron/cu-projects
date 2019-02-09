// program23.cpp
// Factorial(n) = n * (n-1) * (n-2) * ... * 1
#include<iostream>
#include <cmath>
int factorial(int x);
void main(int argc, char* argv[]) {
    if (argc == 2) std::cout << factorial(std::stoi(argv[1]));
    return 0;
}
int factorial(int x) {
    int res = x;
    while (x-- > 1) res = res * x;
    return res;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RECURSIVE
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// program24.cpp
// Factorial(n) = n * Factorial(n-1)
//#include<iostream>
//#include <cmath>
//int factorial(int x);
//int main(int argc, char* argv[]) {
//    if (argc == 2) std::cout << factorial(std::stoi(argv[1]));
//    return 0;
//}
//int factorial(int x) {
//    int y = 1;
//    std::cout << "Entering function Factorial(" << x << ")" << std::endl;
//    if (x == 0) y = 1;
//    else y = x * factorial(x-1);
//    std::cout << "Computed Factorial(" << x << ")" << std::endl;
//    return y;
//}