#ifndef QUEUELL_HPP
#define QUEUELL_HPP

#include <string>

class QueueLL
{
  public:
    struct Node
    {
        Node *next;      
        int key;
    };
  
    QueueLL();
    ~QueueLL();
    bool isEmpty();
    void enqueue(int key);
    void dequeue();
    int peek();

  private:
    // item in list to be dequeued next
    Node* queueFront;
    // item in list that was most recently enqueued
    Node* queueEnd;

};

#endif
