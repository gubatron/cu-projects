#include <iostream>
#include <fstream>

//Uncomment the lines and implement the TODOs in the resizing logic
void resize(int **arrayPtr, int *capacity)
{
    //increase the capacity by two times
     auto newCapacity = *capacity * 2;
     std::cout << "Resizing from " << *capacity << " to " << newCapacity << std::endl;

    // dynamically allocate an array of size newCapacity
     int *newArray = new int[newCapacity];

    // copy all data from oldArray to newArray
    for (int i = 0; i < *capacity; i++) {
        int *ptr = *arrayPtr; // dereference arrayPtr to transfer contents
        newArray[i] = ptr[i];
    }
    // free the memory associated with oldArray
    delete[] *arrayPtr; // delete old array

    *arrayPtr = newArray;
    *capacity = newCapacity;
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        return -1;
    }
    std::string filename = argv[1];
    std::ifstream data;
    data.open(filename.c_str());

    int capacity = 10;
    int *arrayPtr;

    // Dynamically allocate space here for the array
    arrayPtr = new int[capacity];
    int numOfElement = 0;
    std::string temp;

    if(data.is_open())
    {
        while(getline(data, temp))
        {
            int toBeInsert = stoi(temp);
            if(numOfElement == capacity)
            {
                // Complete this function
                resize(&arrayPtr, &capacity);
            }
            arrayPtr[numOfElement] = toBeInsert;
            numOfElement++;
        }
        data.close();
    }

    for(int i = 0; i < numOfElement; i++)
    {
        std::cout << "Num: " << arrayPtr[i] << std::endl;
    }
    return 0;
}
