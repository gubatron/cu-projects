/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
  CountryNetwork network;
  network.insertCountry(NULL, "United States");
  Country *USA = network.searchNetwork("United States");
  network.insertCountry(USA, "Canada");
  Country *canada = network.searchNetwork("Canada");
  network.insertCountry(canada, "Brazil");
  Country *brazil = network.searchNetwork("Brazil");
  network.insertCountry(brazil, "India");
  Country *india = network.searchNetwork("India");
  network.insertCountry(india, "China");
  Country *china = network.searchNetwork("China");
  network.insertCountry(china, "Australia");
  network.printPath();

  network.insertCountry(brazil, "Colombia");
  network.printPath();
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}