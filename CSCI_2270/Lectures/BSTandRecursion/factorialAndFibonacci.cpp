#include<iostream>
#include<assert.h>

long *memo;


/* Slow Recursive Fibonacci: Complexity O(2^n) */
long factorial(int n) {
  assert(n >= 0);
  // std::cout << "computing factorial " << n << std::endl;
  if (n == 0)  return 1; 
  else return n * factorial(n-1);

}


/* Slow Recursive Fibonacci: Complexity O(2^n) */
unsigned long sibonacci(int n) {
  if (n==0)
    return 0; 
  else if (n==1)
    return 1;
  else
    return sibonacci(n-1) + sibonacci(n-2);
}

/* Fast Recursive Fibonacci: Complexity O(n) */
unsigned long fibonacci(int n) {
  if (memo[n] == -1) {
    // If we have not computed fibonacci(n) it yet then compute and memoize it in memo[n].
    if (n==0)
      memo[n] = 0; 
    else if (n==1)
      memo[n] = 1;
    else
      memo[n] = fibonacci(n-1) + fibonacci(n-2);
  }
  return memo[n];
}

int main(int argc, char* argv[]) {

  if (argc != 2) return 0;

  int N = atoi(argv[1]);
  //std::cout << factorial(atoi(argv[1])) << std::endl;

  memo = new long[N+1];
  for (int i=0; i <= N; i++) memo[i] = -1;
  
  
  std::cout << fibonacci(atoi(argv[1])) << std::endl;
  //  std::cout << sibonacci(atoi(argv[1])) << std::endl;
}
