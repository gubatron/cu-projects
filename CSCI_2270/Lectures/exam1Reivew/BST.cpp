#include<iostream>

struct Node {
  int key;
  Node* parent;
  Node* leftChild;
  Node* rightChild;

  Node() {key = -1; leftChild = 0; rightChild = 0; parent = 0;}
  Node(int _key) {key = _key; leftChild = 0; rightChild = 0; parent = 0;}
  ~Node() {}
};


/**********************************************************
 * Binary Tree: 
 *     A tree is either "empty" or is a node with a "key" and pointers to a left sub-tree and a right sub-tree;
 *      T: Tree if T = NULL or T = N(v, T1, T2) 
 *     1. emptry tree:  root = NULL;
 *     2. tree with only one node 
 *     3. tree with both left and right children
 *
 **********************************************************/

class BinaryTree {
private:
  Node* root;

public:
  BinaryTree() {root = 0;}
  ~BinaryTree(){}
  
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
	  curr = curr->leftChild;
	}
	else if (value == curr->key) {
	  return;
	}
	else {
	  curr = curr->rightChild;
	}
      }
      if (value < prev->key) {
	prev->leftChild = tmp;
	tmp->parent = prev;
      }
      else {
	prev->rightChild = tmp;
	tmp->parent = prev;
      }
    }
  }

  void search(int value) {
    Node* tmp = root;

    if (tmp == 0) {
      std::cout << "Value not found" << std::endl;
      return;
    }
    if (value == tmp->key) {
      std::cout << " Value is in the tree" << std::endl;
      return;
    }
    
    while (tmp != 0) {
      if (value == tmp->key) {
	std::cout << " Value is in the tree" << std::endl;
	return;
      }
      else if (value < tmp->key) {
	tmp = tmp->leftChild;
      }
      else {
	tmp = tmp->rightChild;
      }
    }
    std::cout << "Value not found" << std::endl;
    return;
  }
};

int main (int argc, char* argv[]) {
  BinaryTree T;

  T.insert(22);
  T.insert(33);
  T.insert(44);
  T.insert(55);
  T.insert(21);
  T.search(22);
  T.search(29);
  
  return 0;
}
