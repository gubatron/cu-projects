#include <utility>

#include<iostream>
#include<fstream>
#include<sstream>
#include <math.h>       /* modf */

using namespace std;

struct HashNode {
    string key;
    string value;

    HashNode() {
        key = "";
        value = "";
    }

    HashNode(string k, string v) {
        key = std::move(k);
        value = std::move(v);
    }

    ~HashNode() {}
};

class HashTable {
    HashNode **table;
    int size;

public:
    HashTable() {
        size = 10;
        table = new HashNode *[10];
        for (int i = 0; i < size; i++) table[i] = nullptr;
    }

    HashTable(int s) {
        size = s;
        table = new HashNode *[s];
        for (int i = 0; i < size; i++) table[i] = nullptr;
    }

    ~HashTable() { delete[] table; }

    /******************************************************************************
     * E4. Insert a key and value pair inside the hash-table using linear-probing.
     * If there is no space left in the table, simply print a warning and return;
     * You can also implement "dynamic doubling" stratgy, if you wish.
     *****************************************************************************/

    void insert(const string &key, string value) {
        int index = hashCode(key, size);
        HashNode *tmp = new HashNode(key, std::move(value));

        // index can be free -- put in in the table
        if (table[index] == nullptr) table[index] = tmp;
            // OR HASH COLLISION - do LINEAR PROBING
        else {
            for (int i = (index + 1) % size; i != index; i = (i + 1) % size) {      /*checks form index+1 to index
                                                                            * %size takes care of looping*/
                if (table[i] == nullptr) {
                    // any index is free
                    table[i] = tmp;
                    return;
                } else if (table[i]->key == key) { // key matches
                    cout << "key" << key << " already exists with value " << table[i]->value << endl;
                }
            }
            cout << "Hash table overflow " << endl;
        }
    }

/******************************************************************************
 *  E5. Search is a key is inside the hash-table, if so return a pointer to
 * the node. Otherwise, return null pointer (0).
 *****************************************************************************/

    HashNode *search(string key) {
        return 0;
    }

/******************************************************************************
 *  E6. Remove a key from the hash-table implemented using linear probing.
 * Discuss with the students in your group What can go wrong!
 *****************************************************************************/
    void remove(string key) {
        return;
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
        double A = 13 / 32;
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
                cout << "[" << i << "] -> Key: " << table[i]->key << " (#" << hashCode(table[i]->key, size)
                     << ") Value: " << table[i]->value << endl;
            } else {
                cout << "[" << i << "] -> Empty" << endl;
            }
        }
    }
};

/*
         CHALLENGE ALERT!!!
         Submission Date Time -  Tuesday, March 12, 11:59PM
         Email Subject - CSCI2270_CHALLENGE_1
         The subject has to be EXACTLY this...
         Send an email TO YOUR TA.

         Implementation of the challenge will be like midterm FROM SCRATCH.

         SUBMIT program as .cpp, explanation as .txt and output as screenshot.
         Also Explain the Time Complexity of your algorithm in the explanation.txt (That means write the O(?) notation).

         Challenge Problem:

         Write a program to merge two BSTs into one.
         Try and make your program efficient.
*/

int main(int argc, char *argv[]) {

    if (argc != 2) return 0;

    HashTable HT(10);

    ifstream file(argv[1]);
    string
            line;

    while (getline(file, line)) {
        stringstream linestream(line);
        string
                key;
        string
                value;

        getline(linestream, key, ',');
        getline(linestream, value, '\n');

        HT.insert(key, value);
    }


    //  HT.remove("Ashutosh Trivedi");

    string
            name1 = "Prathyusha Gayam";

    if (HT.search(name1) == 0) cout << name1 << ": Key not found" << endl;
    else cout << "Key: " << name1 << " has value:" << HT.search(name1)->value;

    name1 = "Ashutosh Trivedi";

    if (HT.search(name1) == 0) cout << name1 << "key not found" << endl;
    else cout << "Key: " << name1 << " has value:" << HT.search(name1)->value << endl;


    HT.printHashTable();

    return 0;
}
