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
  int sumEvens(Node *head); /* return the sum of all even integers in the list. If the list is empty, return 0*/
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*return the sum of all even integers in the list. If the list is empty, return 0*/
int LinkedList::sumEvens(Node *head) {
  int sum = 0;
  Node temp = *head;

  while (temp->next != nullptr) {
    // if it's even
    if (temp->next % 2 == 0) {
      sum += temp->next;
    }
    temp = temp->next;
  }
  return sum;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
  LinkedList llist;
  bool flag=true; 
  while(flag) {
    std::cout << "--------------------------------------------------\n";
    std::cout << "-----ADD:      1\n";
    std::cout << "-----DELETE:   2\n";
    std::cout << "-----SEARCH:   3\n";
    std::cout << "-----PRINT:    4\n";
    std::cout << "-----ADD EVEN: 5\n";
    std::cout << "-----EXIT:     6\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "RES:> ";
    
    std::string response;
    std::string valStr;
    std::string lvalStr;

    std::cin >> response;
    
    switch(stoi(response)) {
    case 1:
      std::cout << "add \n";
      std::cin >> valStr;
      std::cout << "next to \n";
      std::cin >> lvalStr;
      
      llist.insertNode(stoi(lvalStr), stoi(valStr));
      break;
    case 2:
      std::cout << "delete \n";
      std::cin >> valStr;
      llist.deleteNode(stoi(valStr));
      break;
    case 3:
      std::cout << "search for \n";
      std::cin >> valStr;

      Node* res;
      res = llist.search(stoi(valStr));
      if (res != 0) std::cout << valStr << " is in the list\n";
      else std::cout << valStr << " is not in the list\n";

      break;
      
    case 4:
      llist.traverse();
      break;

    case 5:
        res = llist.sumEven(valStr);
        if (res != 0) std::cout << valStr << " is the sum of even values.\n";
        else std::cout <<" There are no even values in the list\n";
        break;



            int main() {
              LinkedList numSum = new Node;

              int values[] = {2, 1, 4, 5, 5, 2, 8};
              int size = 6;
              for (int i = 0; i < size; i++) {
                // values[i] = sumEvens(numSum);
                std::cout << "Sum:" << values[i] << std::endl;
              }
            }

    case 6:
      std::cout << "Goodbye! \n";
      flag = false;
      break;
    }
  }

  return 0;
}
