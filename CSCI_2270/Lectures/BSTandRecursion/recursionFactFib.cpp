//
// Created by Nicole Leon on 2/27/2019.
//

#include <iostream>
#include <cassert>

/* To increase efficiency store values in array*/
int Fib[1000];

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

long factorial(int n) {
    assert(n >= 0); // precondition

    long result = 1;
    /* <= n to go all the way up to n, not n-1 */
    for (int i = 1; i <= n; i++) result = result * i;
    return result;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// RECURSIVELY
long factorialR(int n) {
    assert(n >= 0); // precondition

    if (n == 0) return 1;
    return (n * factorialR(n - 1));
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// FIBONACCI
long fibonnacci(int n) {
    assert(n >= 1); // precondition

    if (Fib[n] != -1) return Fib[n]; // return what I have stored already

    if (n == 1) {
        Fib[1] = 1;
        return Fib[1];
    }
    else if (n == 2) {
        Fib[2] = 2;
        return Fib[2];
    } else {

        Fib[n] = fibonnacci(n-1) + fibonnacci(n-2);
        //Fib[n - 1] + Fib[n - 2];
        return Fib[n];
    }
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    if (argc == 2) {
        std::cout << factorial(atoi(argv[1])) << std::endl;
    }

    if (argc == 2) {
        std::cout << factorialR(atoi(argv[1])) << std::endl;
    }

    for (int i = 0; i <=100; i++) Fib[i] = -1;

    Fib[1] = 1;
    Fib[2] = 2;

    if (argc == 2) {
        std::cout << fibonnacci(atoi(argv[1])) << std::endl;
    }
    return 0;
}