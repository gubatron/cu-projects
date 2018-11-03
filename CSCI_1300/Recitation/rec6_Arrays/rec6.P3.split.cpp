#include <iostream>
#include <string>
using namespace std;

/**
 * split will split the input string into pieces separated by the 
 *  delimiter, and populate the array of strings with the split pieces 
 *  up to the provided maximum number of pieces.
 * Input parameters:    str : string (to be split)
 *                      delim : char (marks where the above string should be split up)
 *                      pieces[] : string (array to store the split-apart string pieces)
 *                      max : int  (maximum number of split-apart string pieces - length of pieces[])
 *                      ^ depends on the length of the input string    
 * Output: Nothing
 * Return: number of pieces the input strin was split into : int
*/

int split(string str, char delim, string pieces[], int max)
{
    int i;
    int count = 0;  // sets defined variable count to 0
    string tempString = ""; // shows there is nothing there at start
    for (i = 0; i < str.length(); i++)  // -1 to take care of last index being a delim
    {
        if (str[i] == delim && tempString != "") // takes care of leading delims (*) and >1 delim (*)in a row "**Hello**World"
        {            
            if (count == max)
            {
                count++;
                tempString = "";
                break;
            }
            pieces[count] =  tempString;  // don't add this to your array
            tempString = ""; // resets 
            count++;
        }    
        else if (str[i] != delim)
        {   
            tempString = tempString + str[i]; //adds the variable in the position to nothing
        }
    }
    if (tempString != "")
    {
        count++;
    }
    if (count > max)
    {
        count = -1;
    }
    return count;
}

int main()
{
    string pieces[6];
    cout << split("ab ab ab ab  as as ab     ", ' ', pieces, 6); // expected: 1
    return 0;
}
 
 /**
 IONA'S HELP
 
 split
 - longString - a string
 - delimeter - a character
 - array of strings 
 - max no of words
 
 Example:
 "one two three", ' ', words[], 5
 words = {"one", "two", "three"}
 return 3
 
 Appending delimeter   // look at challenge 1. 
 "one two three" + ' '
 
 Must traverse the longString (hint: for loop) -- visits each character one at a time
 Approach 1: use substrings
 * every time we find the delimiter, we try to find the substring before it
 - between two occurences of the delimeter
 - Note: saving indices of the delimeter into a separate array. Process that array afer the for loop
 - create substrings:
    a) before first delimiter
    b) between each pair of delimiters
    c) after the last delimiter
    
 Approach 2: accumulating a string
 - start with a temp string = "" (empty)
 - every time you visit a character
    - if not delimeter: add to the temp string (concatenation)
    - when find the delimeter: 
        if (something is not true (temp has an empty string - I'm either at beginning or they're 2 in a row)) -- save it reset it
            I only want to save the word if this condition is not ture, otherwise keep going until I find characters I want. 
        - save/add/put temp string into the array words[]
        - reset the temp string to ""
        - ++ index variable
    
Challenges:
1. the last "word": is there anything left over?
    *start solution by appending the delimeter at the end -- 
    A1: check the value of the index of the last occurence of the delimeter
    A2: check if temp is empty or not. If it's empty, that's the delimeter. If it's not, it is a word to add
2. Edge case: if the number of words is begger than "max no of words" parameter, Return -1
    "one two three", ' ', words[], 1
    return -1                  b/c ^ too low 
    When do you know how many words you have? -- have a counter or index that is modified
        every time you save into words[]
        The final value of this counter variable is at the end of the loop because you've finished going through string. 
        
        Do  - save/add/put into the array words[]
            - reset the temp string to ""
            - ++ index variable
                                    if counter agrees with number of elements
3. Special cases:
    a) longString starts with the delimeter
    " one two three", ' ', words[], 5
    
    b) back-to-back delimeters
    "  one  two  three  ", ' ', words[], 5
    Not different from a... 
    A1: characters no is 0 so we have an empty string. 
    A2: the moment you found the 1st delim, you reset the temp string, you find the second, so you reset it again
    
    A1: maybe have 2 variables: current index of delimeter and previous index of delimeter
        make sure difference between two consecutive arrays is >1
    A2: 
*/


// weird cases to track 
// input string and character - need to split string into pieces such that character 
// indicates those brakes. 
/**
 * string inputString = "Mississippi";
 * char delimiterChar = 'i';
 * 
 * string inputPieces[6] = {"M", "ss", "ss", "pp"};  // split with 'i'
 * string inputPieces[6] = {"Mi", "i", "ippi"};  // split with 's'
 * 
 * return 0;
 * 
 * // i in front or anywhere or repeated many times (iiii), they exist as one and don't exist at all
 * */
 
    
    
    // if (max - 1 < count)
    //     {
    //         return -1;
    //     }
    //     else if(str[i] == delim && tempString != "")
    //     {
    //         count++; // add one to the count
    //         pieces[count] =  tempString;  // don't add this to your array
    //         tempString = ""; // resets tempString
    //         // for last piece, if there is a delim at the end, 
    //         if(str[i-1] == delim) // if last index is delimeter, remove one from count
    //         {
    //             count--;
    //         }
    //     }
    //     else if (str[i] != delim)
    //     {
    //         tempString = tempString + str[i]; //adds the variable in the position to nothing
    //         pieces[count] = tempString; //adds substring using earlier equation, and uses count to see how many lines
    //     }