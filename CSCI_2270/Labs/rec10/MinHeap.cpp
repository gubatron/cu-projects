#include "MinHeap.hpp"
#include <limits.h>

using namespace std;

/*
Swaps two integer values
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Constructor for our MinHeap implementation
*/
MinHeap::MinHeap(int cap) {
    currentSize = 0;
    capacity = cap;
    heapArr = new int[capacity];
}

/*
Finds the parent of a node, given its index.
*/
int MinHeap::parent(int index) {
    return (index - 1) / 2;
}

/*
Returns the left child of a node.
*/
int MinHeap::leftChild(int index) {
    return ((2 * index) + 1);
}

/*
Returns the right child of a node.
*/
int MinHeap::rightChild(int index) {
    return ((2 * index) + 2);
}

/*
Returns the smallest element from the heap.
*/
int MinHeap::getMin() {
    return heapArr[0];
}

/*
To heapify a subtree with the root at given index
*/
void MinHeap::heapify(int root) {
    int smallest = root;

    if (leftChild(root) < currentSize) {
        if (heapArr[smallest] > heapArr[leftChild(root)]) {
            smallest = leftChild(root);
        }
    }
    if (rightChild(root) < currentSize) {
        if (heapArr[smallest] > heapArr[rightChild(root)]) {
            smallest = rightChild(root);
        }
    }

    if (smallest == root) return;
    else {
        swap(heapArr[smallest], heapArr[root]);
        heapify(smallest);
    }
}

/*
Inserts an element into the heap by maintaining the heap property.
*/
void MinHeap::insertElement(int value) {
    if (currentSize == capacity) {
        cout << "Maximum heap size reached. Cannot insert anymore" << endl;
        return;
    }

    currentSize = currentSize + 1;
    int index = currentSize - 1;
    heapArr[index] = value;

    while (index != 0 && heapArr[parent(index)] > heapArr[index]) {
        swap(&heapArr[index], &heapArr[parent(index)]);
        index = parent(index);
    }
}

/*
Prints the elements in the heap
*/
void MinHeap::print() {
    int iter = 0;
    while (iter < currentSize) {
        cout << heapArr[iter] << " ";
        iter = iter + 1;
    }
    cout << endl;
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
    if (currentSize <= 0)
        return INT_MAX;

    if (currentSize == 1) {
        currentSize--;
        return heapArr[0];
    }

    int minimum = heapArr[0];
    heapArr[0] = heapArr[currentSize - 1];
    currentSize--; // bc we removed one element.
    heapify(0);

    return minimum;
}

// GOLD TODO : Complete this function
// This function deletes a key
//void MinHeap::deleteKey(int key) {
//    // there are many ways of doing it, one of them can be :
//    // replace the key to be deleted with INT_MIN (a very small number), traverse it up to the root and then remove it!
//    if (currentSize <= 0)
//        return;
//
//    if (currentSize == 1) {
//        currentSize--;
//        return;
//    }
//
//    int root = heapArr[0];
//    heapArr[key] = heapArr[rightChild(key)];
//    int int_min = heapArr[key];
//    currentSize--;
//    root = key / 2;
//
//    if (key == 0 || heapArr[root] < heapArr[key]) heapify(key);
//    heapify(key);
//}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////


int main() {
    MinHeap heap(10);
    heap.insertElement(9);
    heap.insertElement(13);
    heap.insertElement(10);
    heap.insertElement(14);
    heap.insertElement(15);
    heap.insertElement(12);
    heap.insertElement(11);
    heap.insertElement(8);

    cout << "***********Elements in the heap are **********" << endl;
    heap.print();
    cout << endl;

    cout << "Smallest element extracted is: " << heap.extractMin() << endl << endl;
    cout << "***********Elements in the heap after extracting the smallest element**********" << endl;
    heap.print();
    cout << endl;

  int key = 15;
    cout << "Deleting a key from the heap: " << endl << endl;
    heap.deleteKey(key);
    cout << "***********Elements in the heap after deleting the key**********" << endl;
    heap.print();

    cout << endl;
    return 0;
}
