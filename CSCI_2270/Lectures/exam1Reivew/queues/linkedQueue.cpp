#include <iostream>
#include "linkedQueue.hpp"

LinkedQueue::LinkedQueue() {
  capacity = DEFAULT_SIZE;
  head = 0;
  tail = 0;
  size = 0; 
}

LinkedQueue::LinkedQueue(int cap) {
  capacity = cap;
  head = 0;
  tail = 0;
  size = 0; 
}

LinkedQueue::~LinkedQueue() {
  QueueNode* tmp = head;

  while (tmp != 0) {
    head = head->next;
    delete tmp;
    tmp = tmp->next;
  }
}

bool LinkedQueue::isEmpty() {
  return (size == 0);
}

bool LinkedQueue::isFull() {
  return (size == capacity);
}

int LinkedQueue::getSize() {
  return size;
}

void LinkedQueue::enqueue(int element) {
  if (isFull()) {
    std::cerr << "Queue Overflow!! Enqueue failed" << std::endl;
  }
  else {
    QueueNode* tmp = new QueueNode(element);
    tmp->next = 0;
    
    if (head == 0) {
      head = tmp;
      tail = tmp;
      size = size + 1;
    }
    else {
      tail->next = tmp;
      tail = tmp;
      size = size + 1;
    }
  }
}

int LinkedQueue::dequeue() {
  if (isEmpty()) {
    std::cerr << "Queue Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    int result = head->item; 
    QueueNode* tmp = head;

    if (tail == head) {
      // there is only one node in the queue
      tail = 0;
      head = 0;
    }
    else {
      head = head->next;
    }
    
    delete tmp;

    size = size - 1;
    return result;
  }
}

int LinkedQueue::peek() {
  if (isEmpty()) {
    std::cerr << "Queue Empty!! Returning garbarge" << std::endl;
    return -1;
  }
  else {
    return head->item;
  }
}

void LinkedQueue::prettyPrint() {
  if (isEmpty()) {
    std::cout << "head->[]<-tail" << std::endl;;
  }
  else {  
    std::cout << "head->[";
    QueueNode* tmp = head;
    while (tmp != 0) {
      std::cout << tmp->item << " ";
      tmp = tmp->next;
    }
    std::cout << "]<-tail"<<std::endl;
  }
}
