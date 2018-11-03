#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void fillArray(int score[], int size);
void copyArray(int score[], int newArray[],int size );
void printArray(int newArray[], int size );
int calcProduct(int score[], int size );
int calcSum(int score[], int size );
int findMax(int score[], int size );
int findMaxIndex(int score[], int size );
int main()
{
    const int NUM_SCORES = 5;
    int score[NUM_SCORES];
    // 1. Fill the buckets
    fillArray(score, NUM_SCORES);
    
    // 2. Copying to another array
    int newArray[NUM_SCORES];
    copyArray(score, newArray, NUM_SCORES );
    
    // 3. Now let's see if we copied correctly. Print newArray
    printArray(newArray, NUM_SCORES );
    
    // 4. The product of all scores
    cout << "Total product: " << calcProduct(score, NUM_SCORES )<< endl;

    // 5. Find average
    cout << "Average: " << double(calcSum(score, NUM_SCORES )) / NUM_SCORES << endl;
    
    // 6. Find max score
    cout << "largest value: " << findMax(score, NUM_SCORES )<< endl;
    
    // 7. Find the position of the highest score
    cout << "The position of the highest score is : " << findMaxIndex(score, NUM_SCORES ) << endl;
    
    return 0;
}
void fillArray(int score[], int size)
{
    cout << "Enter 5 scores: \n";
    cin >> score[0];
    cin >> score[1];
    cin >> score[2];
    cin >> score[3];
    cin >> score[4];
}
void copyArray(int score[], int newArray[],int size )
{
    for (int i = 0; i < size; i++)
    {
        newArray[i] = score[i];
    }
}
void printArray(int newArray[], int size )
{
    for (int i = 0; i < size; i++)
    {
        cout << newArray[i] << endl;
    }    
}
int calcProduct(int score[], int size )
{
    int total = 1;
    for (int i = 0; i < size; i++)
    {
        total = total * score[i];
        //cout << total << endl;
    }
    return total;
}
int calcSum(int score[], int size )
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total = total + score[i];
        //cout << total << endl;
    }
    return total;
}
int findMax(int score[], int size )
{
    int max = score[0];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (score[i] >= max)
        {
            max = score[i];
            index = i;
        }
    }
    return max;
}
int findMaxIndex(int score[], int size )
{
        int max = score[0];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (score[i] >= max)
        {
            max = score[i];
            index = i;
        }
    }
    return index;
}