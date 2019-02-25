#include <utility>

//
// Created by Nicole Leon on 2/11/2019.
//
#include<iostream>
#include "ProducerConsumer.hpp"

ProducerConsumer::ProducerConsumer() {
    queueFront = -1;
    queueEnd = -1;
}

bool ProducerConsumer::isEmpty() {
    if (queueFront == -1) return true;
}

bool ProducerConsumer::isFull() {
    if (!isEmpty()) return true;

    //(queueSize() == SIZE);
}

void ProducerConsumer::enqueue(std::string player) {
    if (isFull()) {
        std::cout << "Queue full, cannot add new item" << std::endl;
    } else {
        if (queueFront == -1) {
            // first element to insert
            queueFront = 0;
            queueEnd = 0;
            queue[queueEnd] = std::move(player);
        } else {
            if (queueEnd == SIZE - 1) {
                queue[0] = player;
                queueEnd = 0;
            } else {
                queueEnd += 1;
                queue[queueEnd] = player;
            }
        }
    }
}

void ProducerConsumer::dequeue() {
    if (isEmpty()) {
        std::cout << "" << std::endl;
    } else {
        std::string result = queue[queueFront];
        if (queueFront == queueEnd) {
            // Only one element in the queue
            queueFront = -1;
            queueEnd = -1;
        } else {
            if (queueFront == SIZE - 1) {
                queueFront = 0;
            } else { queueFront += 1; }
        }
    }
}

int ProducerConsumer::queueSize() {
    if (queueFront <= queueEnd) {
        return (queueEnd - queueFront + 1);
    } else {
        return SIZE - (queueFront - queueEnd) + 1;
    }
}

std::string ProducerConsumer::peek() {
    if (isEmpty()) {
        std::cout << "Queue Empty!! cannot peek" << std::endl;
        return " ";
    } else {
        return queue[queueFront];
    }
}

