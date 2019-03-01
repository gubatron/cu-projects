#include<iostream>

//self-referential structure

struct Node {
  int value;
  struct Node* next; //Self-referential structures

  Node(int _value) {value = _value;} 
};

class LinkedList {
private:
  Node* head;
  Node* tail;

public:
  LinkedList();
  ~LinkedList();

  void traverse();
  Node* search(int val);
  void insertHead(Node* newNode);
  void insertTail(Node* newNode);
  
};

LinkedList::LinkedList() {
  head = 0;
  tail = 0;
}
LinkedList::~LinkedList() {
  Node* curr = head;
  Node* next = 0;
  while (curr != 0) {
    next = curr->next;
    delete curr;
    curr = next;
  }
}

void LinkedList::traverse() {
  Node* curr = head;
  while (curr != 0) {
    std::cout << curr->value << " " << std::endl;
    curr = curr->next;
  }
}

void LinkedList::insertHead(Node* newNode) {

  if (head !=0)
    newNode->next = head;
  else
    newNode->next = 0;
  
  head=newNode;

  if (tail==0) tail = head;
}

void LinkedList::insertTail(Node* newNode) {
  newNode->next = 0;
  
  if (tail != 0)
    tail->next = newNode;

  if (head ==0)
    head = newNode;

  tail = newNode;
}


Node* LinkedList::search(int val) {
  Node* curr = head;

  while ((curr !=0) && (curr->value) != val)
    curr = curr->next;

  return curr;
}

int main() {

  // Lets define a node
   LinkedList list;

 
   list.insertTail(new Node(2));
   list.insertTail(new Node(3));
   list.insertTail(new Node(4));
   list.insertHead(new Node(8));
   list.insertHead(new Node(81));
   list.insertHead(new Node(45));

   list.traverse();
   
   Node *res = list.search(18);
   if (res != 0) std::cout<<"Found";
   else std::cout << "Not found" << std::endl;
   
 
  
  return 0;
}
