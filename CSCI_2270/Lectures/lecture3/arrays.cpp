#include<iostream>
void main(int argc, char* argv[]) {
  int ia[3]; //Array of 3 ints with garbage values
  std::cout << ia[1] << std::endl;
  float fa[] = {1, 2, 3}; //Array of 3 floats initialzed: size automatically mputed
  std::cout << fa[2] << std::endl; // Read different values
return 0;
}

// Array is a collection of elements of the same type

// 1. Static array storage is contiguous
// 2. Array bound must be a constant expression. If you need variable
// bounds, use a vector.
// 3. What happens when initialization and array size mismatch?
// 4. Multi-dimensional arrays (contiguous in row-order fashion!).
