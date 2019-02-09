#include <utility>

/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork() {
    head = nullptr;
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty() {
    return head == nullptr;
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: Add a new Country to the network // add new node to list
 *   between the Country *previous and the Country that follows it in the
 *   network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, std::string countryName) {
    Country *newCountry = new Country();
    newCountry->name = countryName;
    newCountry->message = "";
    newCountry->numberMessages = 0;
    previous->next = newCountry;
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
    // TRAVERSE list to find the node with name countryName then delete it
    Country *head;
    Country *curr = head;

    // if list is empty
    isEmpty();

    if (curr == nullptr) {
        cout << "Country does not exist" << endl;
        return;
    }
    while (curr != nullptr) {
        if (curr->name == countryName) {
            curr = curr->next;
            // if at the head
            if (head->name == countryName) {
                Country *temp = head;
                head = head->next;
                delete temp;
            }
                // either tail or middle
            else {
                Country *prev = head;
                curr = prev->next;
                bool isFound = false;
                while (curr != nullptr && !isFound) {
                    if (curr->name == countryName) {
                        if (curr->next == nullptr) {
                            // tail node
                            prev->next = nullptr;
                            // tail = prev;
                        } else {
                            prev->next = curr->next;
                        }
                        delete curr;
                        isFound = true;
                    } else {
                        prev = curr;
                        curr = curr->next;
                        delete prev; // todo where do I delete? time limit exceeded ERROR
                    }
                }
            }
        }
    }
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup() {
    // delete whatever is in the linked list using deleteEntireNetwork
    string name; // why not Country name??
    deleteCountry(name);
    // add the countries to network using insertCountry
//    insertCountry("United States"); // what do I put as previous???
//    insertCountry("Canada");
//    insertCountry("Brazil");
//    insertCountry("India");
//    insertCountry("China");
//    insertCountry("Australia")

}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country *CountryNetwork::searchNetwork(string countryName) {
    Country *curr = head;
    while (curr != nullptr) {
        if (curr->name == countryName) return curr;
        curr = curr->next;
        return curr;
    }
    return nullptr;
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork() {
    // if list is empty, do nothing and return
    // else, delete every node in linked list; set head to NULL
    // print name of each node as you delete it
    // cout << "deleting: " << node->name << endl;
    // after entire linked list is delete, print:
    // cout << "Deleted network" << endl;
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork() {

}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message) {
    // traverse list from head to node with name receiver
    // for each node in this path (including head) set node's message to msg
    // and increment node's numberMessages field.
    // at each node report the message received and the number of messages received
    // cout << node->name << " [# messages received: " <<
    // node->numberMessages << "] received: " << node->message << endl;

    // if empty, print "Empty list" and exit function
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    // if network is empty, print "nothing in path"
    cout << "== CURRENT PATH ==" << endl;
    cout << "===" << endl;
}
