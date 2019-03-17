#include <iostream>
#include <fstream>
#include <iomanip>
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
bool loadStopWords(std::string ignoreWordFileName, HashTable &hashTable) {
    int element = 0;
    std::string tempword;
    std::ifstream input(ignoreWordFileName);

    if (!input.is_open()) {
        std::cout << "Failed to open " << ignoreWordFileName << std::endl;
        return false;
    }
    while (safeGetline(input, tempword) && element < 50) {
        hashTable.addWord(tempword);
        element++;
    }
    input.close();
    return true;
}

/* load stopwords into the stopwords hash table */
bool loadTextfile(std::string textFile, HashTable &text_ht, HashTable &stopwords_ht) {

    std::string tempword;
    std::ifstream input(textFile);

    if (!input.is_open()) {
        std::cout << "Failed to open " << textFile << std::endl;
        return false;
    }
    while (getline(input, tempword, ' ')) {
        if (!isStopWord(tempword, stopwords_ht)) {
            text_ht.addWord(tempword);
        }
    }
    input.close();
    return true;
}

/* check table to see if a word is a stopword or not */
bool isStopWord(std::string word, HashTable &stopWordsTable) {
    return stopWordsTable.isInTable(word);
}

void quickSort(wordItem arr[], int length, bool reverse) {
    if (length <= 1) {
        return;
    }
    const int pivot_count = arr[length / 2].count;
    int smaller_length = 0;
    int bigger_length = 0;
    int equal_length = 0;

    for (int i = 0; i < length; i++) {
        if (!reverse) {
            if (arr[i].count < pivot_count) smaller_length++;
            if (arr[i].count > pivot_count) bigger_length++;
        } else {
            if (arr[i].count > pivot_count) smaller_length++;
            if (arr[i].count < pivot_count) bigger_length++;
        }
        if (arr[i].count == pivot_count) equal_length++;
    }

    auto smaller = new wordItem[smaller_length];
    auto bigger = new wordItem[bigger_length];
    auto equal = new wordItem[equal_length];

    int smaller_i = 0;
    int bigger_i = 0;
    int equal_i = 0;

    // comparisons, this part should be pluggable to make this generic
    for (int i = 0; i < length; i++) {
        if (!reverse) {
            if (arr[i].count < pivot_count) smaller[smaller_i++] = arr[i];
            if (arr[i].count > pivot_count) bigger[bigger_i++] = arr[i];
        } else {
            if (arr[i].count > pivot_count) smaller[smaller_i++] = arr[i];
            if (arr[i].count < pivot_count) bigger[bigger_i++] = arr[i];
        }
        if (arr[i].count == pivot_count) equal[equal_i++] = arr[i];
    }

    quickSort(smaller, smaller_length, reverse);
    quickSort(bigger, bigger_length, reverse);

    int j = 0;
    // now overwrite the original array with:
    // smaller + equal + bigger

    for (int i = 0; i < smaller_length; i++) arr[j++] = smaller[i];
    for (int i = 0; i < equal_length; i++) arr[j++] = equal[i];
    for (int i = 0; i < bigger_length; i++) arr[j++] = bigger[i];

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
    wordItem *head = hashTable[index];

    while (head->next != nullptr) {
        if (head->word == word) {
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
    wordItem *head = hashTable[index];

    while (head->next != nullptr) {
        if (head->word == word) {
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
    wordItem *head = hashTable[index];

    while (head->next != nullptr) {
        if (head->word == word) {
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
    // as we go through each word, sum all counts so we can
    // calculate probability of words when printing them
    int totalCountWords = 0;
    wordItem arr[numItems]; // array of wordItems to be sorted by wordItem.count

    // copy all the words in all the lists
    int j = 0;
    for (int i = 0; i < hashTableSize; i++) {
        auto headCopy = hashTable[i];
        while (headCopy != nullptr) {
            totalCountWords += headCopy->count;
            arr[j].word = headCopy->word;
            arr[j].count = headCopy->count;
            headCopy = headCopy->next;
            j++;
        }
    }
    quickSort(arr, numItems, true);
    for (int i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(4) << (float) arr[i].count / totalCountWords << " - "
                  << arr[i].word << std::endl;
    }
}

int HashTable::getNumCollisions() {
    return numCollisions;
}

int HashTable::getNumItems() {
    return numItems;
}

int HashTable::getTotalNumWords() {
    int total = 0;
    for (int i = 0; i < hashTableSize; i++) {
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
    for (int i = 0; i < length; i++) {
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
    ht.addWord("paulina");
    ht.addWord("sarah");
    ht.addWord("sarah");
    ht.incrementCount("nicole");
    ht.incrementCount("nicole");
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

void tests() {
    HashTable ht(3);
    setupTests(ht);
    isInTableTests(ht);
    std::cout << "total words: " << ht.getTotalNumWords() << std::endl;
    incrementTest(ht);
    std::cout << "total words: " << ht.getTotalNumWords() << std::endl;

    ht.printTopN(3);
}

bool readParameters(char *argv[], int &topN, std::string &textFile, std::string &stopWordsFile, int &htSize) {
    try {
        topN = std::stoi(argv[1]);
    } catch (std::invalid_argument &e) {
        std::cout << " number of most common words must be an integer. '" << argv[1] << "' is an invalid parameter"
                  << std::endl;
        return false;
    }

    textFile = std::string(argv[2]);

    stopWordsFile = std::string(argv[3]);

    try {
        htSize = std::stoi(argv[4]);
    } catch (std::invalid_argument &e) {
        std::cout << " hash table size must be an integer. '" << argv[4] << "' is an invalid parameter" << std::endl;
        return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cout << "Usage: Assignment7 <number of most common words> <text file> <stop words file> <size of HT>\n";
        return -1;
    }

    int topN;
    std::string textFile;
    std::string stopWordsFile;
    int htSize;

    if (!readParameters(argv, topN, textFile, stopWordsFile, htSize)) {
        return -1;
    }

    HashTable stopwords_ht(htSize);
    if (!loadStopWords(stopWordsFile, stopwords_ht)) {
        std::cout << "Error, could not load stop words from " << stopWordsFile << std::endl;
        return -1;
    }

    HashTable text_ht(htSize);
    if (!loadTextfile(textFile, text_ht, stopwords_ht)) {
        std::cout << "Error, could not load textfile from " << textFile << std::endl;
        return -1;

    }

    text_ht.printTopN(topN);

    std::cout << "#" << std::endl;

    std::cout << "Number of collisions: " << text_ht.getNumCollisions() << std::endl;

    std::cout << "#" << std::endl;

    std::cout << "Unique non-stop words: " << text_ht.getNumItems() << std::endl;

    std::cout << "#" << std::endl;

    std::cout << "Total non-stop words: " << text_ht.getTotalNumWords() << std::endl;

    return 0;
}