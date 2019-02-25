//
// Created by Nicole Leon on 2/20/2019.
//

#include <iostream>

// Creating a linked list and adding to it
struct Node {
    int data;
    Node *next;

    Node() {          /* Default Constructor */
        data = -1;
        next = 0;
    }

    Node(int data_) {  /* Fills data field  */
        data = data_;
        next = 0;
    }

    Node(int data_, Node *next_) { /* Fills both fields */
        data = data_;
        next = next_;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node *curr;
        Node *next;

        curr = next = head;

        while (curr != 0) {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void print() {
        Node *curr;

        std::cout << "head->";

        for (curr = head; curr != 0; curr = curr->next) {
            std::cout << curr->data << "->";
        }

        std::cout << "tail" << std::endl;
    }

    // searches and returns how many numbers are in the list
    Node *search(int val) {
        Node *curr = head;
        int count = 0; // every time it finds a value, increase count

        while (curr != nullptr) {
            count++; // increase count
            if (curr->data == val) return count;
            curr = curr->next;
        }
        return count;
    }


    void insertNode(int leftValue, int value) {
        Node *left = search(leftValue);
        Node *node = new Node(value);

        if (left == 0) {                    /* inserting a new head node */
            node->next = head;
            head = node;
            if (tail == 0) tail = head;
        } else if (left->next == 0) {         /* inserting a new tail node */
            left->next = node;
            tail = node;
        } else {                              /* inserting a node in the middle */
            node->next = left->next;
            left->next = node;
        }
    }


    void deleteNode(int value) {
        if (head->data == value) {
            Node *temp = head;
            head = head->next;
            delete temp;
        } else { /*either tail node or middle node */
            Node *prev = head;
            Node *curr = prev->next;
            bool isFound = false;
            while (curr != 0 && isFound != true) {
                if (curr->data == value) {
                    if (curr->next == 0) { /* tail node */
                        prev->next = 0;
                        tail = prev;
                    } else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    isFound = true;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }
};


// param ptr to head of the linked list
// return true if number of nodes == even; false otherwise
bool lengthIsEven(Node *head) {
    numNodes = search(head);
    if (numNodes % 2 == 0) {
        // even?
        if (numNodes == 0){
            return false; // false if there are zero values in the list
        }
        return true;
    }
    return false;
}

// creates linked list of integers
// calls lengthIsEven on multiple lists;
int main() {
    LinkedList list;

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);


    list.insertNode(nullptr, first);
    lengthIsEven(first); // 1 - false

    list.insertNode(first, second);
    lengthIsEven(second); // 2 - true;

    list.insertNode(second, third);
    lengthIsEven(third); // 3 - false;

}