#include<iostream>
#include "listclass.hpp"

LinkedList::LinkedList() {
  head = 0;
  tail = 0;
}

LinkedList::~LinkedList() {
  Node *curr;
  Node *next;

  curr = next = head;

  while (curr != 0) {
    next = curr-> next;
    delete curr;
    curr = next;
  }
}

void LinkedList::traverse() {
  Node* curr;

  std::cout<<"head->";

  for (curr = head; curr != 0; curr = curr->next) {
    std::cout << curr->data << "->";    
  }
  
  std::cout<<"tail" << std::endl;
}

Node* LinkedList::search(int val) {
  Node* curr = head;
  
  while (curr != 0) {
    if (curr->data == val) return curr;
    curr = curr->next;
  }

  return 0;
}

void LinkedList::insertNode(int leftValue, int value) {
  Node* left = search(leftValue);
  Node* node = new Node(value);
  
  if (left == 0) {                    /* inserting a new head node */
    node->next = head;
    head = node;
    if (tail == 0) tail = head;
  }
  else if (left->next == 0) {         /* inserting a new tail node */
    left->next = node;
    tail = node;
  }
  else {                              /* inserting a node in the middle */
    node->next = left->next;
    left->next = node;
  }
}

void LinkedList::deleteNode(int value) {
  if (head->data == value) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  else { /*either tail node or middle node */
    Node* prev = head;
    Node* curr = prev->next;
    bool isFound = false;
    while (curr != 0 && isFound != true) {
      if (curr->data == value) {
        if (curr->next == 0) { /* tail node */
          prev->next = 0;
          tail = prev;
        }
        else {
          prev->next = curr->next;
        }
        delete curr;
        isFound = true;
      }
      else {
        prev = curr;
        curr = curr-> next;
      }
    }
  }
}

