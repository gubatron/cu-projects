/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/*    Implement menu options as described in the writeup        */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu() {
    cout << "*----------------------------------------*" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Producer (Produces items into the queue)" << endl;
    cout << "2. Consumer (Consumes items from the queue)" << endl;
    cout << "3. Return the queue size and exit" << endl;
    cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[]) {
    ProducerConsumer queue[SIZE];
    bool flag = true;

    while (flag) {
        menu();
        std::string response;
        std::cin >> response;
        int choice = stoi(response);

        switch (choice) {

            case 1: {
                int numItems = 0;
                std::string item;
                std::cout << "Enter the number of items to be produced: \n";
                std::cin >> numItems;
                for (int i = 1; i <= numItems; i++) {
                    std::cout << "Item " << i << ":" << std::endl;
                    std::cin >> item;
                    queue->enqueue(item);
                    std::cout << item << endl;
                }
                break;
            }
            case 2: {
                int numItems = 0;
                std::cout << "Enter the number of items to be consumed: \n";
                std::cin >> numItems;
                while (!queue->isEmpty()) {
                    queue->dequeue();
                    std::cout << queue->getQueueEnd() << std::endl;
                }
                if(queue->isEmpty()) {
                    std::cout<<"Consumed all the items from queue. Cannot consume more"<< std::endl;
                }
                break;
            }
            case 3: {
                cout << "Number of items in the queue: ";
                queue->queueSize();
                break;
            }
            default: break;
        }
        return 0;
    }
}

//int test1(int argc, char const *argv[]) {

//}
