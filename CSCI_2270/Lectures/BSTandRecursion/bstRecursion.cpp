#include<iostream>

struct Node {
  int key;
  Node* left;
  Node* right;

  Node(int k, Node* l, Node *r) { key = k; left = l; right = r;}
  Node(int k) { key = k; left = right = 0;}
  Node() { key = -1; left = right  = 0;}
};

class BST {
private:
  Node* root;
  
public:
  BST() {root = 0;}
  ~BST() {}

  void insert(int value) {
    Node* tmp = new Node(value);
    Node* curr = root;
    Node* prev;

    if (root == 0) {
      root = tmp;
    }
    else {
      while (curr != 0) {
  	prev = curr;
  	if (value < curr->key) {
  	  curr = curr->left;
  	}
  	else if (value == curr->key) {
  	  return;
  	}
  	else {
  	  curr = curr->right;
  	}
      }
      if (value < prev->key) {
  	prev->left = tmp;
      }

      else {
  	prev->right = tmp;
      }
    }
  }
      
  bool search(int k) {return true;}
  int size() {return 0;}

  void inOrder() {}
  void preOrder() {}
  void postOrder() {}
  
  Node* getMin() {return 0;}
  Node* getMax() {return 0;}

  int getSum() {return 0; }

  /* void insert(int val){} */
  /* void remove(int val){} */
  
private:
  /* helper functions */
  
};

int main() {
  BST T;
  int data[10] = {11, 2, 33, 4, 55, 6, 77, -10, 38, 67};
  
  for (int i = 0; i < 10; i++)   T.insert(data[i]);

  /* 1. First implement search in a BST */
  
  // if (T.search(33)) std::cout << "33 is in the tree" <<std::endl;
  // else std::cout << "33 is not in the tree" << std::endl;

  // if (T.search(23)) std::cout << "23 is in the tree" <<std::endl;
  // else std::cout << "23 is not in the tree" << std::endl;

  /* 2. Implement Size for BST */
  //  std::cout << "size of the tree is " << T.size();


  /* 3. Implement in-order traversal for BST */
  //  T.inOrder();

  /* 4. Implement pre-order traversal for BST */
  //  T.preOrder();

  /* 5. Implement post-order traversal for BST */
  //  T.postOrder();

  /* 6. Implement function to compute minimum value in a BST */
  /* Function getMin should return a pointer to the node with smallest value */
  //  std::cout << "minimum value in the tree is " << T.getMin()->key;

  /* 7. Implement function to compute maximum value in a BST */
  /* Function getMax should return a pointer to the node with largest value */
  //std::cout << "maximum value in the tree is " << T.getMax()->key;
  
  /* 8. Implement a function to sum all values in BST */
  // std::cout << "sum of value in the tree is " << T.getSum();

  /* 9. Implement Recursive "insert" */

  /* 10. Implement recursive"remove" */

}
