        
#include <iostream>
using namespace std;

double totalCost(int numberParameter, double priceParameter, double taxParameter);
int getNumber();

int main( )
{
    double price, bill, tax;
    tax = 0.5;
    int number;
    
    number = getNumber(); // first function call = first test
    number = getNumber(); // second function call = second test
    cout << "The user entered the value: " << getNumber() << endl; // third function call = thrid test
    
    cout << "Enter the price per item $";
    cin >> price;
    bill = totalCost(number, price, tax);

    cout << number << " items at "
    << "$" << price << " each.\n"
    << "Final bill, including tax, is $" << bill
    << endl;
    return 0;
}

//Asks the user for input and returns the value entered by the user.
//No input arguments
//Returns an integer
int getNumber()
{
    int userInputNumber;
    cout << "Enter the number of items purchased: ";
    cin >> userInputNumber;
    return userInputNumber;
}

//Computes the total cost, including 5% sales tax,
//on numberParameter items at a cost of priceParameter each, at taxParameter rate
double totalCost(int numberParameter, double priceParameter, double taxParameter)
{
    // int numberParameter = ...whatever was the first value passed at the function call
    //const double TAXRATE = 0.05; //5% sales tax
    double subtotal;
    subtotal = priceParameter * numberParameter;
    return (subtotal + subtotal*taxParameter);
}

    