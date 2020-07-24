#include "dll.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

PatientNetwork::PatientNetwork()
{
    head = NULL;
    tail = NULL;
}

PatientNetwork::~PatientNetwork()
{
    Patient *current = head;

    while (current)
    {
        Patient *next = current->next;
        current = next;
        delete current;
    }
}

bool PatientNetwork::isEmpty()
{
    return head == NULL && tail == NULL;
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
        // cout << "it's empty: adding  " << new_id << " (HEAD) " << endl;
        head = newPatient;
        tail = newPatient;
        return;
    }
    // Add at the tail. Always.
    // cout << "adding  " << new_id << endl;
    tail->next = newPatient;
    newPatient->prev = tail;
    tail = newPatient;
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

    for (current = head; current != NULL; current = current->next)
    {
        std::cout << current->id << "->";
    }

    std::cout << "tail" << std::endl;
}

/*
Destroy DLL from front to back and back to front. Cut time in 1/2
*/
void PatientNetwork::destroyDLL()
{
    Patient *head_tmp;
    Patient *tail_tmp;
    while (!isEmpty())
    {

        // delete from head
        head_tmp = head;
        head = head->next;
        head->prev = NULL;
        head_tmp->next = NULL;
        delete head_tmp; // deleting the content, not the pointer. No need to re-declare in loop

        // delete from tail
        tail_tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        tail_tmp->prev = NULL;
        delete tail_tmp; // deleting the content, not the pointer. No need to re-declare in loop

        if (head == tail && head->next == NULL && tail->prev == NULL)
        {
            delete head;
        }
    }
}