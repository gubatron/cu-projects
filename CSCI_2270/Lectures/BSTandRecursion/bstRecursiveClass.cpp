/**CPPFile*********************************************************************
   FileName    [bstRecursion.cpp] 
   
   PackageName [none]

   Synopsis    [Binary Search Tree using Recursion.]

   Description [
   
   This program implements various functinality of binary search 
   trees using recursive functions. 
   
   A binary search tree (BST) is a special case of a binary tree where the data 
   in the tree is ordered. For any node in the tree, the nodes in the left sub-tree 
   of that node all have a value less than the node value, and the nodes in the 
   right sub-tree of that node all have a value greater than or equal to the node 
   value.
   
   This program implements simple utility functions such as insert, remove, search, 
   size, traversals (in-order, pre-order, and post-order), getMin, getMax, getSum.
   ]    

   SeeAlso     []       

   Author      [Ashutosh Trivedi (ashutosh.trivedi@colorado.edu)]

   Copyright   [ 
   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2 of the License, or (at your option) any
   later version.  
  
   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details
   at http://www.gnu.org/copyleft/gpl.html]

*******************************************************************************/

#include<iostream>

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l, Node *r) {
        key = k;
        left = l;
        right = r;
    }

    Node(int k) {
        key = k;
        left = right = 0;
    }

    Node() {
        key = -1;
        left = right = 0;
    }
};

class BST {
private:
    Node *root;

public:
    BST() {
        // initialize the root to NULL pointer
        root = 0;
    }

    ~BST() {
        // Free the memory used by the BST when you destruct
        recursive_destruct(root);
    }

    Node *search(int k) {
        // search the BST for the value k.
        // It returns the pointer to a node with value $k$ if it exists.
        // OTherwise, it returns 0
        // The helper function search takes a BST and value and searches
        // the BST recursively.
        return search(root, k);
    }

    int size() {
        // Returns the size of th BST
        // It calls the recursive function size that takes a tree and
        // recursively computes its size.
        return size(root);
    }

    void inOrder() {
        inOrder(root);
    }

    void preOrder() {
        preOrder(root);
    }

    void postOrder() {
        postOrder(root);
    }

    Node *getMin() {
        return getMin(root);
    }

    Node *getMax() {
        return getMax(root);
    }

    int getSum() {
        return getSum(root);
    }

    // RECURSIVE
    void insert(int val) {
        insert(root, val);
    }
/////////////// NON RESCURSIVE ///////////////////
//    void insert(int value) {
//        Node *tmp = new Node(value);
//        Node *curr = root;
//        Node *prev;
//
//        if (root == 0) {
//            root = tmp;
//        } else {
//            while (curr != 0) {
//                prev = curr;
//                if (value < curr->key) {
//                    curr = curr->left;
//                } else if (value == curr->key) {
//                    return;
//                } else {
//                    curr = curr->right;
//                }
//            }
//            if (value < prev->key) {
//                prev->left = tmp;
//            } else {
//                prev->right = tmp;
//            }
//        }
//    }

    void remove(int val) {
        remove(root, val);
    }


private:
    void remove(Node *T, int val) {
        if (T == 0) return;
        else {
            if (val < T->key) return remove(T->left, val);
            else if (val > T->key) return remove(T->right, val);
            else {
                // remove value that is equal to the key
                // 4 cases
                // 1. Have no left or right child
                if (T->left == nullptr && T->right == nullptr){
                    delete T;
                    T = nullptr;
                }
                // 2. Only have a left child
                else if (T->left != nullptr && T->right == nullptr) {
                    Node* tmp = T;
                    T = T->left;
                    delete tmp;
                }
                // 3. Only have a right child
                else if (T->left == nullptr && T->right != nullptr){
                    Node* tmp = T;
                    T = T->right;
                    delete tmp.
                }
                // 4. Have both left and right children
                else {
                    Node* to_replace = getMin(T->right);
                    T->key = to_replace->key; // todo could be = to_replace    without ->key
                    remove(T->right, to_replace->key);
                    }
                }
            }
        }
    }

    /* helper functions */
    void insert(Node *&T, int val) { // pass by reference
        if (T == 0) {
            Node *tmp = new Node(val);
            T = tmp;
        } else {
            if (val < T->key) insert(T->left, val);
            else insert(T->right, val);
        }
    }

    int getSum(Node *T) {
        if (T == 0) return 0;
        else return T->key + getSum(T->left) + getSum(T->right);
    }

    void recursive_destruct(Node *T) {
        if (T == 0) return;
        else {
            recursive_destruct(T->left);
            recursive_destruct(T->right);
            delete T;
        }
    }

    Node *getMin(Node *T) {
        if (T == 0) {
            return 0;
        } else {
            if (T->left == 0) return T;
            else return getMin(T->left);
        }
    }

    Node *getMax(Node *T) {
        if (T == 0) {
            return 0;
        } else {
            if (T->right == 0) return T;
            else return getMax(T->right);
        }
    }

    void inOrder(Node *T) {
        if (T == 0) {
            return;
        } else {
            inOrder(T->left);
            std::cout << T->key << " ";
            inOrder(T->right);
        }
        return;
    }

    void preOrder(Node *T) {
        if (T == 0) {
            return;
        } else {
            std::cout << T->key << " ";
            preOrder(T->left);
            preOrder(T->right);
        }
        return;
    }

    void postOrder(Node *T) {
        if (T == 0) {
            return;
        } else {
            postOrder(T->left);
            postOrder(T->right);
            std::cout << T->key << " ";
        }
        return;
    }

    int size(Node *T) {
        if (T == 0) return 0;
        else return (1 + size(T->left) + size(T->right));
    }

    Node *search(Node *T, int val) {
        if (T == 0) {
            // Tree is empty
            return 0;
        } else {
            //Tree has got a node and pointers to left and right sub-trees
            if (T->key == val) return T;
            else if (val < T->key)
                return search(T->left, val);
            else
                return search(T->right, val);
        }
    }
};

int main() {
    BST T;
    int data[10] = {11, 2, 33, 4, 55, 6, 77, -10, 38, 67};

    /* 1. Implement Recursive Insert */
    for (int i = 0; i < 10; i++) T.insert(data[i]);
    T.inOrder();

    /* 2. Implement recursive "remove" */
    T.remove(11);
    T.remove(33);
    T.remove(6);
    T.remove(4);
    T.inOrder();


}
