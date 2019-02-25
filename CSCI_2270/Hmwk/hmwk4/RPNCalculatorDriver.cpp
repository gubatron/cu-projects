/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*          Implement driver as described in the writeup        */
/****************************************************************/

//#include "RPNCalculator.hpp"
#include <iostream>
#include "RPNCalculator.hpp"
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

void test1(){
    RPNCalculator calc;
    Operand * node = calc.peek();
    if(node == NULL) cout << "Correct!" << endl;
    else cout << "head is not NULL, check constructor" << endl;
}

void test2(){
    RPNCalculator calc;
    calc.push(4.3);
    Operand * stackTop = calc.peek();
    cout << "Top of stack: " << stackTop->number << endl;
}

void test3() {
    RPNCalculator calc;
    calc.push(4.3);
    calc.push(-17);
    calc.push(1.1839);
    calc.push(0.2);
    Operand * temp = calc.peek();
    cout << "Print stack from top to bottom:" << endl;
    while(temp != NULL){
        cout << temp->number << endl;
        temp = temp->next;
    }
};

int main()
{
    test1();
    test2();
    test3();
    if (true) return 0;


  // $ Declare a stack to hold the operands
    RPNCalculator operand;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";
    /* $ TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */

  }

    /* $ TODO - If the stack is empty then print "No operands: Nothing to evaluate" */
//    if (operand.isEmpty()) std::cout << "No operands: Nothing to evaluate" << std::cout;

  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/

  return 0;
}
