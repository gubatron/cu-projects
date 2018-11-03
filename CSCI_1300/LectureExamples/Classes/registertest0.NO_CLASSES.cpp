#include <iostream>
#include <iomanip>

using namespace std;

// Solution without using classes

/**
   Resets total price to 0.
   @param nothing
   Returns 0 for the value of total price
*/
double clearTotal()
{
   return 0;
}
/**
   Resets item count to 0.
   @param nothing
   Returns 0 for the value of item count
*/
int clearNumItems()
{
   return 0;
}

/**
   Adds one item. Adds the price value to the total.
   @param total, price
   Returns the new value for total
*/
double addItemToTotal(double total, double price)
{
   return (total + price);
}
/**
   Displays the item count and total price of a cash register.
   @param reg the cash register to display
*/
void display(double tot, int items)
{
   cout << items << " $" << fixed << setprecision(2) 
      << tot << endl;
}

int main()
{
   double total;  //Declare variables
   double price;
   int numItems;
   
   // start at 0
   total = clearTotal();
   numItems = clearNumItems();
   
   // add item
   price = 1.95;
   total = addItemToTotal(total, price);
   numItems++;
   // display
   display(total, numItems);
   
   // add item
   price = 0.95;
   total = addItemToTotal(total, price);
   numItems++;
   // display
   display(total, numItems);
   
   // add item
   price = 2.50;
   total = addItemToTotal(total, price);
   numItems++;
   // display
   display(total, numItems);

   // start at 0
   total = clearTotal();
   numItems = clearNumItems();
   // display
   display(total, numItems);
   return 0;
}


    