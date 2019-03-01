#include<iostream>

/*******************************************************************
 *
 * Arrays are passed as pointers! Called program has addresses of 
 * the array and can change its values
 *
 ******************************************************************/


void plusFour(int *array, int capacity) {
  for (int i=0; i< *capacity; i++) {
    array[i] = array[i] + 4;
  }
}

int main(){
  int capacity = 10;
  int array[10];

  for (int i=0; i < capacity; i++) array[i] =1;

  plusFour(array, capacity);
  
  for (int i=0; i< capacity; i++) std::cout << array[i] << " ";
}
