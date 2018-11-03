#include <iostream>
#include <string>
#include <algorithm> // to use max()
using namespace std;

/**
 * The code has two parts. The simScore that needs to be calcuated and the analyzer function
 * for the doctors to use. 
 * 
           *  NOTES!
           *  1)  "const string &reference" makes sure variables remain unchanged throughout
           *      and are not copied in memory as they're passed to the functions. 
           *              Genomes will exist only once in memory to save space!
           *  2) I created extra functions for my tests to make the output more visually appealing
           *      and easier to read.
 * 
 * 
 * 1)For the simScore() we need a function that returns the similarity score for TWO sequences
 *      It says: for as long as the first string does not equal the second string,
 *      OR the first string does not equal zero OR the second string does not equal zero, 
 *      it will return zero. 
 *      If none of that applies, then it will evaluate the given equation in the problem statement:
 *          (s1.length() - hammingDistance(s1, s2)) / (double)s1.length();
 *          s1 is a double in the denominator in order to get decimals as answers. 
 * In order to use simScore() I will need a hammingDistance function that returns the number of 
 *      different characters position-by-position between the two strings used. 
 *      It says:  for as long as the first string does not equal the second string,
 *      OR the first string does not equal zero OR the second string does not equal zero, 
 *      it will return zero. 
 *      If none of that applies, the distance will be zero and it will increment the distance using a 
 *          for loop shen the index of the statement 1 does not equal the index of statement 2
 * 
 * 2)For the analyzer function, I will need two more functions in order to properly implement the 
 * simScore function properties. 
 *      1) bestSimScore is used to return the best score that is reproduced as the string is scanned. 
 *      Depending on the length of the bacteria sequence, bestSimScore will evaluate the genomes
 *      in chunks sizes of the bacteria sequence and update a simScore every time it finds a better one. 
 *          When the genome length is the same as the sequence length, there is no need to scan because 
 *          they're the same size. 
 *          While the index is less than the length of the genome, it will compare a tempScore that 
 *          consists of the simScore comparing the genome substring and the sequence.
 *              If the tempScore is greate than the bestScore, bestScore = tempScore. 
 *              as long as this is true, it will continue to increment the index (i++)
 *      2) parametersValid goes through the cases that produce ERRORS. If it is false, it will return the 
 *      possible errors as cout statements. If they turn out to be valid, it will return true and proceed 
 *      with evaluating analyzer()
 * 
 *  In analyzer() I will check for the cases that are valid. 
 *      It calls parametersValid() and returns what it says if they are NOT VALID
 *      It then creates variables for the three individual genome scores and it the bacteria sequence
 *          length is equal to the genome1 length, it will evaluate the scores of all three and call to
 *          simScore to get the individual scores. 
 *      if the bacteriaSequence length does not equal genome1 (else), that is the sequence length is smaller,
 *      we will need to find the best score of the sequence accross each genome segement of the same size of the 
 *      sequence. This is done by calling to bestSimScore with each of the genome strings.
 *  Once these are calculated, using max() function [ADD LIBRARY <algorithm>] I will compare 1 and 2, 
 *  then 2 and 3 and so on. If one is the best, or two, or three, cout the respective statements. 
 *
 */
 
//////////////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////////////

/**
 * Hamming Distance Function
 *  returns number of different characters
 *  position-by-position between two strings
 * Input parameters:    s1:string;
 *                      s2:string
 * ouput: nothing
 * returns: number of chars:int
 */
int hammingDistance(const string &s1, const string &s2)
{
  if (s1.length() != s2.length() || s1.length() == 0 ||
      s2.length() == 0)  // s1.empty or s2.empty
  {
    return 0;
  }
  int distance = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) {
      distance++;
    }
  }
  return distance;
}

/**
 * Similarity Score Function
 *  simScore returns the similarity score for
 *  two strings/sequences
 *  Input parameters:    s1:string;
 *                       s2:string
 * ouput: nothing
 * returns: similarity score:double
 */
double simScore(const string &s1, const string &s2)
{
  if (s1.length() != s2.length() || s1.length() == 0 ||
      s2.length() == 0)  // s1.empty or s2.empty
  {
    return 0;
  }
  return (s1.length() - hammingDistance(s1, s2)) / (double)s1.length();
}

/**
 * bestSimScore moves along the genome and finds the best score as it goes along.
 * Depending on the length of the bacteria sequence, 
 * best simScore will evaluate the genomes in chunks sizes of the bacteria sequence
 * and update a simScore every time it finds a better one.
 * Input parameters   genome:string;
 *                    seq: string
 * Output: nothing
 * Returns:   bestScore: double
*/
double bestSimScore(const string &genome, const string &seq)
{
  if (genome.length() == seq.length())
  {
    return simScore(genome, seq); // no need to scan string because they're the same size
  }
  int i = 0; // i is the beginning
  double bestScore = 0; 
  int end = genome.length()-seq.length();
  int seqLength = seq.length();
  while (i < end)
  {
    double tempScore = simScore(genome.substr(i, seqLength), seq);
      if ( tempScore > bestScore)
      {
          //score of sequence in substring
          bestScore = tempScore;
      }
      i++;    // goes forwards
  }
  return bestScore;
}

/**
 * parametersValid() validates parameters
 *     and displays errors
 * input:  genome1:string;
 *         genome2:string;
 *         genome3:string;
 *         bacteriaSequence:string;
 * output: error messages when parameters are invalid
 * return: boolean. `true` if parameters are valid, `false` otherwise
 */
