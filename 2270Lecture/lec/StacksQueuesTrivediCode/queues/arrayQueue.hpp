#pragma once

#define DEFAULT_SIZE 5


/*
  head-> [1|2|3|4|5] <-tail
*/

class ArrayQueue {
private:
  int capacity;
  int* items;
  int head;
  int tail;
  int size;
  
public:
  ArrayQueue();  /* Constructor with capacity DEFAULT_SIZE */
  ArrayQueue(int cap); /* Constructor with capacity */
  ~ArrayQueue(); /* Destructor */

  bool isEmpty(); /* True, if queue is empty */ 
  bool isFull();  /* True, if queue is full  */
  int getSize(); /* return the size of the Queue */
  void enqueue(int element); /* Enqueue an element to the queue */
  int dequeue(); /* Dequeue an element from the queue */
  int peek(); /* Return the element at the head of the queue  */
  void prettyPrint(); /* print the queue */ 
};
