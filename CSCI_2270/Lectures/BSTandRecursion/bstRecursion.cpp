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
    BST() { root = 0; }

    ~BST() {}

    /*Insert() starts at root. If smaller, go left, if larger go right
     till it finds the right place to insert.
     * Also keeps pointer to the parent*/
    void insert(int value) {
        Node *tmp = new Node(value);
        Node *curr = root;
        Node *prev;

        if (root == 0) {
            root = tmp;
        } else {
            while (curr != 0) {
                prev = curr;
                if (value < curr->key) {
                    curr = curr->left;
                } else if (value == curr->key) {
                    return;
                } else {
                    curr = curr->right;
                }
            }
            if (value < prev->key) {
                prev->left = tmp;
            } else {
                prev->right = tmp;
            }
        }
    }

    bool search(int k) {
        // ask if it's there or not
        return search(root, k); // search that takes node pointer and a value
    }

    // tells how many elements/nodes are stored already in the tree
    int size() {
        return size(root);
    }

    // print whole tree from the root}
    void inOrder() {
        inOrder(root); // least to greatest!
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

    int getSum() { return 0; }

    /* void insert(int val){} */    // let's do it recursively
    /* void remove(int val){} */    // let's do it recursively
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private:
    /* helper functions */

    // function to go with search(int k) above
    bool search(Node *T, int val) {
        if (T == nullptr) {
            // Tree is empty
            return false;
        } else {
            // Tree has a node an pointers to left and right subtrees
            if (T->key == val) return true;
            else if (val < T->key) return search(T->left, val);
            else return search(T->right, val);
        }
    }

    // for size()
    int size(Node *T) {
        if (T == nullptr) return 0;

            // add up size of left and right plus one to get whole tree
        else return (1 + size(T->left) + size(T->right));
    }

    // for inOrder()
    void inOrder(Node *T) { // pointer to the root
        if (T == 0) return;
        else {
            // print left, print node, print right part
            inOrder(T->left);
            std::cout << T->key << " ";
            inOrder(T->right);
        }
        return;
    }

    // for preOrder()
    void preOrder(Node *T) { // pointer to the root
        if (T == 0) return;
        else {
            // print key, print left, print right part
            std::cout << T->key << " ";
            preOrder(T->left);
            preOrder(T->right);
        }
        return;
    }

    // for postOrder()
    void postOrder(Node *T) { // pointer to the root
        if (T == 0) return;
        else {
            // print left, print right, print key/node
            postOrder(T->left);
            postOrder(T->right);
            std::cout << T->key << " ";
        }
        return;
    }


    // for getMin
    Node *getMin(Node *T) {
        if (T == 0) return nullptr;
        else {
            if (T->left = 0) return T;
            else return getMin(T->left);
        }
    }

    // for getMax
    Node *getMax(Node *T) {
        if (T == 0) return nullptr;
        else {
            if (T->right = 0) return T;
            else return getMax(T->right);
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    BST T; // object T is a BST class
    int data[10] = {11, 2, 33, 4, 55, 6, 77, -10, 38, 67}; // populating tree with these values

    for (int i = 0; i < 10; i++) T.insert(data[i]);

    /* 1. First implement search in a BST */
    if (T.search(33)) std::cout << "33 is in the tree" << std::endl;
    else std::cout << "33 is not in the tree" << std::endl;

    if (T.search(23)) std::cout << "23 is in the tree" << std::endl;
    else std::cout << "23 is not in the tree" << std::endl;


    /* 2. Implement Size for BST */
    std::cout << "size of the tree is " << T.size() << std::endl;


    /* 3. Implement in-order traversal for BST */
    T.inOrder();
    std::cout << std::endl;
    /* 4. Implement pre-order traversal for BST */
    T.preOrder();
    std::cout << std::endl;
    /* 5. Implement post-order traversal for BST */
    T.postOrder();
    std::cout << std::endl;


    /* 6. Implement function to compute minimum value in a BST */
    /* Function getMin should return a pointer to the node with smallest value */
    std::cout << "minimum value in the tree is " << T.getMin()->key << std::endl;

    /* 7. Implement function to compute maximum value in a BST */
    /* Function getMax should return a pointer to the node with largest value */
    std::cout << "maximum value in the tree is " << T.getMax()->key << std::endl;

    /* 8. Implement a function to sum all values in BST */
    // std::cout << "sum of value in the tree is " << T.getSum();

    /* 9. Implement Recursive "insert" */

    /* 10. Implement recursive"remove" */
}
