#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip> // fixed << setprecision()
#include <algorithm>

using namespace std;

/*
Calculate and print the following information:
[x] The number of times array doubling was required to store all the distinctwords
[ ] The number of distinct “non-ignore” words in the file
[ ] The total word count of the file (excluding the ignore words)
[ ] Starting from index N, print the 10 most frequent words along with their probability (upto
    4 decimal places) of occurrence from the array. The array should be sorted in
    decreasing order based on probability of occurrence of the words.

Command Line Example: 
./Homework1 25 mobydick.txt ignoreWords.txt
*/

struct wordRecord
{
    string word;
    int count;
};

// getIgnoreWords reads words (max 50) to ignore from ignoreWordFileName and stores them in ignorewords[]
void getIgnoreWords(const char *ignoreWordsFileName, string ignoreWords[])
{
    int index = 0;
    string tempword;
    ifstream file_to_read(ignoreWordsFileName);

    if (!file_to_read.is_open())
    {
        std::cout << "Failed to open " << ignoreWordsFileName << endl;
        return;
    }

    // everytime it gets to the tempword, increase the index in the array (less than 50 words)
    while (getline(file_to_read, tempword) && index < 50)
    {
        ignoreWords[index++] = tempword;
    }

    file_to_read.close(); // close file after reading
}

// return whether word is in ignoreWords array
bool isIgnoreWord(string word, string ignoreWords[])
{
    // go through the array, and check every word to see if it matches the given word
    for (int i = 0; i < 50; i++)
    {
        string tempWord = ignoreWords[i];
        if (tempWord == word)
        {
            return true; // is in array
        }
    }
    return false; // is not in array
}

// compute total number of unique words in the entire document, add them up, return sum
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{
    std::cout << "getTotalNumberNonIgnoreWords(length=" << length << ") =>";
    int totalWords = 0;
    for (int i = 0; i < length; i++)
    {
      totalWords += distinctWords[i].count;
    }
    std::cout << totalWords << std::endl;
    return totalWords;
}

// sort the array by word count such that the most frequent words are sorted to the beginning
void sortArray(wordRecord distinctWords[], int length)
{
  sort(distinctWords, distinctWords + length,
       [](wordRecord a, wordRecord b) -> bool {
	 if (a.count == b.count) {
	   return a.word > b.word;
	 }
	 return a.count < b.count;
       });
}

float probOfOcc(wordRecord distinctWords, int totalNumWords)
{
    return (float)distinctWords.count / totalNumWords;
}

/* print the next 10 words after the starting index N from SORTED array of distinctWords. 
These 10 words should be printed with their probability of occurrence up to 4 decimal places.*/
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    // array is already sorted
    for (int i = N; i < N + 10; i++)
    {
        // FORMAT:  0.0033 - little
        cout << fixed << setprecision(4) << probOfOcc(distinctWords[i], totalNumWords) << " - " << distinctWords[i].word.c_str() << endl;
    }
}

int distinctWord(const string &word, wordRecord *items, int size)
{
  if (size == 0) {
    return -1;
  }
  
  for (int i = 0; i < size; i++)
    {
        if (word == items[i].word)
            return i; // word is already in the array - not distinct
    }
    return -1; // found nothing - word is distinct
}

void doubleArray(wordRecord *&arrayPtr, int &capacity)
{
    int newCapacity = capacity * 2;
    wordRecord *newArray = new wordRecord[newCapacity];

    // copy all data from oldArray to newArray
    for (int i = 0; i < capacity; i++)
    {
        newArray[i] = arrayPtr[i];
    }
    // free the memory associated with oldArray
    //std::cout << "about to free old array (old capacity=" << capacity << ")" << std::endl;
    delete[] arrayPtr;
    arrayPtr = newArray; 
    capacity = newCapacity;
    //std::cout << "doubledArray finished OK (new capacity=" << capacity << ")" << std::endl;
}

