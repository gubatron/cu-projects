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
    return stackHead == nullptr;
}

void RPNCalculator::push(float num) {
    auto opptr = new Operand;
    opptr->number = num;
    opptr->next = nullptr;

    if (isEmpty()){
        stackHead = opptr;
        return;
    }
    peek()->next = opptr;
    // Operand *last = peek();
    // last->next = opptr;

}

void RPNCalculator::pop() {
    if (isEmpty()){
        std::cout << "Stack empty, cannot pop an item." << std::endl;
    }

    // if it points to null
    if (stackHead->next == nullptr){
        delete stackHead;
        stackHead = nullptr;
        return;
    }
    auto stcopy = stackHead;
    while (stcopy->next != nullptr) {
        // while stops one before last
        stcopy = stcopy->next;
    }
    delete stcopy->next;
    return;
}

Operand *RPNCalculator::peek() {
    if (isEmpty()) {
        std::cout << "Stack empty, cannot peek." << std::endl;
        return nullptr;
    }
    auto stcopy = stackHead;
    //traverse
    while (stcopy->next != nullptr){
        stcopy = stcopy->next;
    }
    return stcopy;
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

    std::cin >> symbol;
    // input something other than + or *
    if (!(symbol == "+" || symbol == "*")) {
        std::cout << "err: invalid operation" << std::endl;
        return false;
    }
    // if there is nothing in the stack
    if (isEmpty()) {
        std::cout << "err: not enough operands" << std::endl;
        return false;
    }
    // if the stack is not empty
    peek();
    Operand *a = peek();
    pop();
    if (isEmpty()){
        std::cout << "err: not enough operands" << std::endl;
        push(a->number);
        return false;
    }
    Operand *b = peek();
    pop();
    if (symbol == "+"){
        push(a->number + b->number);
    }
    else if (symbol == "*"){
        push(a->number * b->number);
    }
    return true;
}

