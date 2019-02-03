#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

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

void doubleArray(wordItem *&arrayPtr, int &capacity) {
    // dynamically allocate an array of size newCapacity
    auto *newArray = new wordItem[capacity * 2];

    // copy all data from oldArray to newArray
    for (int i = 0; i < capacity; i++) {
        newArray[i] = arrayPtr[i];
    }
    // free the memory associated with oldArray
    delete[] arrayPtr; // delete old array

    arrayPtr = newArray; // re-reference the de-reference
    capacity *= 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

void getStopWords(const char *ignoreWordFileName, std::string ignoreWords[]) {
    int element = 0;
    std::string tempword;
    std::ifstream input(ignoreWordFileName);

    if (!input.is_open()) {
        std::cout << "Failed to open " << ignoreWordFileName << std::endl;
        // idea: mark the function as failed with "failed" on first ignoreWords element.
        return;
    }

    while (safeGetline(input, tempword) && element < 50) {
        ignoreWords[element++] = tempword;
    }

    input.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool isStopWord(const std::string &word, std::string ignoreWords[]) {
    for (int i = 0; i < 50; i++) {
        std::string w = ignoreWords[i];
        if (w == word) {
            return true;
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += uniqueWords[i].count;
    }
    return total;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void swap(wordItem *a, wordItem *b) {
    wordItem temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(wordItem arr[], int length) {
    int i, j;
    for (i = 0; i < length - 1; i++)
        for (j = 0; j < length - i - 1; j++)
            if (arr[j].count < arr[j + 1].count)
                swap(&arr[j], &arr[j + 1]);
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

void arraySort(wordItem arr[], int length) {
    //bubbleSort(arr, length);
    quickSort(arr, length, true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float probOfOcc(wordItem item, int totalWords) {
    return (float) item.count / totalWords;
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords) {
    // assume array is already sorted
    for (int i = 0; i < topN; i++) {
        std::cout << std::fixed << std::setprecision(4) << probOfOcc(uniqueWords[i], totalNumWords) << " - "
                  << uniqueWords[i].word.c_str() << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findWord(const std::string &word, wordItem *items, int size) {
    for (int i = 0; i < size; i++) {
        if (word == items[i].word) return i;
    }
    return -1; // found nothing
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>"
                  << std::endl;
        return -1;
    }

    int topN = std::stoi(argv[1]);

    // open file with words to ignorefile (index 3 argument)
    char *ignorewords_filename = argv[3];
    std::string ignoreWords[50];
    getStopWords(ignorewords_filename, ignoreWords);

    // open file with good words (index 2 argument)
    char *words_filename = argv[2];
    std::ifstream wordsfile(words_filename);

    int capacity = 100;

    // Dynamically allocate space here for the array
    auto *items = new wordItem[capacity];

    if (!wordsfile.is_open()) {
        std::cout << "Failed to open " << words_filename << std::endl;
    }

    int size = 0; // used words inside the array
    int doublings = 0;
    std::string tempword;
    while (getline(wordsfile, tempword, ' ')) {
        if (isStopWord(tempword, ignoreWords)) {
            continue;
        }
        int wordIndex = findWord(tempword, items, size);
        // if not in the array, add wordItem into array and increment size
        if (wordIndex == -1) {
            wordItem item;
            item.count = 1;
            item.word = tempword;
            items[size++] = item;
            if (size == capacity) {
                doubleArray(items, capacity);
                doublings++;
            }
        }
            // if wordItem already appears in array, increment count
        else {
            items[wordIndex].count++;
        }
    }
    wordsfile.close();
    arraySort(items, size);
    std::cout << "Array doubled: " << doublings << std::endl;
    std::cout << "#" << std::endl;
    std::cout << "Unique non-common words: " << size << std::endl;
    std::cout << "#" << std::endl;
    std::cout << "Total non-common words: " << getTotalNumberNonStopWords(items, size) << std::endl;
    std::cout << "#" << std::endl;
    std::cout << "Probabilities of top " << topN << " most frequent words " << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    printTopN(items, topN, getTotalNumberNonStopWords(items, size));
    delete[]items;
}

