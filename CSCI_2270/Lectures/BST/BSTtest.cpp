//
// Created by Nicole Leon on 2/25/2019.
//

#include <iostream>

struct Node {
    int key;
    Node *left;
    Node *right;

    Node() {
        key = -1;
        left = 0;
        right = 0;
    }

    Node(int k) {
        key = k;
        left = 0;
        right = 0;
    }

    ~Node() {}
};

class BST {
private:
    Node *root;

public:
    BST() { root = 0; } /*constructor*/
    ~BST() {};          /*destructor*/

    /////////////////////////////////////////////////////////////////////////////////
    /* INSERT */
    /////////////////////////////////////////////////////////////////////////////////
    void insert(int val) {
        Node *tmp = new Node(val);

        if (root == nullptr) {
            /*tree is empty*/
            /*new root will point to tmp now*/
            root = tmp;
            return;
        } else {
            Node *curr = root;
            Node *prev = nullptr;

            while (curr != nullptr) {
                if (val < curr->key) {
                    /*we need to insert ot the left of this node*/
                    prev = curr;
                    curr = curr->left;
                } else {
                    /*we need to insert ot the right of this node*/
                    prev = curr;
                    curr = curr->right;
                }
            }
            /*curr is pointing to NULL*/
            /*prev is pointing to end of the tree, parent of temp, the node I'm trying to insert*/
            if (val < prev->key){
                prev->left = tmp;
            } else {
                prev->right = tmp;
            }
        }
        return;
    }
    /////////////////////////////////////////////////////////////////////////////////
    /* SEARCH */
    /*start at the root and keep a temp pointer
     * if value is = then done
     * if value is < then go left
     * if value is > them go right
     * move tmp to this node and keep doing the comparison until it's =
     * if you get to the end and left or right are nullptrs then value is not in tree*/
    /////////////////////////////////////////////////////////////////////////////////
    void search(int val) {
        Node *tmp = root;

        while (tmp != nullptr) {
            if (tmp->key == val) {
                /*Yay we found the value*/
                std::cout << "The value " << val << " is in the tree" << std::endl;
                return;
            }
            else if(val < tmp->key) {
                /*Val is not in the right sub-tree*/
                /*if it is at all there, it must be in the left sub-tree*/
                tmp = tmp->left;
            }
            else {
                tmp = tmp->right;
            }
        }
        std::cout << "The value " << val << " is not in the tree" << std::endl;
    }
};


int main() {
    BST T;
    T.insert(11);
    T.insert(5);
    T.insert(33);
    T.insert(22);
    T.insert(45);

    T.search(11);

    T.search(49);

}