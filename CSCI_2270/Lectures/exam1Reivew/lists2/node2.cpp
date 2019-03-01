struct Node {
  int data;        /* Data field */
  Node *next;       /* Next pointer */
  
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
