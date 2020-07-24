#pragma once
#include <iostream>
#include <string>

struct Patient
{
    int id;        // patient ID number
    Patient *next; // next patient ID
    Patient *prev; // previous patient ID
};


class PatientNetwork
{
public:
    PatientNetwork();
    ~PatientNetwork();
    bool isEmpty();
    void insertPatientID(int new_id);    // required method
    Patient *traverseNetwork();
    Patient *searchPatientID(int id);    // required method
    void displayPatientIDs();            // required method
    void destroyDLL();

private:
    Patient *head;
    Patient *tail;
};