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

    int intChoice=-1;
    string choice;
    string name;
    string message;
    string newCountry; // name of country to add to network
    string previous;   // name of country already in network

    Country *temp;     // for searchNetwork case 4

    while (intChoice != 8) {
        displayMenu();
        intChoice = -1;
        while (intChoice == -1) {
            getline(cin, choice);
            try {
                intChoice = stoi(choice);
            } catch (std::invalid_argument &e) {
                intChoice = -1;
                cout << "#> ";
            }
        }

        switch (intChoice) {
            case 1: // Build Network
                network.loadDefaultSetup();
                network.printPath();
                cout << endl;
                break;

            case 2: // Print Network Path
                network.printPath();
                cout << endl;
                break;

            case 3: // Transmit Message
                cout << "Enter name of the country to receive the message:" << endl;
                getline(cin, name);
                cout << "Enter the message to send:" << endl;
                cout << endl;
                getline(cin, message);
                network.transmitMsg(name, message);
                cout << endl;
                break;

            case 4: // Add Country
                cout << "Enter a new country name:" << endl;
                getline(cin, newCountry);
                cout << "Enter the previous country name (or First):" << endl;
                getline(cin, previous);
                temp = network.searchNetwork(previous);
                // if previous not found in the list, print INVALID
                while (temp == nullptr) {
                    cout << "INVALID country...Please enter a VALID previous country name:" << endl;
                    getline(cin, previous);
                    temp = network.searchNetwork(previous);
                }
                cout << endl;
                network.insertCountry(temp, newCountry);
                network.printPath();
                cout << endl;
                break;

            case 5: // Delete Country
                cout << "Enter a country name:" << endl;
                getline(cin, name);
                network.deleteCountry(name);
                network.printPath();
                cout << endl;
                break;

            case 6: // Reverse Network
                network.reverseEntireNetwork();
                network.printPath();
                cout << endl;
                break;

            case 7: // Clear Network
                network.deleteEntireNetwork();
                cout << "Deleted network" << endl;
                cout << endl;
                break;

            case 8: // Quit
                cout << "Quitting... cleaning up path: " << endl;
                network.printPath();
                network.deleteEntireNetwork();
                cout << "Deleted network" << endl;

                if (network.isEmpty()) cout << "Path cleaned" << endl;
                else cout << "Error: Path NOT cleaned" << endl;

                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid input" << endl << endl;
        }
    }
    return 0;
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu() {
    //cout << endl;
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