#include<iostream>

/*******************************************************************
 *
 * Proper way to pass an array when size change is desired! 
 *
 *
 ******************************************************************/


void plusFour(int** pArray, int capacity) {
  int *newarray = new int[capacity];
  for (int i=0; i< capacity; i++) {
    newarray[i] = (*pArray)[i] + 4;
  }

  delete[] (*pArray);
  *pArray = newarray;
  
  std::cout << "Inside called function:" << std::endl; 
  for (int i=0; i< capacity; i++) std::cout << (*pArray)[i] << " ";
  
  std::cout<<std::endl;
}

int main(){
  int capacity = 10;
  int* array = new int[capacity];

  for (int i=0; i < capacity; i++) array[i] =1;

  plusFour(&array, capacity);
  std::cout << "After returning:" << std::endl; 
  for (int i=0; i< capacity; i++) std::cout << array[i] << " ";
}
