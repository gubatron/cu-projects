#include "hashchain.hpp"
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

// inserts a key into hash table using linear-probing
// if there is no space left, print a warning
bool HashTable::insertItem(int key)
{
    int hash = hashFunction(key);

    HashNode *node = new HashNode();
    node->key = key;
    node->next = NULL;

    if (table[hash] == NULL) // if the spot is empty
    {
        table[hash] = node; // add it
        cout << "adding node: [" << node << "]" <<  endl;
        return true;
    }
    // COLLISION
    // chaining - linked
    numOfcolision++;
    HashNode *temp = table[hash];
    while (temp->next != NULL)
    {
        temp = temp->next;
        return true;
    }
    if (temp->key == key)
    {
        cout << "key " << key << " already exists." << endl;
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
        HashNode *temp = table[hash];
        while (temp != NULL && temp->key != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "[temp == NULL] -- Node not found in hash table" << endl;
            return 0;
        }
        else
            return hash[table];
    }
    // else, it's not there
    cout << "Node not found in hash table" << endl;
    return 0;
}