#include<iostream>

using namespace std;
#define COUNT 10


class MinHeap {
private:
    int *heap;
    int capacity;
    int currentSize;

public:
    MinHeap() {
        capacity = 10;
        currentSize = 0;
        heap = new int[capacity];
    }

    MinHeap(int s) {
        capacity = s;
        currentSize = 0;
        heap = new int[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void push(int value) {
        if (currentSize == capacity) { // full, can't put anything else inside
            cout << "Heap overflow" << endl;
        } else {
            // insert a value in a heap
            currentSize++; // we added one element.
            heap[currentSize - 1] = value;
            int i = currentSize - 1;
            // use loop to traverse. Keep on swapping upward until you reach the 0th index
            // or find that parent has a value index smaller than you
            while (parent(i) >= 0 && heap[parent(i)] > heap[i]) {
                // keep on swapping elements
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }
    }

    int pop() {
        if (currentSize <= 0) {
            cout << " Heap is empty: returning garbage" << endl;
            return -1;
        } else {
            // delete value from the heap while keeping the heap property
            int result = heap[0];
            heap[0] = heap[currentSize - 1];
            currentSize--; // we removed one element.
            minHeapify(0);
            return 0;
        }
    }

    int peek() {
        if (currentSize <= 0) {
            cout << " Heap is empty: returning garbage" << endl;
            return -1;
        } else return heap[0];
    }

    //print a heap in text
    void printHeap() {
        print2DUtil(0, 0);
    }

private:
    void print2DUtil(int root, int space) {
        if (root >= currentSize)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        if (rightChild(root) < currentSize)
            print2DUtil(rightChild(root), space);


        // Print current node after space
        // count
        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << heap[root] << "\n";

        // Process left child
        if (leftChild(root) < currentSize)
            print2DUtil(leftChild(root), space);
    }

    void minHeapify(int root) {
        // Recursive program to maintain the heap property:
        // required for  "pop"
        int min = root;
        // compare both index of the the children
        if (leftChild(root) < currentSize) {
            if (heap[min] > heap[leftChild(root)])
                min = leftChild(root);
        }
        if (rightChild(root) < currentSize) {
            if (heap[min] > heap[rightChild(root)])
                min = rightChild(root);
        }

        if (min == root) return;
        else {
            swap(heap[min], heap[root]);
            minHeapify(min);
        }

    }

    int parent(int index) { return (index - 1) / 2; }

    int leftChild(int index) { return 2 * index + 1; }

    int rightChild(int index) { return 2 * index + 2; }

    void swap(int &x, int &y) {
        int z = x;
        x = y;
        y = z;
    } // pass by reference

};

int main() {
    MinHeap MH(20);
    int array[10] = {40, 11, 4, 16, 42, 18, 19, 21, 15, 9};

    for (int i = 0; i < 10; i++) {
        // E1. Implement a push in the heap
        //     MH.push(array[i]);

    }

    for (int i = 0; i < 10; i++) {
        // print after each element is added
        cout << "=====================================================" << endl;
        MH.printHeap();
        cout << "=====================================================" << endl;
        getchar();
    }

    cout << "=====================================================" << endl;
    MH.printHeap();
    cout << "=====================================================" << endl;
    getchar();
    for (int i = 0; i < 10; i++) {
        // E2. Implement a pop from the heap
        //    cout << MH.pop() << " ";
    }
    //  cout << endl;

    return 0;
}
