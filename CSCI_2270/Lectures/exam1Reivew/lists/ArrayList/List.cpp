#include<iostream>
#include<string>
#include "List.hpp"

List::List() {
  m_size = 0;
  m_capacity = 1000;
}

List::~List() {
}

void List::insert(std::string data) {
  if (m_size < m_capacity) {
    m_list[m_size] = data;
    m_size = m_size + 1;
  }
  else {
    throw "List capacity reached";
  }
}

void List::insert(std::string data, int index) {
  if ((index < 0) ||  (index > m_size))  throw "Index out of bounds";
  if (m_size < m_capacity) {
    for (int i = m_size; i > index; i--) {
      m_list[i] = m_list[i-1];
    }
    m_list[index] = data;
    m_size = m_size + 1;
  }
  else {
    throw "List capacity reached";
  }
}

void List::remove(int index) {
  if ((index < 0) ||  (index > m_size))  throw "Index out of bounds";
  for (int i = index; i < m_size - 1; i++) {
    m_list[i] = m_list[i+1];
  }
  m_list[m_size-1] = "";
  m_size = m_size - 1;
}

int List::search(std::string data) {
  for (int i = 0; i < m_size; i++) {
    if (m_list[i] == data) return i;
  }
  return INVALID_INDEX;
}


int List::getSize() {
  return m_size;
}

int List::getCapacity() {
  return m_capacity;
}

bool List::isEmpty() {
  return (m_size == 0);
}

bool List::isFull() {
  return (m_size == m_capacity);
}

void List::print() {
  std::cout << "[ ";
  for (int i = 0; i < m_size-1; i++) {
    std::cout << m_list[i] << ", ";
  }
  std::cout <<  m_list[m_size-1] <<"]" << std::endl;
}