bool parametersValid(const string &genome1, const string &genome2,
                     const string &genome3, const string &bacteriaSequence) 
{
  const string ERROR_1 = "Genome and sequence cannot be empty.";
  const string ERROR_2 = "Genome length does not match.";
  const string ERROR_3 = "Sequence length must be smaller than genome length.";

  // either one is empty
  if (genome1.empty() || genome2.empty() || genome3.empty() ||
      bacteriaSequence.empty()) {
    cout << ERROR_1 << endl;
    return false;
  }
  // all genomes must have same length
  if (!(genome1.length() == genome2.length() &&
        genome2.length() == genome3.length())) {
    cout << ERROR_2 << endl;
    return false;
  }
  // sequence length can't be greater than genome
  if (bacteriaSequence.length() >
      genome3.length())  // any (1,2,3) because they all have same dist
  {
    cout << ERROR_3 << endl;
    return false;
  }
  return true;=
}

/**
 * analyzer function
 *     helps doctros find the best matching sequence amongst
 *     the three known genomes with a sequence from the unknown bacteria
 * input:  genome1:string;
 *         genome2:string;
 *         genome3:string;
 *         bacteriaSequence:string;
 * output: displays best matching genome(s)
 * return: nothing:void
 */
void analyzer(const string &genome1, const string &genome2,
              const string &genome3, const string &bacteriaSequence) 
{
  if (!parametersValid(genome1, genome2, genome3, bacteriaSequence))
  {
    return;
  }
  
  double g1score, g2score, g3score;

  // naive case, sequence size matches genome's size
  if (bacteriaSequence.length() == genome1.length()) 
  {  
    g1score = simScore(genome1, bacteriaSequence);
    g2score = simScore(genome2, bacteriaSequence);
    g3score = simScore(genome3, bacteriaSequence);
  } 
  else 
  {
    // seq length is smaller, therefore we need to find the best score of the sequence across each
    // genome segment of the same size of the sequence.
    g1score = bestSimScore(genome1, bacteriaSequence);
    g2score = bestSimScore(genome2, bacteriaSequence);
    g3score = bestSimScore(genome3, bacteriaSequence);
  }
  
  double bestScore = max(g1score, g2score);
  bestScore = max(bestScore, g3score);
  if (g1score == bestScore)
  {
    cout << "Genome 1 is the best match." << endl;
  }
  if (g2score == bestScore)
  {
    cout << "Genome 2 is the best match." << endl;
  }
  if (g3score == bestScore)
  {
    cout << "Genome 3 is the best match." << endl;
  }
}


//////////////////////////////////////////////////////////////////////////////////////////
// TESTS
//////////////////////////////////////////////////////////////////////////////////////////
void scoreTest(const string &s1, const string &s2)
{
  // TODO: Add expected value parameter
  cout << "hammingDistance(" << s1 << ", " << s2
       << "): " << hammingDistance(s1, s2) << endl;
  cout << "simScore(" << s1 << ", " << s2 << "): " << simScore(s1, s2) << endl
       << endl;
}

void bestSimScoreTest(const string &genome, const string &seq, double expected)
{
  double score = bestSimScore(genome, seq);
  if (score == expected)
  {
      cout << "bestSimScoreTest PASSED: expected = " << expected << " , actual = " << score;
  }
  else
  {
      cout << "bestSimScoreTest FAILED: expected = " << expected << " , actual = " << score;
  }
  cout << endl << endl;
}

void analyzerTest(const string &genome1, const string &genome2,
                  const string &genome3, const string &bacteriaSequence, const string &expectedOutput) 
{
  cout << "ACTUAL OUTPUT:" << endl;
  analyzer(genome1, genome2, genome3, bacteriaSequence);
  cout << "---------------------------" << endl << "EXPECTED OUTPUT:" << endl << expectedOutput << endl << endl;
}

int main()
{
  // tests for both Hamming Distance and Similarity Score
  scoreTest("", "");                    // expected value: 0
  scoreTest("ATGC", "ATGA");            // expected value: 0.75
  scoreTest("CCDCCD", "CCDCCD");        // expected value: 1
  scoreTest("ATG", "GAT");              // expected value: 0
  scoreTest("ACCDT", "ACCT");           // expected value: 0
  scoreTest("CGT", "DGGTA");            // expected value: 0
  scoreTest("GACCGACTAA", "DGGTA");     // expected value: 0
  
  bestSimScoreTest("GACCGACTAA","TACTA", 0.8);
  bestSimScoreTest("GACCGACTAA","GACTA", 1);
  bestSimScoreTest("AATGTTTCAC","TACTA", 0.4);
  bestSimScoreTest("AAGGTGCTCC","TACTA", 0.6);
  bestSimScoreTest("","TACTA", 0);
  bestSimScoreTest("AACT","AATG", 0.5);
  
  analyzerTest("TAATC", "CATTA", "TAATC", "ACTATTT", "Sequence length must be smaller than genome length.");
  analyzerTest("", "CATTA", "TAATC",  "ACTA","Genome and sequence cannot be empty.");   
  analyzerTest("TAATC", "CATTAA", "TAATC", "ACTA", "Genome length does not match");
  analyzerTest("AATGTTTCAC", "GACCGACTAA", "AAGGTGCTCC", "TACTA", "Genome 2 is the best match.");
  analyzerTest("AACT", "AACT","AATG", "AACT", "Genome 1 is the best match.\nGenome 2 is the best match.");
  analyzerTest("ACATC", "ACTTA", "TACAT", "AACT", "Genome 1 is the best match.\nGenome 2 is the best match.\nGenome 3 is the best match.");
  
  return 0;
}