//READING FROM FILE
#include <iostream>
#include <fstream>
void main (int argc, char *argv[]) {
  std::ifstream fin("addresses.txt");
  if (fin.is_open()) {
  std::cout << "File is open as fin stream\n";
  char c;
  fin >> c; // reads a single character
  std::cout << "first char is " << c << " \n";
  }
  else std::cerr << "File addresses.txt not found!";
  fin.close(); // Don’t forget to close!
  return 0;
}
