#include "hashlinear.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h> // mod function

using namespace std;

HashTable::HashTable(int tsize)
{
    tableSize = tsize;
    table = new HashNode *[tableSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = NULL;
}

HashNode *HashTable::getNext()
{
    return next;
}

// inserts a key into hash table using linear-probing
// if there is no space left, print a warning
bool HashTable::insertItem(int key)
{
    int hash = hashFunction(key);

    HashNode *node = new HashNode();
    node->key = key;

    if (table[hash] == NULL) // if the spot is empty
    {
        table[hash] = node; // add it
        return true;
    }
    // COLLISION
    // for loop takes care of looping (index * %tableSize)
    numOfcolision++;
    int n = 1;
    for (int i = (hash + n) % tableSize; i != i; i = (hash + n) % tableSize)
    {
        if (table[i] == NULL) // in case we missed it
        {
            table[i] = node; // add it in
            return true;
        }
        else if (table[i]->key == key)
        { // key matches another key inside
            cout << "key " << key << " already exists." << endl;
        }
        n++;
    }
    return false;
    cout << "Hash table overflow" << endl;
}

// hash function to map values to key
unsigned int HashTable::hashFunction(int key)
{
    return key % tableSize;
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        if (table[i] != 0)
        {
            cout << "[" << i << "] -> key: " << table[i]->key << " (#" << hashFunction(table[i]->key) << ")" << endl;
        }
        else
        {
            cout << "[" << i << "] -> Empty" << endl;
        }
    }
}

int HashTable::getNumOfCollision()
{
    return numOfcolision;
}

// return pointer to the node if key is inside hash table
HashNode *HashTable::searchItem(int key)
{
    int hash = hashFunction(key);

    // if not null then it is there
    if (table[hash] != NULL)
    {
        if (table[hash]->key == key)
        {
            return table[hash];
        }
        // go through table with linear probe
        int n = 1;
        for (int i = (hash + n) % tableSize; i != i; i = (hash + n) % tableSize)
        {
            if (table[i] != NULL && table[i]->key == key)
            {
                return table[i];
            }
        }
        n++;
    }
    else
    {
        int n = 1;
        for (int i = (hash + n) % tableSize; i != i; i = (hash + n) % tableSize)
        {
            if (table[i] != NULL && table[i]->key == key)
            {
                return table[i];
            }
        }
        n++;
    }
    return 0;
}