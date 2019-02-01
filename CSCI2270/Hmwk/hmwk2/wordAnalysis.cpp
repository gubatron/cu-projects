#include <iostream>
#include <fstream>
#include <string>

/*OBJECTIVE
 * Read file with unknown size and store its contents in a dynamic array (use a struct)
 * Store, search, and iterate through data in array of structs
 * User array doubling via dynamic memory to increase size of the array
 *
 * Program takes 3 command line arguments:
 *      number n; name of txt to read; name of txt of words to ignore
 * Will read text, ignore words in second file, and store all unique words in a dynamically
 * doubling array. Then should calculate and print:
    ● The number of array doubling needed to store all the unique words
    ● The number of unique “non-ignore” words in the file
    ● The total word count of the file (excluding the ignore words)
    ● The N most frequent words along with their probability of occurrence (up to 4 decimal places)
 * */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* wordItem struct stores all the words and their counts
 *      use struct because there is an unknown number of words in the file and struct doesn't have a
 *      specific size*/
struct wordItem {
    std::string word;
    int count;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* doubleArray function increases the size of an array
 *      - starts with size of 100 and is doubled whenever the array runs out of free space
 *      - allocate the array dynamically and copy values from old array to new array
 *      * DON'T use std::vector class - write it yourself*/

int * doubleArray(int **arrayPtr, int *capacity) {
    //increase the capacity by two times
    auto newCapacity = *capacity * 2;

    // dynamically allocate an array of size newCapacity
    int *newArray = new int[newCapacity];

    // copy all data from oldArray to newArray
    for (int i = 0; i < *capacity; i++) {
        int *ptr = *arrayPtr; // dereference arrayPtr to transfer contents
        newArray[i] = ptr[i];
    }
    // free the memory associated with oldArray
    delete[] *arrayPtr; // delete old array

    *arrayPtr = newArray; // re-reference the de-reference
    *capacity = newCapacity;

    return *arrayPtr; // the doubled array!
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void getStopWords(const char *ignoreWordFilename, std::string ignoreWords[]) {
    int capacity = 50;
    int *bad_arrayPtr;

    // Dynamically allocate space here for the array
    bad_arrayPtr = new int[capacity];

    int element = 0;
    std::string tempword;
    while (getline(ignoreWordFilename, tempword)) { // todo why is getline not working
        ignoreWords[element++] = tempword;
    }


    // if word is in ignoreWords[] return true
    // do I need pointers for that array??

    // store found words in an array
    // use doubleArray as needed if ignoreWords[] needs more room
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool isStopWord(std::string word, std::string ignoreWords[]) {

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void arraySort(wordItem uniqueWords[], int length) {

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printTopN(wordItem uniqueWords[], int topN, int totalNumWords) {

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>"
                  << std::endl;
        return -1;
    }

    // open file with good words (index 2 argument)
    std::string readwords = argv[2];
    std::ifstream words;
    words.open(readwords.c_str());


    int capacity = 10;
    int *arrayPtr;

    // Dynamically allocate space here for the array
    arrayPtr = new int[capacity]; // todo - do I need a delete for this new even if I have the delete already in the function the ptr is being used in


    if (words.is_open()) {
        int numOfElement = 0;
        std::string tempword;
        int *arrayPtrDoubled;
        while (getline(words, tempword)) {
            int insertWord = stoi(tempword); // convert to int to put words into array?
            if (numOfElement == capacity) {
                // double array if there is not enough room
                arrayPtrDoubled = doubleArray(&arrayPtr, &capacity); // todo should I store the doubled array in arrayPtrDoubled
                arrayPtr[numOfElement] = *arrayPtrDoubled;// I need to take what I find and put it in a value so I can work with it right?
            }
            arrayPtr[numOfElement] = insertWord;
            numOfElement++;
        }
        words.close();
    }

    // open file with words to ignore (index 3 argument) // todo - maybe open file later when I need it
    std::string ignorewords = argv[3];
    std::ifstream ignore;
    ignore.open(ignorewords.c_str()); // todo - remember to close at logical place

    std::string *ignoreWords; // todo - to use in getStopWords? Should I declare it inside the while?

    if (ignore.is_open()) {
        int numOfElement = 0;
        std::string tempword;
        while (getline(ignore, tempword)) {
            int ignore_badwords[] = stoi(tempword); // convert to int to put words into array
            getStopWords(&ignore, &ignoreWords);

            // call isStopWord() and compare words from words file
        }
        ignore.close();
    }


    // get stop-words from ignoreWords.txt and store words in an array
    // getStopWords();

    // read words from HarryPotter.txt and store all unique words NOT in ignore-words in an array of structs
    // dynamic word Item array of size 100 dynamic
    // add non-ignore words to array (double size if array is full)
    // keep track of number of times wordItem array is doubled and the number of unique non-ignore words
}