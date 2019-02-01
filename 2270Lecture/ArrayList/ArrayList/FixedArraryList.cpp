#include<iostream>
#include<string>
#define INVALID_INDEX -1

#define MAX_LIST_SIZE 100
/* Class Declaration */
class List {
private:
  std::string m_list[MAX_LIST_SIZE]; //List of items
  int m_size; // number of items in the list
  int m_capacity; // total capacity of the list

public:
  List();   // Default Constructor
  ~List();  // Default Destructor
  
  int getSize();  // returns number of items in the list
  int getCapacity(); // returns the capacity of the list
  bool isEmpty(); // return true if the list is empty; false otherwise
  bool isFull(); // return true if the list is full; false otherwise

  void insert(std::string data); // insert at item to the end of the list 
  void insert(std::string data, int index); // insert an item at a given index 
  void remove(int index); // remove the item at a given index
  int search(std::string data); // return the index of the first occurence of the given data, -1 otherwise.
  std::string retrieve(int index); //retrieve an item at a given index
  void print(); // print the list 
};

/* Class Definition */
List::List() {
  m_size = 0;
  m_capacity = 1000;
}

List::~List() {
}

void List::insert(std::string data) {
  if (m_size < m_capacity) {
    m_list[m_size] = data;
    m_size = m_size + 1;
  }
  else {
    throw "List capacity reached";
  }
}

void List::insert(std::string data, int index) {
  if ((index < 0) ||  (index > m_size))  throw "Index out of bounds";
  if (m_size < m_capacity) {
    // 
    // Write your own logic here
    // 
  }
  else {
    throw "List capacity reached";
  }
}

void List::remove(int index) {
  if ((index < 0) ||  (index > m_size))  throw "Index out of bounds";
  // Write your own logic here 
}

int List::search(std::string data) {
  for (int i = 0; i < m_size; i++) {
    if (m_list[i] == data) return i;
  }
  return INVALID_INDEX;
}


int List::getSize() {
  return m_size;
}

int List::getCapacity() {
  return m_capacity;
}

bool List::isEmpty() {
  return (m_size == 0);
}

bool List::isFull() {
  return (m_size == m_capacity);
}

void List::print() {
  std::cout << "[ ";
  for (int i = 0; i < m_size-1; i++) {
    std::cout << m_list[i] << ", ";
  }
  std::cout <<  m_list[m_size-1] <<"]" << std::endl;
}

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
      std::cout << " Strange! it should be empty" << std::endl;
        
    // Lets insert couple of values 
    addresses.insert("Boulder");
    addresses.insert("Erie");
    addresses.insert("Louisville");
    
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

    insertIntoList(&addresses); // Pass by pointer 
    addresses.print();

    insertIntoList(addresses); // Pass by Value
    addresses.print();
    
  }
  catch (const char* e) {
    std::cerr << "Exception: " << e << std::endl;
  }
  
  return 0;
}


