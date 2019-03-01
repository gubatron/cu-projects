#include <iostream>
#include "circularArrayQueue.hpp"

CircularArrayQueue::CircularArrayQueue() {
  capacity = DEFAULT_SIZE;
  head = -1;
  tail = -1;
  items = new int[capacity];
}

CircularArrayQueue::CircularArrayQueue(int cap) {
  capacity = cap;
  head = -1;
  tail = -1;
  items = new int[capacity];
}

CircularArrayQueue::~CircularArrayQueue() {
  delete[] items;
}

bool CircularArrayQueue::isEmpty() {
  return (head == -1);
}

bool CircularArrayQueue::isFull() {
  return (getSize() == capacity);
}

int CircularArrayQueue::getSize() {
  if (head <= tail) {
    return (tail - head +1);
  }
  else {
    return capacity - (head - tail) + 1;
  }
}

void CircularArrayQueue::enqueue(int element) {
  /* your code goes here */
}

int CircularArrayQueue::dequeue() {
  /* your code goes here */
}

int CircularArrayQueue::peek() {
  if (isEmpty()) {
    std::cerr << "Queue Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    return items[head];
  }
}

void CircularArrayQueue::prettyPrint() {
  if (isEmpty()) {
    std::cout << "head->[]<-tail" << std::endl;;
  }
  else {  
    std::cout << "head->[";
    if (head <= tail) { 
      for (int i = head; i <= tail; i++) {
	std::cout << items[i] << " ";
      }
    }
    else {
      for (int i = head; i < capacity; i++) {
	std::cout << items[i] << " ";
      }
      for (int i = 0; i <= tail; i++) {
	std::cout << items[i] << " ";
      }
    }
    std::cout << "]<-tail"<<std::endl;
  }
}

void CircularArrayQueue::prettyPrintCircular() {
  if (isEmpty()) {
    std::cout << "head->[]<-tail" << std::endl;;
  }
  else {  
    std::cout << "[";
    for (int i = 0; i < capacity; i++) {
      if (head <= tail) {
	if (i >= head && i <= tail) {
	  if ((i == head) && (i == tail)) std::cout << "#"<<items[i]<<"* ";
	  else if (i == head) std::cout << items[i] <<"* ";
	  else if (i == tail) std::cout << "#"<<items[i];
	  else std::cout << items[i] << " ";
	}
	else std::cout << "B ";
      }
      else {
	if (i <= tail || i >= head) {
	  if ((i == head) && (i == tail)) std::cout << "#"<<items[i]<<"* ";
	  else if (i == head) std::cout << items[i] <<"* ";
	  else if (i == tail) std::cout << "#"<<items[i];
	  else std::cout << items[i] << " ";
	}
	else std::cout << "B ";
      }
    }
    std::cout << "]"<<std::endl;
  }
}
