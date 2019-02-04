/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{

}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{

}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{

}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{

}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{

}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{

}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{

}


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{

}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    
}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{

}