//
// Created by Nicole Leon on 1/19/2019.
//
#include <fstream>
#include <iostream>

int main() {
    //File Writing
    // Creates instance of ofstream and opens the file
    std::ofstream oFile ("filename.txt",  std::ios::binary | std::ios::app | std::ios::out);
    // Outputs to filename.txt through oFile
    oFile << "Insterted this text into filename.txt.\n";
    // Close the file stream
    oFile.close();
    return 0;
}
/*
 * Declaring an instance of file input:
    ifstream iFile ( "filename" );
 * Similarly for file output :
    ofstream oFile ( "filename" );
 * File operation modes:
    ios::app -- Append to the file
    ios::ate -- Set the current position to the end
    ios::trunc -- Delete everything in the file
 * File mode example:
    ofstream ofile ( "test.txt" , ios::app );
*/

