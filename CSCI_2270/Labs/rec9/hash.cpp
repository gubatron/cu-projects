// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node *HashTable::createNode(int key, node *next) {
    node *nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize) {
    this->tableSize = bsize;
    table = new node *[tableSize];
    for (int i = 0; i < bsize; i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key) {
    return static_cast<unsigned int>(key % tableSize);

}

//function to search
node *HashTable::searchItem(int key) {
    //Compute the index by using the hash function
    int index = hashFunction(key);

    //Search the list at that specific index and return the node if found
    node *tmp = table[index];

    while (tmp != nullptr) {
        // does tmp's key match my key?
        if (tmp->key == key) return tmp; // found it!
        tmp = tmp->next; // nope, keep searching
    }
    // if empty or no key
    return nullptr;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key) {
    int index = hashFunction(key);

    auto tmp = new node(); //allocating new node on heap
    tmp = createNode(key, tmp->next);

    if (table[index] == nullptr) table[index] = tmp;
    else {
        // traverse table and find where key needs to be inserted
        node *curr = table[index];
        node *prev = nullptr;

        while (curr != nullptr) {   /*scan list from left to right*/
            if (curr->key == key) {
                cout << "duplicate entry: " << key << endl;
                return false;
            } else if (!searchItem(key)) {
                prev = curr;
                curr = curr->next;
            }
        }
        // insert node I'm trying to insert right now after the current
        prev->next = tmp; // will never reach this part while prev == nullptr
    }
}

// function to display hash table
void HashTable::printTable() {
    for (int i = 0; i < tableSize; i++) {
        if (table[i] != nullptr) {
            cout << i << "|| ";
            node *curr = table[i];
            while (curr != nullptr) {
                cout << "-> Key: " << curr->key << " (#" << hashFunction(curr->key);
                curr = curr->next;
            }
            cout << endl;
        } else {
            cout << i << "|| -> Empty" << endl;
        }
    }
}
