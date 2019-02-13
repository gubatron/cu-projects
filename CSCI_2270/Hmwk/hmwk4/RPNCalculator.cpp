//
// Created by Nicole Leon on 2/11/2019.
//
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
    Operand *op = new Operand;
    op->number = num;
    op->next = nullptr;
    op->next = stackhead;
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
    if (!isEmpty()) return stackhead->number;
    else {
        std::cout << "Stack empty, cannot peek." << std::endl;
        return nullptr;
    }
}


/*
➔Perform the arithmetic operation symbol, which will be either “+” or “*”, on the top 2
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
    int a, b, value;
    cin >> symbol;

    if (symbol == '+' || symbol == '*') {

        return value;
    }

    std::cout << "err: invalid operation" << std::endl;
    return false;

    return false;
}

