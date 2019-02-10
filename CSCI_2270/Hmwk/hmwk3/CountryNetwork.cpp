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
void CountryNetwork::insertCountry(Country *previous, std::string countryName) {
    auto newCountry = new Country();
    newCountry->name = countryName;
    newCountry->message = "";
    newCountry->numberMessages = 0;
    newCountry->next = nullptr;
    if (previous == nullptr) {
        std::cout << "adding: " << countryName << " (HEAD)" << std::endl;

        // if we already had something in the list, let's not lose the list
        if (head != nullptr) { // list is not empty
            // make a copy of the head pointer
            Country *headCopy = head;
            // our new country points to the old head (head's copy)
            newCountry->next = headCopy;
        }

        // now make the head point to the new country
        head = newCountry;
    } else {
        std::cout << "adding: " << countryName << " (prev: " << previous->name << ")" << std::endl;
        if (head == nullptr) { // list is empty
            head = previous;
            head->next = newCountry;
        } else {
            // previous might not be the last one, let's
            // keep the tail, just in case we have to insert in between
            // previous and the tail.

            auto tail = previous->next; // doesn't matter if there's no tail
            previous->next = newCountry;

            // make sure our country points to whatever the tail was,
            // even if it was null
            newCountry->next = tail;
        }
    }
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
    Country *curr = head;
    Country *prev = nullptr;

    while (curr != nullptr) {
        if (curr->name == countryName) {

            if (prev == nullptr) {
                // we're at the head, delete it and keep the rest of the list.
                auto oldHead = curr; // keep it to delete it
                head = curr->next; // move the head
                delete oldHead; // delete old node pointed by head previously
                return;
            }

            // Now, let's unlink the current one, and point
            // the previous to the next of current
            prev->next = curr->next;
            delete curr;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Country does not exist." << endl;
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: populates the network with the predetermined countries
 * First, delete whatever is in the linked list using the member function
deleteEntireNetwork. Then add the following six countries, in order, to the network with
insertCountry: "United States", "Canada", "Brazil", "India", "China", "Austraila"
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup() {
    // delete whatever is in the linked list using deleteEntireNetwork
    deleteEntireNetwork();
    // add the countries to network using insertCountry
    insertCountry(nullptr, "United States");
    Country *USA = searchNetwork("United States");
    insertCountry(USA, "Canada");
    Country *canada = searchNetwork("Canada");
    insertCountry(canada, "Brazil");
    Country *brazil = searchNetwork("Brazil");
    insertCountry(brazil, "India");
    Country *india = searchNetwork("India");
    insertCountry(india, "China");
    Country *china = searchNetwork("China");
    insertCountry(china, "Australia");
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
    while (head != nullptr){
        auto temp = head;
        head = head->next;
        cout << "deleting: " << temp->name << endl;
        delete temp;
    }
    head = nullptr;
    // after entire linked list is delete, print:
    cout << "Deleted network" << endl;
}
/****************************************************************/
/****************************************************************/
/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork() {
    if (head == nullptr) return;

    Country *prev = nullptr;
    Country *curr = head;
    Country *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev; // point head at the last node
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
    Country *prev = head;
    Country *curr = nullptr;
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
    Country *temp = head;

    cout << "== CURRENT PATH ==" << endl;

    if (isEmpty()) {
        cout << "nothing in path" << endl;
    }
    while (temp != nullptr) {
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
}
