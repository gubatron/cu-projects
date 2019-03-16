#include<iostream>
using namespace std;

#define COUNT 10


class MaxHeap {
private:
  int* heap;
  int capacity;
  int currentSize;

public:
  MaxHeap() {
    capacity = 10;
    currentSize = 0;
    heap = new int[capacity];
  }

  MaxHeap(int s) {
    capacity = s;
    currentSize = 0;
    heap = new int[capacity];
  }
  
  ~MaxHeap() {
    delete[] heap;
  }
  
  void push(int value) {
    if (currentSize == capacity) {
      cout << "Heap overflow" << endl;
    }
    else {
      // Implement push in a max heap
    }
  }
  
  int pop() {
    if (currentSize <= 0) {
      cout << " Heap is empty: returning garbage" << endl;
      return -1;
    }
    else {
      // Implement a pop from a max heap
      return -1;
    }
  }

  int peek() {
    if (currentSize <= 0) {
      cout << " Heap is empty: returning garbage" << endl;
      return -1;
    }
    else return heap[0];
  }

  void printHeap() {
    print2DUtil(0, 0);
  }

private:
  void print2DUtil(int root, int space){
    if (root >= currentSize)
      return;
    
    // Increase distance between levels
    space += COUNT;

    // Process right child first
    if (rightChild(root) < currentSize)
      print2DUtil(rightChild(root), space);
    

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
      cout<<" ";
    cout<<heap[root]<<"\n";

    // Process left child
    if (leftChild(root) < currentSize)
      print2DUtil(leftChild(root), space);
  }
  void maxHeapify(int index) {
    // Recursive program to maintain the max-heap property:
    // reqired for  "pop"
  }
  int parent(int index) {return (index-1)/2;}
  int leftChild(int index) {return 2*index+1;}
  int rightChild(int index) {return 2*index+2;}
  void swap(int &x, int &y) {int z = x; x = y; y = z;}

};

int main() {
  MaxHeap MH(20);
  int array[10] = {11, 4, 16, 18, 19, 15, 9};

  for (int i = 0; i < 10; i++) {
    // E3. Implement a push in a maxHeap 
    //    MH.push(array[i]);
  }
  cout << "====================================================="<<endl;
  MH.printHeap();
  cout << "====================================================="<<endl;
  getchar();
  
  for (int i = 0; i < 10; i++) {
    // E4. Implement a pop in a maxHeap
    //    cout << MH.pop() << " ";
  }
  
  // cout << endl;
  
  return 0;
}
