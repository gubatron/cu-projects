        
#include <iostream>
using namespace std;

double totalCost(int numberParameter, double priceParameter, double taxParameter);


int main( )
{
    double price, bill, tax;
    tax = 0.5;
    int number;
    cout << "Enter the number of items purchased: ";
    cin >> number;
    cout << "Enter the price per item $";
    cin >> price;
    bill = totalCost(number, price, tax);

    cout << number << " items at "
    << "$" << price << " each.\n"
    << "Final bill, including tax, is $" << bill
    << endl;
    return 0;
}

//Computes the total cost, including 5% sales tax,
//on numberParameter items at a cost of priceParameter each.
double totalCost(int numberParameter, double priceParameter, double taxParameter)
{
    // int numberParameter = ...whatever was the first value passed at the function call
    //const double TAXRATE = 0.05; //5% sales tax
    double subtotal;
    subtotal = priceParameter * numberParameter;
    return (subtotal + subtotal*taxParameter);
}

    