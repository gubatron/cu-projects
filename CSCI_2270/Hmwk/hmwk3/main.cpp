/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <string> // for getline
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char *argv[]) {
    CountryNetwork network;
    network.insertCountry(nullptr, "United States");
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

    string choice;

    string name;
    string message;
    string newCountry; // name of country to add to network
    string previous;   // name of country already in network

    while (choice != "8") {
        displayMenu();
        getline(cin, choice);
        switch (stoi(choice)) {
            case 1: // Build Network
                network.loadDefaultSetup();
                network.printPath();
                break;

            case 2: // Print Network Path
                network.printPath();
                break;

            case 3: // Transmit Message
                cout << "Enter name of the country to receive the message:" << endl;
                getline(cin, name);
                cout << "Enter the message to send:" << endl;
                getline(cin, message);
                network.transmitMsg(name, message);
                break;

            case 4: // Add Country
                cout << "Enter a new country name:" << endl;
                getline(cin, newCountry);
                cout << "Enter the previous country name (or First):" << endl;
                getline(cin, previous);
                network.searchNetwork(newCountry);
                while (newCountry == previous) {
                    cout << "INVALID country...Please enter a VALID previous country name:" << endl;
                    getline(cin, previous);
                }
                Country *previous;
                network.insertCountry(previous, newCountry);
                // todo Angel: function takes type Country but getline takes type string
                network.printPath();
                break;

            case 5: // Delete Country
                cout << "Enter a country name:" << endl;
                getline(cin, name);
                network.deleteCountry(name);
                network.printPath();
                break;

            case 6: // Reverse Network
                network.reverseEntireNetwork();
                network.printPath();
                break;

            case 7: // Clear Network
                network.deleteEntireNetwork();
                break;

            case 8: // Quit
                cout << "Quitting... cleaning up path: " << endl;
                network.printPath();
                network.deleteEntireNetwork();

                if (network.isEmpty()) cout << "Path cleaned" << endl;
                else cout << "Error: Path NOT cleaned" << endl;

                cout << "Goodbye!" << endl;
                break;
                
            default:
                cout << "invalid input" << endl << endl;
        }
    }
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu() {
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