//
// Created by Nicole Leon on 2/20/2019.
//

#include <iostream>

// PROBLEM 3


class CircularArrayQueue {
private:
    int capacity;
    int* items;
    int head;
    int tail;


public:
    CircularArrayQueue();  /* Constructor with capacity DEFAULT_SIZE */
    CircularArrayQueue(int cap); /* Constructor with capacity */
    ~CircularArrayQueue(); /* Destructor */

    bool isEmpty(); /* True, if queue is empty */
    bool isFull();  /* True, if queue is full  */
    int getSize(); /* return the size of the Queue */
    void enqueue(int element); /* Enqueue an element to the queue */
    int dequeue(); /* Dequeue an element from the queue */

    int peek(); /* Return the element at the head of the queue  */
    void print(); /* print the queue */
    Node* shift(Node *tail, int n); // example declaration
};

CircularArrayQueue::CircularArrayQueue() {
    capacity = DEFAULT_SIZE;
    head = -1;
    tail = -1;
    items = new int[capacity];
}

CircularArrayQueue::CircularArrayQueue(int cap) {
    capacity = cap;
    head = -1;
    tail = -1;
    items = new int[capacity];
}

CircularArrayQueue::~CircularArrayQueue() {
    delete[] items;
}

bool CircularArrayQueue::isEmpty() {
    return (head == -1);
}

bool CircularArrayQueue::isFull() {
    return (getSize() == capacity);
}

int CircularArrayQueue::getSize() {
    if (head <= tail) {
        return (tail - head +1);
    }
    else {
        return capacity - (head - tail) + 1;
    }
}

void CircularArrayQueue::enqueue(int element) {
    /* your code goes here */
}

int CircularArrayQueue::dequeue() {
    /* your code goes here */
}

int CircularArrayQueue::peek() {
    if (isEmpty()) {
        std::cerr << "Queue Empty!! Returning garbarge" << std::endl;
        return -1;
    }
    else {
        return items[head];
    }
}

void CircularArrayQueue::print() {
    if (isEmpty()) {
        std::cout << "head->[]<-tail" << std::endl;;
    }
    else {
        std::cout << "head->[";
        if (head <= tail) {
            for (int i = head; i <= tail; i++) {
                std::cout << items[i] << " ";
            }
        }
        else {
            for (int i = head; i < capacity; i++) {
                std::cout << items[i] << " ";
            }
            for (int i = 0; i <= tail; i++) {
                std::cout << items[i] << " ";
            }
        }
        std::cout << "]<-tail"<<std::endl;
    }
}

//void CircularArrayQueue::prettyPrintCircular() {
//    if (isEmpty()) {
//        std::cout << "head->[]<-tail" << std::endl;;
//    }
//    else {
//        std::cout << "[";
//        for (int i = 0; i < capacity; i++) {
//            if (head <= tail) {
//                if (i >= head && i <= tail) {
//                    if ((i == head) && (i == tail)) std::cout << "#"<<items[i]<<"* ";
//                    else if (i == head) std::cout << items[i] <<"* ";
//                    else if (i == tail) std::cout << "#"<<items[i];
//                    else std::cout << items[i] << " ";
//                }
//                else std::cout << "B ";
//            }
//            else {
//                if (i <= tail || i >= head) {
//                    if ((i == head) && (i == tail)) std::cout << "#"<<items[i]<<"* ";
//                    else if (i == head) std::cout << items[i] <<"* ";
//                    else if (i == tail) std::cout << "#"<<items[i];
//                    else std::cout << items[i] << " ";
//                }
//                else std::cout << "B ";
//            }
//        }
//        std::cout << "]"<<std::endl;
//    }
//}


Node* CircularArrayQueue::shift(Node *tail, int n) {

}