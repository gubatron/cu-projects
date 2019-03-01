#include <iostream>
#include "arrayStack.hpp"

ArrayStack::ArrayStack() {
  capacity = DEFAULT_SIZE;
  top = -1;
  items = new int[capacity];
}

ArrayStack::ArrayStack(int cap) {
  capacity = cap;
  top = -1;
  items = new int[capacity];
}

ArrayStack::~ArrayStack() {
  delete[] items;
}

bool ArrayStack::isEmpty() {
  return (top == -1);
}

bool ArrayStack::isFull() {
  return (top == (capacity-1));
}

void ArrayStack::push(int element) {
  if (isFull()) {
    std::cerr << "Stack Overflow!! Push failed" << std::endl;
  }
  else {
    top = top + 1;
    items[top] = element;
  }
}

int ArrayStack::pop() {
  if (isEmpty()) {
    std::cerr << "Stack Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    int result = items[top];
    top = top - 1;
    return result;
  }
}

int ArrayStack::peek() {
  if (isEmpty()) {
    std::cerr << "Stack Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    return items[top];
  }
}

void ArrayStack::prettyPrint() {
  if (isEmpty()) {
    std::cout << "[]" << std::endl;;
  }
  else {  
    std::cout << "[";
    for (int i = 0; i <= top; i++) {
      std::cout << items[i] << " ";
    }
    std::cout << "]<-top"<<std::endl;
  }
}
