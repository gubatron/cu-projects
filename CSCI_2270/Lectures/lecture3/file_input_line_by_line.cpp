//READING FROM FILE
#include <iostream>
#include <fstream>
#include <string>
void main (int argc, char *argv[]) {
  std::ifstream fin("addresses.txt");
  if (fin.is_open()) {
    std::string line;
    // getline goes line by line
    while (getline(fin, line)) {
      std::size_t found = line.find("TX"); // in this file, find ppl from TX
      if (found!=std::string::npos) {
        std::cout << line << std::endl;
      }
    }
  }
  else std::cerr << "File addresses.txt not found!";
  fin.close(); // Don’t forget to close!
  return 0;
}

// STRING STREAMS : input and output to strings
while (getline(fin, line)) {
  std::stringstream sin(line);
  std::string id, name, phone, email, street, zip, city, state, lat, lon;
  getline(sin, id, ’,’);
  getline(sin, name, ’,’);
  getline(sin, phone, ’,’);
  getline(sin, email, ’,’);
  getline(sin, street, ’,’);
  getline(sin, city, ’,’);
  getline(sin, state, ’,’);
  getline(sin, zip, ’,’);
  getline(sin, lat, ’,’);
  getline(sin, lon, ’ ’);
  std:: cout << name << "lives in " << state << std::endl;
}
