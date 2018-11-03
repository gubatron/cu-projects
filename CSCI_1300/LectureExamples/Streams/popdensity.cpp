#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

/** 
   Converts a string to a floating-point number, e.g. "3.14" -> 3.14.
   @param s a string representing a floating-point number
   @return the equivalent floating-point number
*/   
// helper function (we won't cover it in class)
double string_to_double(string s)
{
   istringstream stream;
   stream.str(s);
   double x = 0;
   stream >> x;
   return x;
}

/**
   Extracts the country and associated value from an input line.
   @param line a line containing a country name, followed by a number
   @return country
*/
string read_country(string line)
{ 
   string country;
   int i = 0; // Locate the start of the first digit
   while (!isdigit(line[i])) 
   { 
      i++; 
   }
   int j = i - 1; // Locate the end of the preceding word
   while (isspace(line[j])) 
   { 
      j--; 
      
   }
   country = line.substr(0, j + 1); // Extract the country name
   
   return country;
   
   //value = string_to_double(line.substr(i)); // Extract the number value
   // We can't return both country and value. We need to create read_value()
}

/**
   Extracts the country and associated value from an input line.
   @param line a line containing a country name, followed by a number
   @return population or area
*/
double read_value(string line)
{ 
   string country;
   double value;
   int i = 0; // Locate the start of the first digit
   while (!isdigit(line[i])) 
   { 
      i++; 
      
   }
   /*int j = i - 1; // Locate the end of the preceding word
   while (isspace(line[j])) 
   { 
      j--; 
      
   }*/
   //country = line.substr(0, j + 1); // Extract the country name
   
   //return country;
   
   value = string_to_double(line.substr(i)); // Extract the number value
   return value;
}

int main()
{
   ifstream in1;
   ifstream in2;
   in1.open("worldpop.txt"); // Open input files
   in2.open("worldarea.txt");

   ofstream out;
   out.open("world_pop_density.txt"); // Open output file
   out << fixed << setprecision(2);

   string line1;
   string line2;

   // Read lines from each file
   while (getline(in1, line1) && getline(in2, line2))
   {
      string country;
      double population;
      double area;

      // Split the lines into country and associated value
      country = read_country(line1);
      population = read_value(line1);
      area = read_value(line2);

      // Compute and print the population density
      double density = 0;
      if (area != 0) // Protect against division by zero
      {
         density = population * 1.0 / area;
      }
      out << setw(40) << left << country  
         << setw(15) << right << density << endl;      
   }

   return 0;
}
