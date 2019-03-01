struct Node {
  int data;        /* Data field */
  Node *next;       /* Next pointer */
  Node *prev;       /* Previous pointer */
  
  Node() {          /* Default Constructor */
    data = -1;
    next = 0;
    prev = 0;
  }
  Node(int data_){  /* Fills data field  */
    data = data_;
    next = 0;
    prev = 0;
  }
  Node(int data_, Node* next_){ /* Fills data and next fields */
    data = data_;
    next = next_;
  }
  Node(int data_, Node* next_, Node* prev_){ /* Fills all fields */
    data = data_;
    next = next_;
    prev = prev_;
  }
};

class DLLinkedList {
private:
  Node* head;
  Node* tail;

public:
  DLLinkedList();      /* Constructor */
  ~DLLinkedList();     /* Destructor */

  void traverse();         /* Traverse and print the list */ 
  Node* search(int val);    /* Search the list to find a value */
  void insertNode(int leftValue, int value); /* Insert a node in the list */
  void deleteNode(int value); /* delete the value from the list*/
};
