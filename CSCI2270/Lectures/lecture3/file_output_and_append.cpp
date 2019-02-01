//WRITING FROM FILE
#include <iostream>
#include <fstream>
using namespace std;
int main () {
  ofstream myfile;
  myfile.open("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close(); // close file
  return 0;
 }
//good if file doesn't need to keep changing
///////////////////////////////////////////////////////////////////////////////
// Can also write: TO APPEND A FILE
//
int main () {
  // use pipe | if using more than one mode
  ofstream myfile("example.txt", ios::binary | ios::app | ios::out);
  myfile << "Writing this to a file.\n";
  myfile.close();
   return 0;
}
//
// - The constructor instead of open()
// - Parameters passed while opening the file. Keeps on changing
