#ifndef CASHREGISTER_H
#define CASHREGISTER_H

/**
   A simulated cash register that tracks the item count and
   the total amount due.
   Header file
 */
class CashRegister
{
public:
   /**
      Constructs a cash register with cleared item count and total.
      Any body can use them but attributes are private. 
   */
   CashRegister();

   /**
      Clears the item count and the total.
   */
   void clear();

   /**
      Adds an item to this cash register.
      @param price the price of this item
   */
   void add_item(double price);

   /**
      @return the total amount of the current sale
   */
   double get_total() const;

   /**
      @return the item count of the current sale : double
   */
   int get_count() const;

private: //data members that are constantly being displayed
         //implicitly passed into function 
   int item_count;
   double total_price;
}; // <-- DON'T FORGET ";"

#endif


///*
Public:
double getTotal();
void setTotal(double tot);
int getNumItems();
void setNumItems(int num);
//*/
