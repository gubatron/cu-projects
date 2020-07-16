#include "dll.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

PatientNetwork::PatientNetwork()
{
    head == NULL;
    tail == NULL;
}

bool PatientNetwork::isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    return false;
}

/* 
Simply insert every patient ID at the end of the list 
such that we can traverse the list back and forth once they're all inserted
- insert first node if list is empty
- insert at tail thereafter
*/
void PatientNetwork::insertPatientID(int new_id)
{
    Patient *newPatient = new Patient();
    newPatient->id = new_id;
    newPatient->next = NULL;
    newPatient->prev = NULL;

    // if is empty, add 1st node
    if (isEmpty())
    {
        cout << "adding: " << new_id << " (HEAD) " << endl;
        head = newPatient;
        tail = newPatient;
    }

    // if I have at least 1 node, insert after the head and reasign the tail
    if (head != NULL) {
        // if there is only one node
        if (head == tail) {
            head->next = newPatient;
            newPatient->prev = head;
            tail = newPatient;
        }
        // if there are two or more nodes, insert at the tail
        else if (tail) // CHECK
        {   
            cout << "adding: " << new_id << " (prev: " << newPatient->prev->id << ")" << endl;
            tail->next = newPatient;
            tail = newPatient;
        }
    }
}

/*
Traverse list until matching data is found
*/
Patient *PatientNetwork::searchPatientID(int id)
{
    Patient *current = head;

    while (current != NULL)
    {
        if (current->id == id)
            return current;
        current = current->next;
    }
    return 0;
}


/*
Traverse and print patient IDs
*/ 
void PatientNetwork::displayPatientIDs()
{
    Patient *current;
    std::cout << "head->";

    for (current = head; current != NULL; current = current->next) {
        std::cout << current->id << "->";
    }

    std::cout << "tail" << std::endl;
}