#include <iostream>
#include <fstream>
#include <iomanip>
#include "HashTable.hpp"
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
        element++;
    }
    input.close();
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
    getStopWords(argv[3], stopwords_ht);

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