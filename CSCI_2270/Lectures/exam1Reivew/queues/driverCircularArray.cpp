#include<iostream>
#include "circularArrayQueue.hpp"


int main() {
  CircularArrayQueue Q;
  bool flag = true;
  
  while (flag) {
    std::cout << "--------------------------------------------------\n";
    std::cout << " 1. ENQUEUE    2. DEQUEUE   3. EXIT \n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "RES:> ";
    
    std::string response;
    std::cin >> response;
    int choice = stoi(response);
    
    switch (choice) {

    case 1:
      {
	std::string elem;
	std::cout << "Enter the number you wish to enqueue: \n";
	std::cin >> elem;
	Q.enqueue(stoi(elem));
	Q.prettyPrintCircular();	
	break;
      }
      
    case 2:
      {
	int ret = Q.dequeue();
	std::cout << "The number dequeued is: " << ret << std::endl; 
	Q.prettyPrintCircular();
	break;
      }
      
    case 3:
      {
	std::cout << "Goodbye! \n";
	
	flag = false;
	break;
      }
    }
  }

  return 0;
}
