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
