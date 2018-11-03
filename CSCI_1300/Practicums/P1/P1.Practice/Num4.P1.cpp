#include <iostream>
using namespace std;


/**
 * PaintHouse function calculates the cost to paint a house.
 *      1. total cost of painting house = cost of painting wall + cost of painting
 *  windows and doors
 *      2. Cost to paint windowns and doors = $6.75
 *      3. Cost to paint walls is perimeter of house = 2 * (width + depth)
 *      4. painting cost for first 100 feet or perimeter = $8 per foot
 *      5. painting cost for next 100 feet of perimeter = $10 per foot
 *      6. painting cost for >200 feet = $15 per foot
 *      7. Invalid paramters return -1;
 * Input parameters: width (int); depth (int); win_door (int)
 * Output: nothing
 * Returns: cost (float)   // not void function
*/

float PaintHouse (int w, int d, int WinDoor)
{
    int p = 2 * (w + d);
    if (p < 0 || WinDoor < 0 || w < 0 || d < 0)
    {
        return -1;
    }
    else if (p <= 100)
    {
        p = 8 * p;
    }
    else if (p <= 200)
    {
        p = -200 + (10 * p);
    }
    else
    {
        p = -1200 + (15 * p);
    }
    
    float WallCost = p;
    float WinDoorCost = WinDoor * 6.75;
    // cost to paint the whole house
    float HouseCost = WallCost + WinDoorCost;
    
    return HouseCost;

}

int main() {
    cout << PaintHouse(100,12,0)<<endl;
    cout << PaintHouse(28,48,12)<<endl;
}