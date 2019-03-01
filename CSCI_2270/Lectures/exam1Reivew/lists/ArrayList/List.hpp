#define MAX_LIST_SIZE 100
#define INVALID_INDEX -1

/* Class Declaration */
class List {
private:
  std::string m_list[MAX_LIST_SIZE];
  int m_size;
  int m_capacity;
  
public:
  List();   // Default Constructor 
  
  ~List();  // Default Destructor
  
  int getSize();  // returns number of items in the list
  int getCapacity(); // returns the capacity of the list
  bool isEmpty(); // return true if the list is empty; false otherwise
  bool isFull(); // return true if the list is full 

  void insert(std::string data); // insert at item to the end of the list 
  void insert(std::string data, int index); // insert an item at a given index 
  void remove(int index); // remove the item at a given index
  int search(std::string data); // return the index of the first occurence of the given data, -1 otherwise.
  std::string retrieve(int index); //retrieve an item at a given index
  
  void print(); // print the list 
};

