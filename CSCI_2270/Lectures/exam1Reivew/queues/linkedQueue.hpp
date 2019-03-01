#pragma once

#define DEFAULT_SIZE 5


/*
  tail-> [1|2|3|4|5] <-head
*/

struct QueueNode {
  int item; 
  QueueNode* next;

  QueueNode() {item = -1; next = 0;}
  QueueNode(int element) {item = element; next = 0;}
};

class LinkedQueue {
private:
  int capacity;
  QueueNode* head;
  QueueNode* tail;
  int size;
  
public:
  LinkedQueue();  /* Constructor with capacity DEFAULT_SIZE */
  LinkedQueue(int cap); /* Constructor with capacity */
  ~LinkedQueue(); /* Destructor */

  bool isEmpty(); /* True, if queue is empty */ 
  bool isFull();  /* True, if queue is full  */
  int getSize(); /* return the size of the Queue */
  void enqueue(int element); /* Enqueue an element to the queue */
  int dequeue(); /* Dequeue an element from the queue */
  int peek(); /* Return the element at the head of the queue  */
  void prettyPrint(); /* print the queue */ 
};
