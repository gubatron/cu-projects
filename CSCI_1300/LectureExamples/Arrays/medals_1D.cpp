#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
   const int SPORTS = 11;

   string sports[] =
      {
         "Alpine Skiing",
         "Figure Skating",
         "Speed Skating",
         "Snowboarding",
         "Luge",
         "Cross-Country Skiing",
         "Freestyle Skiing"
         "Hockey"
         "Curling"
         "Short track"
         "Bobsled"
      };
   
   int gold_medals[SPORTS] =   {1, 0, 0, 4, 0, 1, 1, 1, 0, 0, 0};
   int silver_medals[SPORTS] = {1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 1};
   int bronze_medals[SPORTS] = {1, 2, 1, 1, 0, 0, 1, 0, 0, 0, 0};

   // Create a table with the total gold, silver and bronze medals
   cout << "\tGold\tSilver\tBronze\tTotal" << endl;

   // might need some variables
   int total_gold = 0;
   int total_silver = 0;
   int total_bronze = 0;
   
   // Print gold, silver and bronze total for the USA
   for (int i = 0; i < SPORTS; i++)
   {
      total_gold = total_gold + gold_medals[i];
      total_silver = total_silver + silver_medals[i];
      total_bronze = total_bronze + bronze_medals[i];
   }
   
   cout << "\t" << total_gold << "\t" << total_silver << "\t" << total_bronze << "\t" << total_gold + total_silver + total_bronze << endl; 
   
   // which sport got the most gold medals
   // 1. find the max and the position of the max
   int max = gold_medals[0];
   int pos = 0;
   for (int i = 1; i < SPORTS; i++)
   {
      if (gold_medals[i] > max)   
      {
         max = gold_medals[i];
         pos = i;
      }
   }
   // 2. find the sport associated with this position
   cout << "Max gold medals = " << max << " for " << sports[pos] << endl;
   
   // What about total medals per sport
   int total_medals[SPORTS];
   for (int i = 0; i < SPORTS; i++)
   {
      total_medals[i] = gold_medals[i] + silver_medals[i] + bronze_medals[i];
      cout << total_medals[i] << endl;
   }
   // 1. Let's use a function
   
   // 2. Check at the end that the values in third array have changed
   
   
   // Add a sport
   
   
   // Remove a sport
   
   
   
   return 0;
}


void addarray(int size,         // IN size of arrays
              int A[],  // input array
              int B[],  // input array
              int C[])  // result array

// Takes three arrays of the same size as input parameters 
// and outputs an array whose elements are the sum of the
// corresponding elements in the three input arrays.
{
   for (int i = 0; i < size; i++)
   {
      C[i] = A[i] +  B[i] + C[i];
   }

} // End of function addarray
