#include <iostream>
#include <math.h>
using namespace std;

/**
 * This function is called sphereSurfaceArea
 * It's single input value is radius which is given by the user
 * It does not return anything and it prints the calculated surface area
*/

void sphereSurfaceArea (float radius)
{
    float surface_area = 4 * M_PI * pow(radius,2);
    cout << "surface area: " << surface_area << endl;
}


/**
int main()
{
    cout << "Enter a radius: " << endl; 
    float radius;
    cin >> radius; 
    sphereSurfaceArea(radius);
}
*/