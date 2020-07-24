#include "dll.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <chrono>

using namespace std;

int randomTo(int n) {
    if (n < 0) {
        n = 0;
    }
    return rand() % n + 1;
}

void drive(ifstream &dataSetFile, ofstream &dataResultsInsertFile, ofstream &dataResultsSearchFile) {
    PatientNetwork patientNet;
    unsigned int testData[10000]; // we'll first read all the data from the csv and put it in memory, to not interrupt operations with disk I/O later
    int insertData[100]; // we'll measure 100 times, how long it takes to copy 100 elements here.
    float insert_avg_times[100];
    float search_avg_times[100];
    int total_inserted_items = 0;
    int num_read_items = 0;
    int insert_index = 0;
    int num_searched_items = 0;

    int i = 0;
    unsigned int tempID;
    while (dataSetFile >> tempID) {
        testData[i++] = tempID;
        if (dataSetFile.peek() == ',') {
            dataSetFile.ignore();
        }
        cout << "read testData[i=" << (i - 1) << "] = " << testData[i - 1] << endl;
    }

    auto start = chrono::steady_clock::now();
    auto start_search = chrono::steady_clock::now();

    i = 0;
    while (i < 10000) {
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // INSERT
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if (num_read_items == 0) {
            start = chrono::steady_clock::now();
            //  cout << "start = " << start << endl;
        }

        // INSERT IN DLL
        patientNet.insertPatientID(testData[i]);
        total_inserted_items++;

        if (num_read_items == 99) {
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::nanoseconds>(
                    end - start).count(); // calculate how long it took to run the function.
            // cout << "end = " << end << endl;
            // cout << "duration =" << duration << endl << endl;

            float avg = duration / 100.0;         // average insert time
            insert_avg_times[insert_index] = avg; // put the average in insert[]

            //cout << "insert [ " << insert_index << " ] Duration [ " << duration << " ] Avg [" << avg << "]" << endl;

            insert_index++;      // go to the next index in my insert array for next time
            num_read_items = -1; // reset item counter so we can start the clock again

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // SEARCH
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            // We've inserted +100 elements, now we perform total_inserted_items searches on the total set so far.
            int search_index = 0;
            while (search_index < 100) {
                if (num_searched_items == 0) {
                    start_search = chrono::steady_clock::now();
                }
                // generate a random number that will fall within the 10k indices of testData[10000]
                int random_search_index = randomTo(total_inserted_items - 1);
                int random_data_value = testData[random_search_index];

                // DLL SEARCH
                patientNet.searchPatientID(random_data_value);

                if (num_searched_items == total_inserted_items - 1) {
                    auto end_search = chrono::steady_clock::now();
                    auto duration = chrono::duration_cast<chrono::nanoseconds>(
                            end_search - start_search).count(); // calculate how long it took to run the function.

                    float avg = duration / 100.0;
                    search_avg_times[search_index] = avg;

                    //cout << "search [ " << search_index << " ] Duration [ " << duration << " ] Avg [" << avg << "]" << endl;

                    num_searched_items = -1;
                    search_index++;
                }
                num_searched_items++;
            }
        }
        num_read_items++; // brings it back to 0 to continue reading (be able to enter the if statement above)
        if (i % 250 == 0) {
            float completed_percentage = (i / 10000.0) * 100.0;
            cout << completed_percentage << "%" << endl;
        }
        i++;
    }
    cout << "100%" << endl;
    cout << endl;
    // Now write averages insert times to file
    for (auto average : insert_avg_times) {
        dataResultsInsertFile << average << endl;
    }
    dataResultsInsertFile.close();

    // Now write averages search times to file
    for (auto average : search_avg_times) {
        dataResultsSearchFile << average << endl;
    }
    dataResultsSearchFile.close();
}

// Command Line Example: ./medTracker dll.cpp dlldriver.cpp dataSetA.csv
int main(int argc, char *argv[]) {
    ifstream dataSetFileA;
    ofstream dataResultsInsertFileA("dll_insert_avg_a.csv");
    ofstream dataResultsSearchFileA("dll_search_avg_a.csv");

    ifstream dataSetFileB("dataSetB.csv");
    ofstream dataResultsInsertFileB("dll_insert_avg_b.csv");
    ofstream dataResultsSearchFileB("dll_search_avg_b.csv");

    cout << "Processing dataset A..." << endl;
    // read file and insert into testData[]
    int i = 0;
    int testData[10000];
    unsigned int tempID;
    dataSetFileA.open("dataSetA.csv");
    if (!dataSetFileA.is_open()) {
        cout << "could not open dataSetA.csv" << endl;
        return 1;
    }
    drive(dataSetFileA, dataResultsInsertFileA, dataResultsSearchFileA);
    cout << "Processing dataset B..." << endl;
    drive(dataSetFileB, dataResultsInsertFileB, dataResultsSearchFileB);
    cout << endl << "doubly_linked_list.exe finished." << endl;
    return 0;
}
