#include <iostream>
#include "arrayQueue.hpp"

ArrayQueue::ArrayQueue() {
  capacity = DEFAULT_SIZE;
  head = -1;
  tail = -1;
  items = new int[capacity];
}

ArrayQueue::ArrayQueue(int cap) {
  capacity = cap;
  head = -1;
  tail = -1;
  items = new int[capacity];
}

ArrayQueue::~ArrayQueue() {
  delete[] items;
}

bool ArrayQueue::isEmpty() {
  return (getSize() == 0);
}

bool ArrayQueue::isFull() {
  return (tail == (capacity-1));
}

int ArrayQueue::getSize() {
  if (head == -1) return 0;
  else return (tail-head+1);
}

void ArrayQueue::enqueue(int element) {
  if (isFull()) {
    std::cerr << "Queue Overflow!! Enqueue failed" << std::endl;
  }
  else {
    if (head == -1) {
      head = 0;
      tail = 0;
      items[tail] = element;
      
    }
    else {
      tail = tail + 1;
      items[tail] = element;
    }
  }
}

int ArrayQueue::dequeue() {
  if (isEmpty()) {
    std::cerr << "Queue Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    int result = items[head]; 

    for (int i = 0; i < tail; i++) {
      items[i] = items[i+1];
    }
    tail = tail-1;

    if (tail == -1) head = -1;

    return result;
  }
}

int ArrayQueue::peek() {
  if (isEmpty()) {
    std::cerr << "Queue Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    return items[head];
  }
}

void ArrayQueue::prettyPrint() {
  if (isEmpty()) {
    std::cout << "head->[]<-tail" << std::endl;;
  }
  else {  
    std::cout << "head->[";
    for (int i = 0; i <= tail; i++) {
      std::cout << items[i] << " ";
    }
    std::cout << "]<-tail"<<std::endl;
  }
}
