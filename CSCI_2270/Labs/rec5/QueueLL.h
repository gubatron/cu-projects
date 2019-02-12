#ifndef QUEUELL_H
#define QUEUELL_H

#include <string>

class QueueLL
{
private:
    struct Node
    {
        int key;
        Node *next;
    };

    // item in list to be dequeued next
    Node* queueFront = nullptr;
    // item in list that was most recently enqueued
    Node* queueEnd = nullptr;

public:
    QueueLL() {
        queueFront = nullptr;
        queueEnd = nullptr;
    }

    ~QueueLL() {
        while (!isEmpty())
            dequeue();
    }

    bool isEmpty() {
        return queueFront == nullptr || queueEnd == nullptr;
    }

    void enqueue(int key) {
        Node *nn = new Node;
        nn->key = key;
        nn->next = nullptr;

        // if queue is empty, new node is both front and rear
        if (isEmpty()) { //(queueEnd == nullptr)
            queueFront = queueEnd = nn;
            return;
        }
        // add the new node at the end of queue and change rear
        queueEnd->next = nn;
        queueEnd = nn;
    }

    void dequeue() {
        if (!isEmpty()) {
            // store previous front and move front one node ahead
            Node *temp = queueFront;
            queueFront = queueFront->next;

            //if front becomes empty, then rear becomes empty too (null)
            if (queueFront == nullptr) {
                queueEnd = nullptr;
            }
            delete temp;
        } else {
            std::cout << "queue is empty. can not deque" << std::endl;
        }
    }

    int peek() {
        if (!isEmpty())
            return queueFront->key;
        else {
            std::cout << " queue is empty. can not peek" << std::endl;
            return -1;
        }
        //return 0;
    }
};

#endif
