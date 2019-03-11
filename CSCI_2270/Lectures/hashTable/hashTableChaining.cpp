#include <utility>

#include<iostream>
#include<fstream>
#include<sstream>
#include <math.h>       /* modf */

/*CHAINING IS SLIGHTLY EASIER THAN PROBING*/

using namespace std;

struct HashNode {
    string key;       // student id, name or whatever
    string value;     // value assigned to it
    HashNode *next;

    HashNode() {
        key = "";
        value = "";
        next = nullptr;
    }

    HashNode(string k, string v) {
        key = std::move(k);
        value = std::move(v);
        next = nullptr;
    }

    ~HashNode() {}
};

class HashTable {
    HashNode **table; // double pointer bc it's a pointer to a pointer that contains a HashNode
    // table is an array but double pointer keeps it dynamic
    // table is an array of hash pointers
    int size;

public:
    HashTable() {
        size = 10;
        table = new HashNode *[10]; // allocating HashNode pointers in the heap -- remember to delete with destructor
        for (int i = 0; i < size; i++) table[i] = nullptr; // initializing all ptrs to 0 to be safe
    }

    explicit HashTable(int s) {
        size = s;
        table = new HashNode *[s];
        for (int i = 0; i < size; i++) table[i] = nullptr; // initializing all ptrs to 0 to be safe
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            HashNode *tmp = table[i];
            while (tmp != nullptr) {
                HashNode *curr = tmp;
                tmp = tmp->next;
                delete curr;
            }
        }
        delete[] table;
    }

    /******************************************************************************
     * E1.. Insert a key and value pair inside the hash-table using chaining.
     *****************************************************************************/

    // compute hash code of key
    // go to corresponding index
    // make a new node
    // possible index is free or not
    // traverse list to see if key is there
    // find the right place
    // insert it - up to you -- at the top, sorted, etc...

    void insert(const string &key, const string &value) {
        // LAZY GENERAL IMPLEMENTATION BELOW

        int index = hashCode(key, size);

        HashNode *tmp = new HashNode(key, value); // allocating a new HashNode on heap and getting a pointer into tmp

        if (table[index] == nullptr) {
            table[index] = tmp;
        } else {
            // traverse table and find where key needs to be inserted
            HashNode *curr = table[index];
            HashNode *prev = nullptr;

            while (curr != nullptr) {            /*scan list from left to right*/
                if (curr->key == key) {
                    if (curr->value == value) cout << "Error: Entry already exists in the hashtable!\n";
                    else cout << "Error: Duplicate key!\n";
                    return;
                }
                prev = curr;
                curr = curr->next;
            }

            // insert node I'm trying to insert right now after the current
            prev->next = tmp; // will never reach this part while prev == nullptr

            return;
        }
    }

    /******************************************************************************
     *  E2. Search is a key is inside the hash-table, if so return a pointer to
     * the node. Otherwise, return null pointer (0).
     *****************************************************************************/

    // With the key, get the hash. If you find the value when you traverse, return pointer,
    // if not, return null

    HashNode *search(const string &key) {
        int index = hashCode(key, size);

        HashNode *tmp = table[index];

        while (tmp != nullptr) {
            /*tmp's key matches my key?*/
            if (tmp->key == key) /*I have found the key, give it to me*/ return tmp;
            /*otherwise move on to the next node*/
            tmp = tmp->next;
        }
        /*if it's empty or there is no key*/
        return nullptr;
    }

    /******************************************************************************
     *  E6. Remove a key from the hash-table implemented using chaining.
     *****************************************************************************/

    void remove(const string &key) {
        // go through to remove. Find if it's there
        int index = hashCode(key, size);

        HashNode *tmp = table[index];
        HashNode *prev = nullptr;

        while (tmp != nullptr) {
            if (tmp->key == key) break; /*if key matches, exit loop*/
            prev = tmp; /*otherwise keep going*/
            tmp = tmp->next;
        }

        if (tmp == nullptr) return; /*if empty, return without doing anything; key not found*/

        else if (prev == nullptr) { /*table is matching and previous is null. if so, previous goes away*/
            table[index] = tmp->next; // no one is pointing to tmp now
            delete tmp;
            tmp = nullptr; // when deleting a value pointing to an address, reallocate that pointer to null
        } else { /*when previous is not equal to null, don't touch anything at the head, delete temp. */
            prev->next = tmp->next;
            delete tmp;
            tmp = nullptr;
        }
        //
    }


    int hashCode(string k, int table_size) {
        int hash = 0;

        for (int i = 0; i < k.length(); i++)
            hash = hash + k[i];

        return hash % table_size;
    }

    /******************************************************************************
     *
     *  1. Given a key k (k is a string), generate the sum of the ASCII values
     *      for the characters in k.
     *  2. Multiply k by a constant A, where 0 < A < 1.
     *  3. Store the fractional part of kA.
     *  4. Multiply fractional part of kA by a constant, m, and take the floor of the result.”
     *
     *********************************************************************************/

    int hashCode2(string k, int table_size) {
        int hash = 0;
        double A = 13.0 / 32.0;
        double hA;
        int m = 1024;

        for (int i = 0; i < k.length(); i++)
            hash = hash + k[i];

        hA = hash * A;

        double fractpart, intpart;
        //get the fractional part of hash
        fractpart = modf(hA, &intpart);

        fractpart = fractpart * m;
        hash = floor(fractpart);
        return hash % table_size;
    }

    void printHashTable() {
        for (int i = 0; i < size; i++) {
            if (table[i] != 0) {
                cout << "[" << i << "] ";
                HashNode *curr = table[i];
                while (curr != 0) {
                    cout << "-> Key: " << curr->key << " (#" << hashCode(curr->key, size) << ") Value: " << curr->value;
                    curr = curr->next;
                }
                cout << endl;
            } else {
                cout << "[" << i << "] -> Empty" << endl;
            }
        }
    }
};

int main(int argc, char *argv[]) {

    if (argc != 2) return 0;

    HashTable HT(3);

    ifstream file(argv[1]);
    string line;

    while (getline(file, line)) {
        stringstream linestream(line);
        string key;
        string value;

        getline(linestream, key, ',');
        getline(linestream, value, '\n');

        HT.insert(key, value);
    }

    HT.printHashTable();

    /*SEARCH*/
//    string name1 = "Prathyusha Gayam";
//    /* call the function with her name. If you find it, print the value of her key*/
//    if (HT.search(name1) == nullptr) cout << name1 << ": Key not found" << endl;
//    else cout << "Key: " << name1 << " has value:" << HT.search(name1)->value;
//
//    name1 = "Ashutosh Trivedi";
//
//    if (HT.search(name1) == nullptr) cout << name1 << "key not found" << endl;
//    else cout << "Key: " << name1 << " has value:" << HT.search(name1)->value << endl;

    /*REMOVE*/
    HT.remove("Ashutosh Trivedi");
//    HT.remove("Prathyusha Gayam");
//    HT.remove("Andrew Altomare");
//    HT.remove("Maciej J Zagrodzki");




    HT.printHashTable();

    return 0;
}
