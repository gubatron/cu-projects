#include<iostream>
#include "linkedStack.hpp"


int main() {
  LinkedStack S;
  bool flag = true;
  
  while (flag) {
    std::cout << "--------------------------------------------------\n";
    std::cout << " 1. PUSH    2. POP    3. EXIT \n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "_ ";
    
    std::string response;
    std::cin >> response;
    int choice = stoi(response);
    
    switch (choice) {

    case 1:
      {
	std::string elem;
	std::cout << "Enter the number you wish to push: ";
	std::cin >> elem;
	std::cout << std::endl;
	
	S.push(stoi(elem));
	S.prettyPrint();

	break;
      }
      
    case 2:
      {
	int ret = S.pop();
	std::cout << "The number popped is: " << ret << std::endl; 
	S.prettyPrint();
	break;
      }
      
    case 3:
      {
	std::cout << "Goodbye! \n";
	
	flag = false;
	break;
      }
    default:
      break;
    }
  }

  return 0;
}
