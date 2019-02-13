#ifndef STACKLL_H
#define STACKLL_H

class StackLL {
private:
    struct Node {
        char key;
        Node *next;
    };

    // pocharer to item to be popped next
    Node *stackHead;

public:
    StackLL() {
        stackHead = nullptr;
    }

    ~StackLL() {
        while (!isEmpty())
            pop();
    }

    bool isEmpty() {
        return (stackHead == nullptr);
    }

    void push(char key) {
        Node *nn = new Node;
        nn->key = key;
        nn->next = nullptr;
        nn->next = stackHead;
        stackHead = nn;
    }

    void pop() {
        if (!isEmpty()) {
            Node *temp = stackHead;
            stackHead = stackHead->next;
            delete temp;
        } else {
            std::cout << "empty stack. can not pop" << std::endl;
        }
    }

    char peek() {
        if (!isEmpty())
            return stackHead->key;
        else {
            std::cout << "empty stack. can not peek" << std::endl;
            return -1;
        }
        //return 0;
    }
};

#endif
