//
// Created by Nicole Leon on 3/3/2019.
//
#include <iostream>

int myFunc(int n) {
    int result = 0;
    if (n<=0) return 0;
    if (n==1) return 1;
    result = myFunc(n-1) + myFunc(n-3);
    return result;
}
int main(){
    std::cout << myFunc(4);
    return 0;
}
