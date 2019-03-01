#include<iostream>

static int i;
int main() {
  std::cout << " Size of integer " << sizeof(int) << std::endl;

  int x = 0;
  std::cout << "Type\t Name \t\t Value \t\t Address" << std::endl;
  std::cout << "int \t x \t\t "<< x << " \t\t " << &x << std::endl;

  int* z = &x; // pointer variable z contains the address of variable x;
  std::cout << "int \t z \t\t "<< z << " \t\t " << &z << std::endl;
  std::cout << "int \t *z \t\t "<< *z << " \t\t " << &*z << std::endl;

  x = 5;
  std::cout << "__________________________________________________________________"<<std::endl;
  std::cout << " x = 5 "<<std::endl;
  std::cout << "__________________________________________________________________"<<std::endl;
  std::cout << "int \t x \t\t "<< x << " \t\t " << &x << std::endl;
  std::cout << "int \t z \t\t "<< z << " \t\t " << &z << std::endl;
  std::cout << "int \t *z \t\t "<< *z << " \t\t " << &*z << std::endl;

  *z = 33;
  std::cout << "__________________________________________________________________"<<std::endl;
  std::cout << " *x = 33 "<<std::endl;
  std::cout << "__________________________________________________________________"<<std::endl;
  std::cout << "int \t x \t\t "<< x << " \t\t " << &x << std::endl;
  std::cout << "int \t z \t\t "<< z << " \t\t " << &z << std::endl;
  std::cout << "int \t *z \t\t "<< *z << " \t\t " << &*z << std::endl;


  int* u = new int(5); // u points to an address that stores an integer value
  int* v = new int[4]; // v points to an address that an array of integers

  u[0] = 3;
  std::cout << "int \t u \t\t "<< u << " \t\t " << &u << std::endl;
  std::cout << "int \t u[1] \t\t "<< u[1] << " \t\t " << &u[1] << std::endl;

  int y[2] = {11, 14};
  std::cout << y[0] << "  " << y[1];
  // int y[4];
  // std::cout << "int* \t y \t\t "<< y << " \t\t " << &y << std::endl;
  // std::cout << "int \t y[0] \t\t "<< y[0] << " \t\t " << &y[0] << std::endl;
  // std::cout << "int \t y[1] \t\t "<< y[1] << " \t\t " << &y[1] << std::endl;
  // std::cout << "int \t y[2] \t\t "<< y[2] << " \t\t " << &y[2] << std::endl;
  // std::cout << "int \t y[3] \t\t "<< y[3] << " \t\t " << &y[3] << std::endl;

    
  
  return 0;
}
