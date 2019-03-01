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

