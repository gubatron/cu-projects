#include <iostream>
#include <iomanip>
#include "cashregister.h" // header file "cashregister.h"
using namespace std;                   //      v
                                       //      v
// implementation file                 //      v
// cpp file that includes the header file "cashregister.h"

CashRegister::CashRegister()
{
   clear();
}

void CashRegister::clear()
{
   item_count = 0;
   total_price = 0;
}

void CashRegister::add_item(double price)
{
   item_count++;
   total_price = total_price + price;
}

double CashRegister::get_total() const 
{
   return total_price; 
}

int CashRegister::get_count() const
{
   return item_count; 
}



