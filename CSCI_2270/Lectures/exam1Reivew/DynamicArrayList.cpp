#include<iostream>
#include<string>

#define INVALID_INDEX -1

/* Class Declaration */
class List {
private:
  std::string* m_list;
  int m_size;
  int m_capacity;
  int m_resize;
public:
  List();   // Default Constructor 
  ~List();  // Default Destructor
  int getSize();  // returns number of items in the list
  bool isEmpty(); // return true if the list is empty; false otherwise
  void insert(std::string data); // insert at item to the end of the list 
  void insert(std::string data, int index); // insert an item at a given index 
  void remove(int index); // remove the item at a given index
  int search(std::string data); // return the index of the first occurence of the given data, -1 otherwise.
  std::string retrieve(int index); //retrieve an item at a given index
  void print(); // print the list
private:
  void resize(); // Dynamically resize by doubling
};

List::List() {
  m_size = 0;
  m_list = 0;
  m_capacity = 0;
  m_resize = 0;
}

List::~List() {
  if (m_size > 1)  delete[] m_list;
  if (m_size == 1)  delete m_list;
}

void List::resize() {
  m_resize = m_resize + 1;
  std::cout << "Resizing " << m_resize << " times and no of elements: " << m_size << std::endl;
  

  if (m_capacity == 0) {
    m_list = new std::string [1];
    m_capacity = 1;     
  }
  else {
    // Write your own logic here ..
    // Write your own logic here ..
  }
}

void List::insert(std::string data) {
  if (m_size == m_capacity) resize();

  m_list[m_size] = data;
  m_size = m_size + 1;
  
}

void List::insert(std::string data, int index) {

  if ((index < 0) ||  (index > m_size))  throw "Index out of bounds";

  if (m_size == m_capacity) resize();
  
  for (int i = m_size; i > index; i--) {
    m_list[i] = m_list[i-1];
  }
  m_list[index] = data;
  m_size = m_size + 1;
}

void List::remove(int index) {
  if ((index < 0) ||  (index > m_size))  throw "Index out of bounds";
  for (int i = index; i < m_size - 1; i++) {
    m_list[i] = m_list[i+1];
  }
  m_list[m_size-1] = "";
  m_size = m_size - 1;
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

bool List::isEmpty() {
  return (m_size == 0);
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


