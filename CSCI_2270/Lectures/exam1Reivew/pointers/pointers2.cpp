#include<iostream>

int main() {
  int x [20];

  x[0] = 1;
  for (int i=1; i<20; i++) x[i] = x[i-1]+i;
  for (int i=0; i<20; i++) std::cout<< "x["<<i<<"] = "<<x[i]<<" at address: " << x+i << "\n";
  std::cout<< std::endl;

  int* p = x; 
  std::cout<< "*p = " << *p << std::endl;
  std::cout<< "*(p)+4=" << *(p)+4 << std::endl;
  std::cout<< "*(p+4) = " << *(p+4) << std::endl;
  //  std::cout<< "(*p)[4] = " << (*p)[4]<< std::endl;
  
  int (*ptr)[20]; // pointer to an array of 20 integers
  ptr = &x;
  
  std::cout << "*ptr+4 = " << *ptr+4 << std::endl;;
  std::cout << "(*ptr)+4 = " << (*ptr)+4 << std::endl;
  std::cout << "*(ptr+4) = " << *(ptr+4) << std::endl;
  std::cout << "(*ptr)[4] = " << (*ptr)[4] << std::endl;

  return 0;
}
