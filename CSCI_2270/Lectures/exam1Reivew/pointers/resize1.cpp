#include<iostream>

/*******************************************************************
 *
 * Arrays are passed as pointers! Called program has addresses of 
 * the array and can change its values, but not change the variable 
 * itself, i.e. array can not be reassigned or modified for size.
 *
 ******************************************************************/


void plusFour(int *array, int capacity) {
  int *newarray = new int[capacity];
  for (int i=0; i< capacity; i++) {
    newarray[i] = array[i] + 4;
  }
  
  array = newarray;
  std::cout << "Inside called function:" << std::endl; 
  for (int i=0; i< capacity; i++) std::cout << array[i] << " ";
  
  std::cout<<std::endl;
}

int main(){
  int capacity = 10;
  int array[10];

  for (int i=0; i < capacity; i++) array[i] =1;

  plusFour(array, capacity);
  std::cout << "After returning:" << std::endl; 
  for (int i=0; i< capacity; i++) std::cout << array[i] << " ";
}