// Command Line Example: ./Homework1 25 mobydick.txt ignoreWords.txt
int main(int argc, char *argv[])
{
    // if there aren't 4 arguments, print statement and exit program
    if (argc != 4)
    {
        std::cout << "Usage: Homework1Solution <number of words> < inputfilename.txt > <ignoreWordsfilename.txt> " << endl;
    }

    int topNwords = stoi(argv[1]);

    // open wordsFile (index 2)
    char *wordsFileName = argv[2];
    ifstream wordsFile(wordsFileName);

    // open ignoreWordsFileName (index 3) and store the words in ignoreWords array
    char *ignoreWordsFileName = argv[3];
    string ignoreWords[50];
    getIgnoreWords(ignoreWordsFileName, ignoreWords); // populates ignoreWords array

    int capacity = 100; // starting size of array

    // dynamically allocating space for the array
    auto *items = new wordRecord[capacity];

    if (!wordsFile.is_open())
    {
        std::cout << "Failed to open " << wordsFileName << endl;
        return -1;
    }

    int itemCount = 0;             // count distinct non-common words
    int arr_double_count = 0; // count how many times the array doubled
    string templine;          
    string tempword;

    // get the entire first line 
    while (!wordsFile.eof() && getline(wordsFile, templine)) 
    {
        if (templine.length() == 0) // if line is not empty, ignore
        {
            continue;
        }

        // make an input stream from the line (string)
        // http://www.cplusplus.com/reference/sstream/istringstream/istringstream/
        std::istringstream linestream(templine);

        while (!linestream.eof() && getline(linestream, tempword, ' ')) { // per word,
          if (tempword.length() == 0) // if word is not blank, ignore, loop again
          {
            continue;
          }

          if (isIgnoreWord(tempword, ignoreWords)) // if it's a word to ignore, ignore
          {
            continue;
          }

          // track distinct words
          int wordIndex = distinctWord(tempword, items, itemCount);
          //std::cout << "word index: " << wordIndex << std::endl;
          // if not in the array, add WordRecord into array and increment size of array
          if (wordIndex == -1) // word is distinct
          {
            //std::cout << "new" << std::endl;
            wordRecord item;
            item.count = 1;
            item.word = tempword;
            //std::cout << "items current size=" << size << std::endl;
            // add non-gnore words to the array
            items[itemCount++] = item; // add item to struct array and increase count of words (size)
            // double the array if full
            if (itemCount == capacity)
            {
                std::cout << "capacity met (" << itemCount << "), about to doubleArray!" << std::endl;
                doubleArray(items, capacity);
                arr_double_count++;
                std::cout << "doubledArray arr_double_count=" << arr_double_count << std::endl;
            }
            //std::cout << "counted as new word" << std::endl;
          }
          else // wordRecord already appears in array, increment count
          {
            items[wordIndex].count++;
	    //std::cout << "old word at " << wordIndex << " '" << items[wordIndex].word << "' new count is " << items[wordIndex].count << std::endl;	  
          }
	  if (wordIndex != -1) {
  	    //std::cout << tempword << ":" << items[wordIndex].count << std::endl;
  	  }
	}
    }
    std::cout << "finished reading file, let's close" << std::endl;
    wordsFile.close(); // close file
    std::cout << "closed the file fine." << std::endl;

    /* 
    Sample output
    Array doubled: 7
    Distinct non-common words: 7275
    Total non-common words: 42962
    Probability of next 10 words from rank 25 
    */
    //std::cout << "capacity: " << capacity << endl;
    std::cout << "Array doubled: " << arr_double_count << endl;
    std::cout << "Distinct non-common words: " << itemCount << endl; // itemCount is always itemCount of the active array
    std::cout << "Total non-common words: " << getTotalNumberNonIgnoreWords(items, itemCount) << endl;
    std::cout << "Probability of next 10 words from rank " << topNwords << endl;
    std::cout << "---------------------------------------" << endl;
    printTenFromN(items, topNwords, getTotalNumberNonIgnoreWords(items, itemCount));

    delete[] items;

    return 0;
}
