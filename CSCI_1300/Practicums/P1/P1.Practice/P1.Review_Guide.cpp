/**
CSCI 1300 – Practicum 1 Review Guide
1a. Data Types :=
    So far this semester we have been working with several types of data:
        ❏ integers (int): any whole number, positive or negative
        ❏ floating point numbers (float, double): any decimal number, positive or
        negative
        ❏ booleans (bool): discrete logical values: true or false
        ❏ characters (char): ‘a’, ‘o’, ‘0’, ‘8’
1b. Casting :=
    Data types are not concrete values themselves, but rather, ways of
    interpreting values. This means that the same value can be 'cast' to different
    data types to create different values.
        For example, the floating point number 10.123 can be cast to an int to produce
        an integer 10.
    C++ contains a built in functions to cast a value to each data type ­ int() ­
    float() ­ str() ­ bool()
2. Variables :=
    Variables are ways of referring to values. They are not the values themselves.
    Each variable has:
        ● a name
            ○ there are rules associated with variable names.
            ○ Must start with ...
            ○ Cannot be a reserved word
        ● a value
        ● a memory address
3. Arithmetic :=
    Know how to perform:
        ➔ Addition
        ➔ Subtraction
        ➔ Multiplication
        ➔ Division
            ◆ Integer
            ◆ floating point
            ◆ modulo/remainder
        ➔ Exponentiation    pow(+0, exp)
        ➔ Taking roots  sqrt()
4. Print/ Output_to_the_command_window / Display :=
    cout statements:
        ● text messages (as strings in “...”)
        ● values of variables
            values from functions calls (functions that return values)
        ● special characters “\n”
        ● endl
5a. Defining Functions :=
    You need to know how to define functions. All functions have 3 major
    components:
        ★ the function must have a unique FUNCTION NAME; review the rules for
        naming a function in C++
        ★ the function takes some INPUT PARAMETERS. Must specify the type for each
        parameter.
        ★ the function may RETURN some value; the function may not RETURN anything
        (void function)
    INPUT PARAMETERS ­> [FUNCTION NAME] ­> RETURN VALUE
    In C++, functions have the following format:
        <return_type> <FUNCTION_NAME>(<0 or more INPUT PARAMETERS, with each type>)
        {
            <FUNCTION BODY> <optional RETURN STATEMENT>
        }
        Example:
        Int addNums (int num1, int num2)
        {
            int answer = num1 + num2;
            return answer;
        }
5b. Calling Functions :=
    Once you define a function you can begin to call it. To call a function,
    simply type the function name EXACTLY AS IT WAS DEFINED and pass the necessary
    arguments.
        NOTE: FUNCTION NAMES ARE CASE­SENSITIVE
            ❖ Calling functions that return a value
            ❖ Calling functions that do not return anything
6. Conditionals :=
    A conditional can be described as any statement that evaluates to a boolean
    True or False.
        ➢ A conditional might be an arithmetic expression:
            x > 10
            x != 8
            x <= 1000000
        ➢ A conditional might also be the result of function that itself returns a
        True or False:
            bool divisible_by_4(int x)
            {
                return x % 4 == 0;
            }
            Example:
                divisible_by_4(10) returns false
                divisible_by_4(16) returns true
        ➢ Conditionals can also be chained together using logical NOT, AND and OR
        statements.
            x > 0 && divisible_by_4(x) => x IS positive AND x is divisible by 4
            x <= 0 || !divisible_by_4(x) => x is NOT positive OR x is NOT divisible by 4
            Logical Operators
                AND means that both sub­conditionals must be True for the entire conditional
                to be True. Otherwise the entire conditional with be False.
                    Truth Table:
                    X && Y
                    T && T=T
                    T && F=F
                    F && T=F
                    F && F=F
                OR means that if either sub­conditional is True then the entire conditional
                will be True. If both sub­conditionals are False, then the entire conditional
                will be False.
                    Truth Table:
                    X || Y
                    T || T=T
                    T || F=T
                    F || T=T
                    F || F=F
7. If, else, IF­ELSE Blocks :=
    Conditionals allow our programs to have different behavior depending on
    certain conditions that we specify. Because of this they are also referred to
    as Control­Flow statements because they CONTROL the FLOW of our programs.
    To specify conditions we use if,else if,else blocks:
        if (<some condition>)
        {
            <do this>
        }
        else if (<some other condition>)
        {
            <do that>
        }
        else
        {
            <if none of the above cases were true, do something else>
        }
        Example:
        if (x > 0)
            cout << “x is positive” ;
        else if (x < 0)
            cout << “x is negative” ;
        else
            cout << “x is neither positive nor negative; x equals 0”;
    There are several important things to understand about if­else blocks.
        ❖ Each block represents an isolated test. This means that within the
        context of an if­elseif­else block, once a condition is satisfied, the
        entire block is done.
            For example: in the above example, as soon as x is determined to be positive,
            negative, or zero, the entire block is done.
            No additional cases will be tested. However, if we instead wrote:
                if (x > 0)
                    cout << “x is positive”;
                if (x < 0)
                    cout << “x is negative”;
                if (x == 0)
                    cout << “x is neither positive nor negative; x equals 0”;
                then regardless of the value of x, all the conditions will be checked each
                time the code runs.
        ❖ An if­elseif­else block must begin with an if statement.
        ❖ An if statement can be ended with 0 OR 1 else statement.
        ❖ That initial if statement can be followed by 0 OR MORE else if
            statements that check additional conditions.
        ❖ The final else statement should serve as a catch­all or default case.
            i.e. if none of the above cases are true, then “do this”.
8. Switch Statement
    The switch statement lets you choose from a fixed set of alternatives. It has
    a sequence of if statements that compares a single integer value against
    several constant alternatives.
    Every branch of the switch must be terminated by a break instruction. If the
    break is missing, execution falls through to the next branch, and so on, until
    finally a break or the end of the switch is reached. The default branch is
    chosen if none of the case clauses match.
    Example:
        int number;
        ...
        switch(number)
        {
            case 1: cout << “The number is one”; break;
            case 2: cout << “The number is two”; break;
            default: cout<< “The number is neither one nor two”; break;
        }
        If the value of number is 1, “The number is one” is printed.
        If the value of number is 5, “The number is neither one nor two” is printed.

Objectives:
    I. Fundamental Programming Features
        A. Declare and initialize variables and constants.
        B. Use built­in operators to create expressions and statements.
            1. Write assignment statements.
            2. Create expressions with arithmetic, relational and logical operators.
            3. Evaluate expressions using rules of operator precedence.
        C. Perform input and output.
            1. Retrieve data from the keyboard.
            2. Write data to the console window.
        D. Call built­in mathematical functions.
        E. Implement type­casting.
        F. Control program flow.
            1. Implement selection statements.
                a. Write code with if, else and else­if statements.
                b. Use switch statements.
                c. Write nested selection statements.
        G. Trap errors using selection.
    II. Procedures
        A. Define and call functions with void and non­void return values.
        B. Declare functions (prototyping).
        C. Differentiate between actual and formal parameters.
        D. Understand and analyze variable scope.
        E. Understand testing functions and use function calls (and various
        parameters) to ensure complete coverage of your code; make sure every
        possible outcome (return value or printout) is attempted and reached.
*/


