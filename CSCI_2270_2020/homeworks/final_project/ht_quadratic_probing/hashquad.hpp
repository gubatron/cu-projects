#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

#include <string>

using namespace std;

struct HashNode
{
    int key;
    // struct HashNode *next;
};

class HashTable
{
public:
    HashTable(unsigned int tableSize);               // Constructor
    ~HashTable() { delete[] table; }
    bool insertItem(int key);               // inserts a key into hash table
    unsigned int hashFunction(int key);  // hash function to map values to key
    void printTable();
    int getNumOfCollision();
    HashNode *searchItem(int key);

private:
    unsigned int tableSize; // No. of buckets (linked lists)

    HashNode **table; // Pointer to an array containing buckets
    int numOfcolision = 0;
    HashNode *createhashNode(int key, HashNode *next);
};

#endif