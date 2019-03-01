#include<iostream>

//self-referential structure

struct Node {
  int value;
  struct Node* next; //Self-referential structures
};

int main() {

  // Lets define a node
  Node n1;
  n1.value = 5;
  n1.next = 0;

  std::cout << "n1 data: " << n1.value << std::endl;

  Node* n2 = 0;
  n2 = &n1; // n2 now stores the address of n1

  (*n2).value = 11;
  std::cout << "n1 data: " << n1.value << std::endl;


  Node* n3 = new Node;
  (*n3).value = 55;
  (*n3).next = &n1;

  std::cout << "n3 data: " << (*n3).value << std::endl;


  n3->value = 66;
  n3->next = &n1;

  std::cout << "n3 data: " << n3->value << std::endl;
  std::cout << "n3 next pointer's data: " << n3->next->value << std::endl;
  
  
  return 0;
}
