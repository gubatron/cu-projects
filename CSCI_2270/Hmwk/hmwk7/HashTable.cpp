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
    }

    input.close();
}

/* check table to see if a word is a stopword or not */
bool isStopWord(std::string word, HashTable &stopWordsTable);


////////////////////////////////////////////////////////////////////
/*CLASS FUNCTIONS*/
////////////////////////////////////////////////////////////////////
HashTable::HashTable(int hashTableSize) {

}

HashTable::~HashTable() {

}

void HashTable::addWord(std::string word) {

}

bool HashTable::isInTable(std::string word) {
    return false;
}

void HashTable::incrementCount(std::string word) {

}

void HashTable::printTopN(int n) {

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
    
    return 0;
}

wordItem *HashTable::searchTable(std::string word) {
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
    std::string ignoreWords[50];
    getstopWords(ignorewords_filename, ignoreWords);

    // open file with good words (index 2)
    char *words_filename = argv[2];
    std::ifstream wordsfile(words_filename);
}