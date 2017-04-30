#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "animals.h"
// #include "park.h"
// #include "park.cpp"



// A Mouse object doesn't "chase" anything; 
// it merely moves counterclockwise around the statue, one meter per call to Chase. 
// Therefore, use the mouse's radius as the statue's radius. 
bool Mouse::Chase() {
	myPos.IncrementPosition(0.0, 1.0);
	// cout << "Mouse radius in meters " << myPos.myRadius << endl;
 //    cout << "Mouse angle in radians " << myPos.myAngleInRadians << endl;
    return false;

}

// A Cat object has a Mouse object as its target. 
// If the cat sees its target, it moves one meter toward the statue; 
// otherwise it circles 1.25 meters counterclockwise around the statue. 
bool Cat::Chase() {
	Position startingPosition = myPos;
	// sees its target
	if (myPos.Sees(myTarget->Pos())) {
		myPos.IncrementPosition(-1.0, 0.0);
		// cout << "Cat radius in meters " << myPos.myRadius << endl;
		// cout << "Cat angle in radians " << myPos.myAngleInRadians << endl;
	} else {
		myPos.IncrementPosition(0.0, 1.25);
	}
	return myTarget->Pos().IsBetween(startingPosition, myPos) && myPos.IsAtStatue();
	
}

// A Person object is trying to photograph the situation. 
// It doesn't try to capture anything. 
// If it sees its target, it doesn't move;
// otherwise it circles 2 meters clockwise around the statue.
bool Person::Chase() {
	if (myPos.Sees(myTarget->Pos())) {
		// cout << "Person radius in meters " << myPos.myRadius << endl;
  //   	cout << "Person angle in radians " << myPos.myAngleInRadians << endl;
		return false;
	} else {
		myPos.IncrementPosition(0.0, -2.0);
		return false;
	}
	
}
