#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Step 0:  Understand the processing task.
Program to reverse the lines in a file and write them to a new file. 

 - open the file for reading
 - read each line with getline() into a string
 - reverse the string
 - open a file for writing
 - write reversed string to a file
*/
/**
   Reverse a string that is passed in as a parameter.
   @param newline the string to be reversed
   Return the reversed string
*/
string reverse(string line)
{
   int j = line.length() - 1; // index of the last character
   string copyline = line;  // because we want it to have the same number of characters
   // loop through copyline, copy ch from line from the last to the first
   for (int i = 0; i < line.length(); i++)
   {
      copyline[i] = line[j];
      j--;
   }
   return copyline;
}

int main()
{
   // Step 1:  Determine which files you need to read and write
   // Read from : 
   // Write to: 
   

   // Step 2:  Choose a method for obtaining the file names.
   // a) hardcode them
   // b) ask the user to input file names
   string filename1 = "Mary.txt";
   string filename2 = "Mary_out.txt";
   
   // Step 3. Create file stream objects/variables
   
   // ifstream means input file stream - used for reading from files
   ifstream in;
   
   // oftsream means output file stream - used for writing to files
   ofstream out;

   // Step 4. Associate the file stream object with the file
   //    by using .open(), with the file name (as a string) in parentheses
   in.open(filename1); // open file for reading
   out.open(filename2); // open file for writing

   // Step 4b. Check for failure after opening
   if (in.fail()) // or if (!in.is_open())
   { 
      return 0; 
   }
   
   // Step 5a:  Choose between line, word, and character-based input.
   // declare variables
   string line = ""; // passed to getline
   string revLine;
   // Step 5b: Read each line
   while (getline(in, line))// line contains string for each line in the file
   {
      // Step 6: Process each line
      // Step 6b:  Place repeatedly occurring tasks into functions.
      revLine = reverse(line);
         
      // Step 7:  If required, use manipulators to format the output.
      if (revLine != "")
      {
         cout << revLine << endl;
         out << revLine << endl;
      }
   }
   // Step 8: Don't forget to close the files at the end
   in.close();
   out.close();
   return 0;
}

    
   