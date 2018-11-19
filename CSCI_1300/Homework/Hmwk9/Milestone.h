#include "Common.h"

#ifndef MILESTONE_H
#define MILESTONE_H

// where methods and member variables are defined
class Milestone {
public:
  // Constructor
  Milestone(string milestoneName,
	    int distance,
	    bool isItAFort,
	    int minDays,
	    float costPerDay) : name(milestoneName),
                                distanceFromOrigin(distance),
                                is_fort(isItAFort),
                                minimumDaysRequired(minDays),
                              	costPerDayInAUD(costPerDay) {
  }
 
  // Methods
  string getName();
  int getDistanceFromOrigin();
  bool isFort();
  bool isAttraction();
  bool canLeaveTheSameDay();
  int getMiniumDaysRequired(); // can be zero

// private to the class
private:
  string name;
  int distanceFromOrigin; // in km
  bool is_fort; // if not, it's an attraction.
  int minimumDaysRequired;
  float costPerDayInAUD; // extra cost to the whole party
}; 

#endif

// At attractions, the money paid is just a toll/fee
// 
