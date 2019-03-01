#include<iostream>
#include<string>
#include "List.hpp"


void insertIntoList(List* addresses_p) {
  (*addresses_p).insert("Denver");
  addresses_p->insert("Lafayette");
}

void insertIntoList(List addresses_p) {
  addresses_p.insert("Lafayette");
}

int main(int argc, char* argv[])
{
  try {
    List addresses;

    if (addresses.isEmpty())
      std::cout << "List is initially empty as expected" << std::endl;
    else
      std::cout << "Strange! it should be empty" << std::endl;
    
    // Lets insert couple of values 
    addresses.insert("Boulder");
    addresses.insert("Erie");
    addresses.insert("Louisville");
    addresses.insert("Denver");
    
    addresses.print();
    
    std::string text = "Erie";
    int i = addresses.search(text);
    
    if (i >= 0) std::cout << text << " is in the list at index: " <<  i << " !" << std::endl;
    else std::cout << text << " is not in the list!"  << std::endl;
    
    addresses.remove(i);
    
    i  = addresses.search(text);
    
    if (i >= 0) std::cout << text << " is in the list at index: " <<  i << "." << std::endl;
    else std::cout << text << " is not in the list!"  << std::endl;

    //addresses.remove(i);
    
    for (int j=0; j<=100; j++) {
      addresses.insert("Boulder");
    }
    
    // addresses.print();
    std::cout << " Denver is in the list at index: " <<  addresses.search("Denver")  << "." << std::endl;
  }
  catch (const char* e) {
    std::cerr << "Exception: " << e << std::endl;
  }
  
  return 0;
}


