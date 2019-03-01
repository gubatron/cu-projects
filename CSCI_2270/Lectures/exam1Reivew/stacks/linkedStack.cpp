#include <iostream>
#include "linkedStack.hpp"

LinkedStack::LinkedStack() {
  capacity = DEFAULT_SIZE;
  top = 0;
  size = 0;
}

LinkedStack::LinkedStack(int cap) {
  capacity = cap;
  top = 0;
  size = 0;
}

LinkedStack::~LinkedStack() {
  StackNode* tmp = top;

  /* traverse the list and delete elements one-by-one */ 
  while (tmp != 0) {
    top = top->next;
    delete tmp;
    tmp = top;
  }
}

bool LinkedStack::isEmpty() {
  return (size == 0);
}

bool LinkedStack::isFull() {
  return (size == capacity);
}

void LinkedStack::push(int element) {
  if (isFull()) {
    std::cerr << "Stack Overflow!! Push failed" << std::endl;
  }
  else {
    StackNode* curr = new StackNode(element);
    curr->next = top;
    top = curr;
    size = size + 1;
  }
}

int LinkedStack::pop() {
  if (isEmpty()) {
    std::cerr << "Stack Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    int result = top->item;
    StackNode* tmp = top;

    top = top->next;
    size = size -1;
    
    delete tmp; 
    return result;
  }
}

int LinkedStack::peek() {
  if (isEmpty()) {
    std::cerr << "Stack Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    return top->item;
  }
}

void LinkedStack::prettyPrint() {
  if (isEmpty()) {
    std::cout << "top->[]" << std::endl;;
  }
  else {  
    std::cout << "top->[";
    StackNode* tmp = top;
    
    /* traverse the list and print elements one-by-one */ 
    while (tmp != 0) {
      std::cout << tmp->item  << " ";
      tmp = tmp-> next;
    }
    std::cout << "]"<<std::endl;
  }
}
