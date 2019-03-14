#include <iostream>
#include <fstream>
#include "HashTable.hpp"


////////////////////////////////////////////////////////////////////
/*HELPER FUNCTIONS*/
////////////////////////////////////////////////////////////////////
std::istream &safeGetline(std::istream &is, std::string &t) {
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    std::istream::sentry se(is, true);
    std::streambuf *sb = is.rdbuf();

    for (;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                return is;
            case '\r':
                if (sb->sgetc() == '\n')
                    sb->sbumpc();
                return is;
            case std::streambuf::traits_type::eof():
                // Also handle the case when the last line has no line ending
                if (t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char) c;
        }
    }
}


/* load stopwords into the stopwords hash table */
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable) {
    int element = 0;
    std::string tempword;
    std::ifstream input(ignoreWordFileName);

    if (!input.is_open()){
        std::cout << "Failed to open " << ignoreWordFileName << std::endl;
        return;
    }

    while (safeGetline(input,tempword) && element < 50) {
        stopWordsTable[element++] = tempword;
        // TODO How do I implement HT correctly?
    }

    input.close();
}

/* check table to see if a word is a stopword or not */
bool isStopWord(std::string word, HashTable &stopWordsTable){
    for (int i = 0; i < 50; i++) {
        std::string w = stopWordsTable[i];
        // TODO How do I implement HT correctly?
        if (w == word) {
            return true;
        }
    }
    return false;

}


////////////////////////////////////////////////////////////////////
/*CLASS FUNCTIONS*/
////////////////////////////////////////////////////////////////////
HashTable::HashTable(int hashTableSize) {
    this->hashTableSize = hashTableSize; //todo My goal is to connect it to the instance varialbe hashTableSize in .hpp
    hashTable = new wordItem *[hashTableSize];
    for (int i = 0; i < hashTableSize; i++) hashTable[i] = nullptr; // initializing all pointers to NULL to be safe
    int numItems = 0;
    int numCollisions = 0;
}

HashTable::~HashTable() {
    for (int i = 0; i < hashTableSize; i++) {
        wordItem *tmp = hashTable[i];
        while (tmp != nullptr) {
            wordItem *curr = tmp;
            tmp = tmp->next;
            delete curr;
        }
    }
    delete[] hashTable;
}

void HashTable::addWord(std::string word) {

}

bool HashTable::isInTable(std::string word) {
    return false;
}

void HashTable::incrementCount(std::string word) {

}

// probability of occurrence up to 4 decimal places.
void HashTable::printTopN(int n) {
//    for (int i = 0; i < n; i++) {
//    /* for each wordItem, w, in the top n most frequent words
//        totalNumberofWords - total number of non-stop words */
//    std::cout << (float)w->count/totalNumberofWords << " - " << w->word << std::endl;
//    }
}

int HashTable::getNumCollisions() {
    return 0;
}

int HashTable::getNumItems() {
    return 0;
}

int HashTable::getTotalNumWords() {
    return 0;
}

unsigned int HashTable::getHash(std::string word) {
    int hash = 0;
    for (char i : word) hash = hash + i;
    return static_cast<unsigned int>(hash % hashTableSize);
}

wordItem *HashTable::searchTable(std::string word) {
    int index = getHash(word);

    // search list a that specific index and return the node if found
    wordItem *tmp = hashTable[index];

    while(tmp!= nullptr) {
        // does tmp's word match my word?
        if (tmp->word == word) return tmp; // found it!
        tmp = tmp->next; // nope, keep searching
    }
    // if empty or no key, 
    return nullptr;
}

////////////////////////////////////////////////////////////////////
/*DRIVER FUNCTION*/
////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cout << "Usage: Assignment7 <number of common words> <text file> <stop words file> <size of HT>\n";
        return -1;
    }

    int topN = std::stoi(argv[1]);

    // open file with words to ignore file (index 3)
    char *ignorewords_filename = argv[3];
//    HashTable **ignoreWords[50];
//    getStopWords(ignorewords_filename, ignoreWords);
// TODO How do I do this with HTs?

    // open file with good words (index 2)
    char *words_filename = argv[2];
    std::ifstream wordsfile(words_filename);
}