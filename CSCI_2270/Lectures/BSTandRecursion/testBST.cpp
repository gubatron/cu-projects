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
    BST() { root = 0; }

    ~BST() {}


    void insert(int val) {
        Node *tmp = new Node(val);


        if (root == 0) {
            /* tree is empty */
            /* new root will point to tmp now */
            root = tmp;
            return;
        } else {
            Node *curr = root;
            Node *prev = 0;
            while (curr != 0) {
                if (val < curr->key) {
                    /* We need to insert to the left of this node */
                    prev = curr;
                    curr = curr->left;
                } else {
                    /* We need to insert to the right of this node */
                    prev = curr;
                    curr = curr->right;
                }
            }
            //  curr is pointing to NULL
            // prev is pointing to the parent of tmp

            if (val < prev->key) {
                prev->left = tmp;
            } else {
                prev->right = tmp;
            }
        }
        return;
    }

    void search(int val) {
        Node *tmp = root;

        while (tmp != 0) {
            if (tmp->key == val) {
                /* Yay we found the value */
                std::cout << "The value " << val << " is in the tree" << std::endl;
                return;
            } else if (val < tmp->key) {
                /* Val is not in the right sub-tree */
                /* if it is at all there, it must be in the left sub-tree */
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
        std::cout << "The value " << val << " is NOT in the tree" << std::endl;
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
