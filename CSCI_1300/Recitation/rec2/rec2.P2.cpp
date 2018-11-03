#include <iostream>
#include <math.h>
using namespace std;

/**
 * The function calculates the volume of a sphere with a given radius
 * The radius is defined as a float 
 * In the function the volume is calculated with the correct formula
*/ 

void sphereVolume (float radius)
{
    float volume = (4.0/3.0) * M_PI * pow(radius,3);
    cout << "volume: " << volume << endl;
}

// Call the function sphereVolume 

/**
int main()
{
    cout << "Enter a radius: " << endl; 
    float radius;
    cin >> radius; 
    sphereVolume(radius);
}
*/