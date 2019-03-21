#include<iostream>

using namespace std;

#define COUNT 10

class MaxHeap {
private:
    int *heap;
    int capacity;
    int currentSize;

public:
    MaxHeap() {
        capacity = 10;
        currentSize = 0;
        heap = new int[capacity];
    }

    MaxHeap(int c) {
        capacity = c;
        currentSize = 0;
        heap = new int[capacity];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void push(int value) {
        if (currentSize == capacity) { // full, can't put anything else inside
            cout << "Heap overflow" << endl;
        } else {
            // insert a value in a heap

        }
    }

    int pop() {
        // give element of minimum priority

    }

    int peek() {
        if (currentSize <= 0) {
            cout << " Heap is empty: returning garbage" << endl;
            return -1;
        } else return heap[0];
    }

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

    void maxHeapify(int root) {
        // Recursive program to maintain the max-heap property:
        // required for  "pop"

    }

    int parent(int index) { return (index - 1) / 2; } // DOESN'T CHECK FOR A NEGATIVE INDEX!!!

    int leftChild(int index) { return 2 * index + 1; }

    int rightChild(int index) { return 2 * index + 2; }

    void swap(int &x, int &y) {
        int z = x;
        x = y;
        y = z;
    }

};

int main() {
    MaxHeap MH(10);
    int array[10] = {11, 4, 16, 18, 19, 15, 9};

    for (int i = 0; i < 10; i++) {
        // E3. Implement a push in a maxHeap
        MH.push(array[i]);
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
        // E4. Implement a pop in a maxHeap
        cout << MH.pop() << " ";
    }

    // cout << endl;

    return 0;
}
