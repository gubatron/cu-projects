#include<iostream>
#include<string>
#include "List.hpp"

List::List() {
  m_size = 0;
  m_list = 0;
  m_capacity = 0;
  m_resize = 0;
}

List::~List() {
  if (m_size > 1)  delete[] m_list;
  if (m_size == 1)  delete m_list;
}

void List::resize() {
  m_resize = m_resize + 1;
  std::cout << "Resizing " << m_resize << " times and no of elements: " << m_size << std::endl;
  

  if (m_capacity == 0) {
    m_list = new std::string [1];
    m_capacity = 1;     
  }
  else {
    std::string *n_list = new std::string [m_capacity*2];
    
    for (int i=0; i< m_capacity; i++) {
      n_list[i] = m_list[i];
    }
    delete[] m_list;
    
    m_list = n_list;
    m_capacity = m_capacity * 2;
  }
}

void List::insert(std::string data) {
  if (m_size == m_capacity) resize();

  m_list[m_size] = data;
  m_size = m_size + 1;
  
}

void List::insert(std::string data, int index) {

  if ((index < 0) ||  (index > m_size))  throw "Index out of bounds";

  if (m_size == m_capacity) resize();
  
  for (int i = m_size; i > index; i--) {
    m_list[i] = m_list[i-1];
  }
  m_list[index] = data;
  m_size = m_size + 1;
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

bool List::isEmpty() {
  return (m_size == 0);
}

void List::print() {
  std::cout << "[ ";
  for (int i = 0; i < m_size-1; i++) {
    std::cout << m_list[i] << ", ";
  }
  std::cout <<  m_list[m_size-1] <<"]" << std::endl;
}

