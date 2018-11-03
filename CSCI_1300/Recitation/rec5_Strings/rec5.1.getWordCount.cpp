#include <iostream>
using namespace std;

/**
 * getWordCount function takes a sentence and returns 
 * number of words in the sentence.
 * Input parameters: s (string)
 * Output: nothing
 * Returns: number of words in sentence (int)
*/

int getWordCount(string s)
{
    int words = 0; // holds number of words
    if (s.length() > 0) // empty string. if (s == "")
    {
        bool inWord = (s[0] != ' ');
        for (int i = 0; i < s.length(); i++)
        {
            if (i == s.length() - 1) {
                inWord = (s[i] != ' ');
            }
            
            if (inWord && (s[i] == ' ' || i == s.length() - 1) ) // or last character
            {
                words++;
            }
            inWord = (s[i] != ' ');
        }
    }
    return words;
}

int main()
{
    string s;
    s = " xj jqwft ixjhid hcru wnurxcn qxjz ssd laiklp ogdsz kvne kiby zjagbuk fmkpz jnjm kmr bx ofxmg vie cqcjcpy a";
    cout << getWordCount(s);
}


// for number of words
// int main( )
// {
// 	char str[80];
	
// 	cout << "Enter a string: ";
// 	cin.getline(str,80);
	
// 	int words = 0; // Holds number of words
	
// 	for(int i = 0; str[i] != '\0'; i++)
// 	{
// 		if (str[i] == ' ') //Checking for spaces
// 		{
// 			words++;
// 		} 		
// 	}

// 	cout << "The number of words = " << words+1 << endl;

// 	return 0;
// }