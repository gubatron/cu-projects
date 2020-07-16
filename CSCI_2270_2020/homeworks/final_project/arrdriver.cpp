#include "dll.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <ctime> // for clock()
// Learned how to use clock() with:
// http://www.cplusplus.com/reference/ctime/clock/

#include <cstdlib> // for rand() to generate pseudo-random values in search[100]
// http://www.cplusplus.com/reference/cstdlib/rand/

using namespace std;

// Command Line Example: ./medTracker dll.cpp dlldriver.cpp dataSetA.csv
main(int argc, char *argv[])
{
    int testData[10000];
    float insert[100];
    float search[100];

    // char *dataSetFileName = argv[1];
    ifstream dataSetFile("dataSetA.csv");
    // ifstream dataSetFile("dataSetB.csv");
    string tempID;

    ofstream dataResultsInsertFile("array_insert_avg.csv");
    ofstream dataResultsSearchFile("array_search_avg.csv");

    int num_read_items = 0;
    int num_searched_items = 0;
    int insert_index = 0;
    int search_index = 0;

    auto time = clock();
    float duration;

    // read file and insert into testData[]
    while (!dataSetFile.eof() && getline(dataSetFile, tempID, ','))
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // INSERT
        // How long does it take to insert 100 elements into testData[]?
        // Divide the total time by 100 to get the average insert time
        // Put average in insert[i]
        // Do this 100 times, for every set of 100 elements (total of 10000 elements)
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if (num_read_items == 0)
        {
            time; // start the clock
        }

        testData[num_read_items] = stoi(tempID); // populate testData[1000] 100 numbers at a time

        // print to make sure I'm putting the right values inside of testData[].
        // cout << "index: " << num_read_items << "\t tempID: " << tempID << " == " << testData[num_read_items] << endl; // YES!

        // WHEN WE GET THE 100TH ITEM
        // 1. We take another time measurement (stop) and we calculate duration
        // 2. Calculate the average time for each insertion
        // 3. Reset the item counter
        if (num_read_items == 99)
        {
            time = clock() - time;                   // stop the clock
            duration = time / (float)CLOCKS_PER_SEC; // calculate how long it took to run the function.

            float avg = duration / 100; // average insert time
            insert[insert_index] = avg; // put the average in insert[]

            // cout << "At INSERT array index 100 * [ " << insert_index << " ] the function took [ " << duration << " ] seconds to INSERT \t";
            // cout << "The AVERAGE INSERT TIME at INSERT index 100 * [ " << insert_index << " ] is [ " << insert[insert_index] << " ] seconds" << endl;

            // TODO: PRINT AVERAGES INTO 'array_insert_avg.csv' FILE
            dataResultsInsertFile << insert[insert_index] << ",";

            insert_index++;      // go to the next index in my insert array for next time
            num_read_items = -1; // reset item counter so we can start the clock again
        }
        num_read_items++; // brings it back to 0 to continue reading (be able to enter the if statement above)

    } // while() insert

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // SEARCH
    // How long does it take to search through testData[10000] 100 elements at a time?
    // generate random values in interval of [0,99] to populate search[]
    // use these values as indices for testData[1000]
    // search testData[] 100 elements at a time and see how long this takes
    // Divide the total time by 100 to get the average.
    // Put average in search[i]
    // Do this 100 times, for every set of 100 elements (total of 10000 elements)
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // testData[] by now is populated
    // Let's populate search[] with random values to ensure that a value we search for is already present at an index
    for (int i = 0; i < 100; i++)
    {
        i = rand();
        search[i];
    }
    bool flag = false;
    bool found = false; // for search loop
    while (flag = false) // while not at the end of search[]
    {
        if (num_searched_items == 0)
        {
            time; // start the clock
        }
        // TODO: search through testData[] 100 items at a time
        for (int i = 0; i < search[100]; i++)
        {
            if (testData[i] == search[i])
            {
                found = true; // it matches / found
                cout << "testData at [ " << i << " ] is [ " << testData[i] << " ] which SHOULD equal to search[i] [ " << search[i] << endl;
            }
            else cout << "testData[ "<< testData[i] <<" ] != search[ "<< search[i] <<" ]" << endl;
        }

        if (num_searched_items == 99)
        {
            time = clock() - time;                   // stop the clock
            duration = time / (float)CLOCKS_PER_SEC; // calculate how long it took to run the function.

            float avg = duration / 100; // average insert time
            search[search_index] = avg; // put the average in insert[]

            // cout << "At SEARCH array index 100 * [ " << search_index << " ] the function took [ " << duration << " ] seconds to SEARCH \t";
            // cout << "The AVERAGE SERACH TIME at SEARCH index 100 * [ " << search_index << " ] is [ " << search[search_index] << " ] seconds" << endl;
            // cout << "----------------------------               o                --------------------------" << endl << endl;

            // TODO: PRINT AVERAGES INTO 'array_insert_avg.csv' FILE

            search_index++;          // go to the next index in my search array for next time
            num_searched_items = -1; // reset item counter so we can start the clock again
        }
        num_searched_items++;
        if (search_index == 100) flag = true;
    } // while() search
}