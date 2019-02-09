#include <iostream>
#include <fstream>
#include <cstdlib> // for quick sort

/* insertIntoSortedArray function reads up to 100 numbers from a file and
stores them in a sorted array, then allow the user to see if a specific number has been stored.
 * It inserts the new value into the correct spot so that it remains sorted
 * Input    int : myArray[] (at least 100)
 *          int : numEntries (actual number of entries in myArray)
 *          int : newValue (new value to be added to myArray)
 * Return:  int : newSize (new size of the array)
 * Print:   -
 */

int insertIntoSortedArray(int myArray[], int numEntries, int newValue) {
    myArray[numEntries] = newValue;
    // use quick sort
    std::qsort(myArray, numEntries + 1, sizeof(int), [](const void *a, const void *b) {
        int arg1 = *static_cast<const int *>(a);
        int arg2 = *static_cast<const int *>(b);

        if (arg1 < arg2) return -1;
        if (arg1 > arg2) return 1;
        return 0;

    });
    return numEntries + 1;
}

// prints the elements of an array, comma separated
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        // not at the end
        if (i != size - 1) {
            std::cout << ",";
        }
    }
}

void main(int argc, char* argv[]) {
    int arr[100];
    int numEntries = 0;
    int newValue = 0;

    std::ifstream in;
    in.open(argv[1]);
    if (in.fail()) {
        std::cout << "Failed to open the file." << std::endl;
    }
    std::string line;
    while (getline(in, line)) {
        // if the line is not empty
        if (line != "") {
            newValue = std::stoi(line);
            // insert each number as you go
            numEntries = insertIntoSortedArray(arr, numEntries, newValue);
            printArray(arr, numEntries);
            std::cout << std::endl;
        }
    }
    in.close();

}
