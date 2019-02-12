#include <iostream>
#include "StackLL.h"

using namespace std;

// the following function should print true for exp = “[()]{}{[()()]()}” and false for exp = “[(])”
bool isValid(string input) {
    StackLL stack;
    char x;

    // Traversing the input
    for (int i = 0; i < input.length(); i++) {
        //Switch cases for the closing brackets
        switch (input[i]) {
            case '(':
                stack.push(static_cast<char>(i));
                break;

            case '{':
                stack.push(static_cast<char>(i));
                break;

            case '[':
                stack.push(static_cast<char>(i));
                break;

            default: break;
        }

        // If it is not an opening bracket, then the stack shouldn't be empty
        if (stack.isEmpty())
            return false;


        //Switch cases for the closing brackets
        switch (input[i]) {
            case ')':
                stack.peek();
                stack.pop();
                break;

            case '}':
                stack.peek();
                stack.pop();
                break;

            case ']':
                stack.peek();
                stack.pop();
                break;
            default: break;
        }

    }
    // If stack is not empty, there are unmatched brackets
    return (stack.isEmpty());


}

int main() {
    int choice;
    while (1) {
        cout << "--------------------------------------------------------" << endl;
        cout << "Examine if the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct." << endl << endl;
        cout << "1. Enter the string to be validated  " << endl;
        cout << "2. Quit  " << endl;
        cout << "--------------------------------------------------------" << endl;

        cout << "Choice: ";
        cin >> choice;
        cout << endl;
        string input;
        switch (choice) {
            case 1:

                cout << "Enter the string to be validated: ";
                cin >> input;
                if (isValid(input))
                    cout << "------- Balanced ------ " << endl;
                else
                    cout << "------- Not Balanced -------" << endl;
                break;
            case 2:
                return 0;
            default:
                cout << "------- Oops! Wrong choice ------ " << endl;
                return 0;
        }
    }
    return 0;


}
