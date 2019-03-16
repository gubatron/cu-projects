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

    if (!input.is_open()) {
        std::cout << "Failed to open " << ignoreWordFileName << std::endl;
        return;
    }
    while (safeGetline(input, tempword) && element < 50) {
        stopWordsTable.addWord(tempword);
        element++; // TODO: double check it's adding 50 and not 49.
    }
    input.close();
}

/* check table to see if a word is a stopword or not */
bool isStopWord(std::string word, HashTable &stopWordsTable) {
    return stopWordsTable.isInTable(word);
}

////////////////////////////////////////////////////////////////////
/*CLASS FUNCTIONS*/
////////////////////////////////////////////////////////////////////
HashTable::HashTable(int size) {
    hashTableSize = size;
    hashTable = new wordItem *[hashTableSize];
    for (int i = 0; i < hashTableSize; i++) hashTable[i] = nullptr; // initializing all pointers to NULL to be safe
    numItems = 0;
    numCollisions = 0;
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
    int index = getHash(word);

    // no collision, new word
    if (hashTable[index] == nullptr) {
        auto w = new wordItem;
        w->next = nullptr;
        w->word = word;
        w->count = 1;
        hashTable[index] = w;
        numItems++;
        return;
    }

    // could be existing word or new word with hash collision.
    wordItem* head = hashTable[index];

    while (head->next != nullptr) {
        if  (head->word == word) {
            head->count++;
            return;
        }
        head = head->next;
    }

    if (head->word == word) {
        head->count++;
        return;
    }

    // if we get here, it's a new word with this hash, and it's a collision

    auto w = new wordItem;
    w->next = nullptr;
    w->word = word;
    w->count = 1;
    head->next = w;

    numItems++;
    numCollisions++;

}

bool HashTable::isInTable(std::string word) {
    int index = getHash(word);
    if (hashTable[index] == nullptr) {
        return false;
    }
    // could be existing word or new word with hash collision.
    wordItem* head = hashTable[index];

    while (head->next != nullptr) {
        if  (head->word == word) {
            return true;
        }
        head = head->next;
    }

    // does the last word match? if not, it's not in the table.
    return head->word == word;
}

void HashTable::incrementCount(std::string word) {
    int index = getHash(word);
    if (hashTable[index] == nullptr) {
        return;
    }
    // could be existing word or new word with hash collision.
    wordItem* head = hashTable[index];

    while (head->next != nullptr) {
        if  (head->word == word) {
            head->count++;
            return;
        }
        head = head->next;
    }

    // does the last word match? if not, it's not in the table.
    if (head->word == word) {
        head->count++;
    }
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
    return numCollisions;
}

int HashTable::getNumItems() {
    return numItems;
}

int HashTable::getTotalNumWords() {
    int total = 0;
    for (int i=0; i < hashTableSize; i++) {
        auto head = hashTable[i];
        while (head != nullptr) {
            total += head->count;
            head = head->next;
        }
    }
    return total;
}

unsigned int HashTable::getHash(std::string word) {
    unsigned int hash = 5381;
    int length = word.size();
    for (int i=0; i < length; i++) {
        hash = ((hash << 5) + hash) + (int) word[i];
    }
    return hash % hashTableSize;
}

wordItem *HashTable::searchTable(std::string word) {
    int index = getHash(word);

    // search list a that specific index and return the node if found
    wordItem *tmp = hashTable[index];

    while (tmp != nullptr) {
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

void setupTests(HashTable &ht) {
    ht.addWord("angel");
    ht.addWord("legna");
    ht.addWord("nicole");
    ht.addWord("nicole");
    ht.addWord("paulina");
    ht.addWord("angel");
    ht.addWord("sarah");
    ht.addWord("asrha");
    ht.addWord("angel");
    ht.addWord("desmond");
    ht.addWord("sarah");
}

void isInTableTests(HashTable &ht) {
    std::cout << ht.isInTable("desmond") << std::endl;
    std::cout << ht.isInTable("angel") << std::endl;
    std::cout << ht.isInTable("lange") << std::endl;
    std::cout << ht.isInTable("neny") << std::endl;
}

void incrementTest(HashTable &ht) {
    ht.incrementCount("paulina");
}

int main(int argc, char *argv[]) {
//    if (argc != 5) {
//        std::cout << "Usage: Assignment7 <number of common words> <text file> <stop words file> <size of HT>\n";
//        return -1;
//    }

    HashTable ht(3);
    setupTests(ht);
    isInTableTests(ht);
    std::cout << "total words: " << ht.getTotalNumWords() << std::endl;
    incrementTest(ht);
    std::cout << "total words: " << ht.getTotalNumWords() << std::endl;

    if (true) {
        return 0;
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