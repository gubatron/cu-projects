//
// Created by Nicole Leon on 1/19/2019.
//
#include <fstream>
#include <iostream>

int main() {
    // File Reading
    char str[10];
    // Opens the file for reading
    // Ensure that filename.txt is present in the directory
    // as that of the source file
    std::ifstream iFile ("filename.txt");
    // Reads one string from the file
    iFile >> str;
    // Outputs the file contents
    std::cout << str << "\n";
    // waits for a keypress
    std::cin .get();
    // iFile is closed
}
