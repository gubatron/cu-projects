#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double process_name(string Name, double total, double p)
{
   if (total > 0)
   {
      cout << Name << " ";
      total = total - p;
   }
   return total;
}
int main()
{  
   ifstream in_file;
   in_file.open("babynames.txt");
   
    // Check for failure after opening
   if (in_file.fail()) 
   { 
      return 0; 
   }
   // declare variables
   int rank;
   string name;  // reuse them for boys and girls
   int count;
   double percent;
   double boy_total = 50;
   double girl_total = 50;
   
   // read one line at a time from file and check if it should be displayed
   while (boy_total > 0 || girl_total > 0)
   {
         in_file >> rank;
         cout << rank << " ";
         in_file >> name >> count >> percent;
         // process boy info: print rank and the name as long as < 50%
         boy_total = process_name(name, boy_total, percent);
         
         in_file >> name >> count >> percent;
         // process girl info
         girl_total = process_name(name, girl_total, percent);
         
         cout << "\n";
   }
   return 0;
}	

/*You can use the fileObject.fail() function to check if the file open 
was successful or not. This will return true if the file open has failed and 
false otherwise.*/