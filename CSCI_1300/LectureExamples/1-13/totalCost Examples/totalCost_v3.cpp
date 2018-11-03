        
#include <iostream>
using namespace std;

double totalCost(int numberParameter, double priceParameter, double taxParameter);
int getNumber();

int main( )
{
    double price, bill, tax;
    tax = 0.5;
    int number;
    
    // We want to replace the two lines below with a function that 
    //asks the user for input and returns the value entered by the user
    //cout << "Enter the number of items purchased: ";
    //cin >> number;
    number = getNumber(); //the function call becomes the assignment operation for the variable number
    
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

    