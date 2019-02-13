//
// Created by Nicole Leon on 2/11/2019.
//
#include <iostream>
#include "RPNCalculator.hpp"

RPNCalculator::RPNCalculator() {
    stackHead = nullptr;
}

RPNCalculator::~RPNCalculator() {
    while (!isEmpty()) {
        pop();
    }
}

bool RPNCalculator::isEmpty() {
    return (stackHead == nullptr);
}

void RPNCalculator::push(float num) {
    auto *op = new Operand;
    op->number = num;
    op->next = nullptr;
    op->next = stackHead;
    stackHead = op;
}

void RPNCalculator::pop() {
    if (!isEmpty()) {
        Operand *temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    } else {
        std::cout << "Stack empty, cannot pop an item." << std::endl;
    }
}

Operand *RPNCalculator::peek() {
    if (!isEmpty()) return stackHead;
    else {
        std::cout << "Stack empty, cannot peek." << std::endl;
        return nullptr;
    }
}


/*
Perform the arithmetic operation symbol, which will be either “+” or “*”, on the top 2
numbers in the stack. The return value indicates whether the operation was carried out
successfully
➔ If symbol is not “+” or “*”, print "err: invalid operation" and return false
➔ Store the floats from the top two elements in the stack in local variables and pop them.
    ◆ Before getting each element, make sure that the stack is not empty. If it is empty,
    print “err: not enough operands” and return false
    ◆ If you pop the first element, and notice that the list is empty prior to getting the
    next element, print the error message, push the first element back to the stack,
    and return false
➔ Perform the arithmetic operation symbol on those two elements and push the result to
the stack*/
bool RPNCalculator::compute(std::string symbol) {
    // Store the floats from the top two elements in the stack in local variables and pop them.
    // TODO How do you store the float?

    Operand *a = stackHead = nullptr; // todo ??
    Operand *b = a - 1; // to do how do I create these properly to assign them to float number
                                // and point them to the the last two elements of the stack? I only have stackhead.
                                // do a = stackHead = nullptr and b = a - 1???
    Operand *value = nullptr;

    std::cin >> symbol;

    if (symbol == "+" || symbol == "*") {
        if (isEmpty()) {
            std::cout << "err: not enough operands" << std::endl;
            return false;
        }
         //stack is not empty
         // pop last value and assign to a
             //if (isEmpty()) {
             //    std::cout << "err: not enough operands" << std::endl;
             //    return false;
             //}
             // if not empty, pop next value and assign to b
             // do a <symbol> b and return value
                // todo How? -- value = a (symbol) b;

        return value; // pop this into the stack
    }
    // input something other than + or *
    std::cout << "err: invalid operation" << std::endl;
    return false;
}

