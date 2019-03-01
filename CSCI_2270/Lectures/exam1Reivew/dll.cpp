#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>       /* time */

struct Node {
  int key;
  Node* prev;
  Node* next;

  Node() {
    key = -1;
    prev = 0;
    next = 0;
  }

  Node(int k) {
    key = k;
    prev = 0;
    next = 0;
  }

};

class LinkedList {
private:
public:
  Node* head;
  Node* tail;


  LinkedList() {
    head = 0;
    tail = 0;
  }

  // destructor
  ~LinkedList() {
    Node* tmp = head;

    while (tmp != 0) {
      Node* succ = tmp->next;
      delete tmp;
      tmp = tmp->next;
    }
  }
  
  Node* search(int val) {
    for (Node* tmp = head; tmp!= 0; tmp=tmp->next) {
      if (tmp->key == val) return tmp;
    }
    return 0;
  }

  void insert(int val, Node* leftNode) {
    Node* tmp = new Node(val);
    if (leftNode == 0) {
      /* first node */
      tmp->next = head;
      if (head != 0) head->prev = tmp;
      head = tmp;
      if (tail == 0) tail = tmp; 
    }
    else if (leftNode->next == 0) {
      /* last node */
      tmp->prev = leftNode;
      tail->next = tmp;
      tail  = tmp;
    }
    else {
      /* middle node */
      Node* rightNode = leftNode->next;

      leftNode->next = tmp;
      tmp->prev = leftNode;
      rightNode->prev = tmp;
      tmp->next = rightNode;
    }
    
  }

  void deleteNode(int val) {
    Node* tmp = search(val);

    if (tmp == 0) {
      /* empty list */
      return;
    }
    else {
      if (tmp == head) {
	/* delete at the top */
	if (head->next == 0) {
	  tail = 0;
	  head = 0;
	}
	else {
	  head = head->next;
	  head->prev = 0;
	}
	delete tmp;
      }
      else if (tmp == tail) {
	/* delete tail node */
	if (tail==head) head  = 0;
	tail = tail->prev;
	tail->next = 0;
	delete tmp;
      }
      else {
	/* delete middle node */
	Node* tmp_prev = tmp->prev;
	Node* tmp_next = tmp->next;

	delete tmp;
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_prev;
      }
    }
    return;
  }


  void traverse() {
    for (Node* tmp = head; tmp!= 0; tmp=tmp->next) {
      std::cout << tmp->key << " ";
    }
    std::cout << std::endl;
  }

};

int main() {
  LinkedList L;
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);

  L.head = first;
  first->next = second;
  first->prev = 0;
  
  second->next = third;
  second->prev = first;

  third->next = 0;
  third->prev = second;

  L.tail = third;
  L.traverse();

  Node* secthird = new Node(25);

  Node* after = second;
  Node* before = second->next;

  
  secthird->next = third;
  secthird->prev = second;

  L.traverse();

  second->next = secthird;
  third->prev = secthird;

  L.traverse();

  Node* tmp = L.search(110);
  L.insert(5, tmp);

  L.traverse();

  tmp = L.search(30);
  L.insert(35, tmp);
  L.traverse();
}
