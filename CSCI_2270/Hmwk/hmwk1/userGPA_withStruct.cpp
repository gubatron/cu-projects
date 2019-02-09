#include <iostream>
#include <fstream>
#include <sstream> // for string stream
#include <utility> // for std::move()

/* OVERVIEW:
 * Program reads a .csv file with up to 100 lines and
 * stores the information in an array of structs and
 * also writes the lines whose gpa is greater than a minimum value to a output .csv file.
 * Each line of the input file corresponds to a struct element in the array.
 * Then you will allow the user to print the contents of the array. */

/* A structure is useful for storing an aggregation of elements
 * Elements must be different types and each field has a given name*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// struct User declaration
struct User {
    std::string username;
    float gpa{}; // {} initializes gpa field
    int age{}; // {} initializes age field
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* addUser function instantiates a struct and stores the username, gpa, age values in it
    ads the struct to the users array
    length: number of items currently s
 The line in this comment is written by me, the line in written function is Clion's "Tidy" feature
 correcting the way I used _username because the parameter is passed by value and only copied once;
 moving it avoids unnecessary copies*/
void addUser(User users[], std::string _username, float _gpa, int _age, int length) {
    User u;
    u.username = std::move(_username); // std::move() is Clion's "Tidy" feature corrects the way the parameter is passed
                                       // makes sure the parameter is copied only once; avoids unnecessary copies
    u.gpa = _gpa;
    u.age = _age;
    users[length] = u;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* printList function loops through the populated array
 * prints out each element of the list in the format: “<USERNAME> [<GPA>] age: <AGE>”
 * length: Number of items in the array */
void printList(const User users[], int length) {
    for (int i = 0; i < length; i++)
        std::cout << users[i].username << " [" << users[i].gpa << "] age: " << users[i].age << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* saveUsers function takes a new user and writes it to the file
 *   Since one cannot copy streams, pass a pointer to get the same stream*/
void saveUsers(User u[], int length, std::ofstream *fileout) {
    for (int i = 0; i < length; i++)
        *fileout << u[i].username << "," << u[i].gpa << "," << u[i].age << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*creates users by parsing each line using getline*/
User createUser(const std::string &line) { // as a const reference its not copied unnecessarily
    std::istringstream iss(line); // input to a string
    User u;
    std::string buffer;

    getline(iss,buffer,',');
    u.username = buffer;

    getline(iss,buffer,',');
    u.gpa = stof(buffer);

    getline(iss,buffer,',');
    u.age = stoi(buffer);

    return u;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void main(int argc, char **argv) {
    // edge case, must have 3 arguments (0: title; 1: username; 2: gpa; 3: age)
    if (argc != 4) {
        std::cout << "Error: incorrect number of arguments" << std::endl;
    }

    //array that holds the User struct objects to be populated with file data
    User users[100];

    // reading from input file "data.csv"
    std::ifstream filein;
    filein.open("data.csv"); // TEST
    //filein.open(argv[1]); // 1 is the first argument -- csv file to read from
    if (filein.fail()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line; // line in file to read
    std::string username;
    int age = 0;
    int counter = 0;
    double min_gpa = std::stof(argv[3]); // converting the third argument which is a char string to a float
    User user;

    // going through the file
    while(std::getline(filein,line)){

        user = createUser(line);

        if (user.gpa >= min_gpa) {
            // populate users array per person added and use counter as the length in both addUser and printList
            addUser(users, user.username, user.gpa, user.age, counter++);
        }

        counter++;
    }
    filein.close(); // done with reading

    // writing to a file
    std::ofstream fileout;
    fileout.open(argv[2]); // 2 is the second argument -- csv file to write to

    // writes new users to csv file; pass pointer because cannot send a copy of a stream
    saveUsers(users, counter, &fileout);
    printList(users, counter); // should print out previously populated array

    fileout.close();
}