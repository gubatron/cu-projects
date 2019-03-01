#include<iostream>
struct Node {
  int data;
  Node* next;

  Node() {          /* Default Constructor */
    data = -1;
    next = 0;
  }
  Node(int data_){  /* Fills data field  */
    data = data_;
    next = 0;
  }
  Node(int data_, Node* next_){ /* Fills both fields */
    data = data_;
    next = next_;
  }
};

class LinkedList {
private:
  Node* head;
  Node* tail;

public:
  LinkedList();      /* Constructor */
  ~LinkedList();     /* Destructor */

  void traverse();         /* Traverse and print the list */ 
  Node* search(int val);    /* Search the list to find a value */
  void insertNode(int leftValue, int value); /* Insert a node in the list */
  void deleteNode(int value); /* delete the value from the list*/
};

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
  // Implement your insertion here 
}

void LinkedList::deleteNode(int value) {
  // implement your deletion here 
}

int main() {
  LinkedList llist;
  bool flag=true; 
  while(flag) {
    std::cout << "--------------------------------------------------\n";
    std::cout << "-----ADD:    1\n";
    std::cout << "-----DELETE: 2\n";
    std::cout << "-----SEARCH: 3\n";
    std::cout << "-----PRINT:  4\n";
    std::cout << "-----EXIT:   5\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "RES:> ";
    
    std::string response;
    std::string valStr;
    std::string lvalStr;

    std::cin >> response;
    
    switch(stoi(response)) {
    case 1:
      std::cout << "What number you wish to add? \n";
      std::cin >> valStr;
      std::cout << "What is the left value? \n";
      std::cin >> lvalStr;
      
      llist.insertNode(stoi(lvalStr), stoi(valStr));
      break;
    case 2:
      std::cout << "What number you wish to delete? \n";
      std::cin >> valStr;
      llist.deleteNode(stoi(valStr));
      break;
    case 3:
      std::cout << "What number you wish to  search for? \n";
      std::cin >> valStr;

      Node* res;
      res = llist.search(stoi(valStr));
      if (res != 0) std::cout << " The value " << valStr << " is in the list\n";
      else std::cout << " The value " << valStr << " is not in the list\n";

      break;
      
    case 4:
      llist.traverse();
      break;
      
    case 5:
      std::cout << "Goodbye! \n";
      flag = false;
      break;
    }
  }

  return 0;
}
