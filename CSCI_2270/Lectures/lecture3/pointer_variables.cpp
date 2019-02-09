#include<iostream>
void main(int argc, char* argv[]) {
  char ch= ’a’;
  char *cp; // cp is a pointer variable
  cp = &ch; // cp points to the address of the ch
  std::cout << "Size of a pointer to char: ";
  std::cout << sizeof(char *) << std::endl;
  std::cout << "Address of ch is = " << (void *) cp;
  return 0;
}

// Pointers are address variables and you want to tell which address they are pointing to
// 1. What are the sizes of pointers to different typs of objects?
// 2. Repeat the above exercise for other types
// 3. A pointer varialble of type T is:
//      T* p OR T *p
//      bad practice: int *p, q, r
// 4. A pointer varialbe equal to 0 means it doesn't point to/refer to an object. Use of NULL is discouraged
