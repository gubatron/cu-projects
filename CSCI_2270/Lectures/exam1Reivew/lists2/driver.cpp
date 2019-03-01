#include<iostream>
#include "listclass.hpp"

int main() {
  LinkedList llist;
  bool flag=true; 
  while(flag) {
    std::cout << "--------------------------------------------------\n";
    std::cout << "-----ADD:    1\n";
    std::cout << "-----DELETE: 2\n";
    std::cout << "-----SEARCH: 3\n";
    std::cout << "-----PRINT:  4\n";
    std::cout << "-----EXIT:   5\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "RES:> ";
    
    std::string response;
    std::string valStr;
    std::string lvalStr;

    std::cin >> response;
    
    switch(stoi(response)) {
    case 1:
      std::cout << "What number you wish to add? \n";
      std::cin >> valStr;
      std::cout << "What is the left value? \n";
      std::cin >> lvalStr;
      
      llist.insertNode(stoi(lvalStr), stoi(valStr));
      break;
    case 2:
      std::cout << "What number you wish to delete? \n";
      std::cin >> valStr;
      llist.deleteNode(stoi(valStr));
      break;
    case 3:
      std::cout << "What number you wish to  search for? \n";
      std::cin >> valStr;

      Node* res;
      res = llist.search(stoi(valStr));
      if (res != 0) std::cout << " The value " << valStr << " is in the list\n";
      else std::cout << " The value " << valStr << " is not in the list\n";

      break;
      
    case 4:
      llist.traverse();
      break;
      
    case 5:
      std::cout << "Goodbye! \n";
      flag = false;
      break;
    }
  }

  return 0;
}
