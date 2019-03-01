#include<iostream>

void resize(int *array, int* capacity) {
  int newCapacity = *capacity*2;
  int *newArray = new int(newCapacity);
  
  for (int i=0; i< *capacity; i++) {
    newArray[i] = array[i] + 4;
  }
  array=newArray;
  *capacity = newCapacity;
}

int main(){
  int capacity = 10;
  int * array = new int(capacity);
  for (int i=0; i < capacity; i++) array[i] =1;

  resize(array, &capacity);
  for (int i=0; i< capacity; i++) std::cout << array[i] << " ";
}
