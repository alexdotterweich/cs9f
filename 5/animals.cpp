#include <iostream>

#include "animals.h"

// #include "park.h"
// #include "park.cpp"


Mouse::Mouse(string s, Position coords): Animal(s, coords) {}

// A Mouse object doesn't "chase" anything; 
// it merely moves counterclockwise around the statue, one meter per call to Chase. 
// Therefore, use the mouse's radius as the statue's radius. 
bool Mouse::Chase() {
	// cout << "in mouse chase" << endl;
	myPos.IncrementPosition(0.0, 1.0);
	// cout << "Mouse radius in meters " << myPos.myRadius << endl;
 //    cout << "Mouse angle in radians " << myPos.myAngleInRadians << endl;
	cout << "mouse coord" << endl;
	myPos.Print();

    return false;

}


Cat::Cat(string s, Position coords): Animal(s, coords) {}
// A Cat object has a Mouse object as its target. 
// If the cat sees its target, it moves one meter toward the statue; 
// otherwise it circles 1.25 meters counterclockwise around the statue. 
bool Cat::Chase() {
	Position startingPosition = myPos;

	// cout << "in cat chase" << endl;
	// sees its target
	if (myPos.Sees(myTarget->Pos())) {
		myPos.IncrementPosition(-1.0, 0.0);
		// cout << "Cat radius in meters " << myPos.myRadius << endl;
		// cout << "Cat angle in radians " << myPos.myAngleInRadians << endl;
		cout << "cat coords" << endl;
		myPos.Print();
	} else {
		myPos.IncrementPosition(0.0, 1.25);
		cout << "cat coords" << endl;
		myPos.Print();

	}
	return myTarget->Pos().IsBetween(startingPosition, myPos) && myPos.IsAtStatue();
	
}

Person::Person(string s, Position coords): Animal(s, coords) {}
// A Person object is trying to photograph the situation. 
// It doesn't try to capture anything. 
// If it sees its target, it doesn't move;
// otherwise it circles 2 meters clockwise around the statue.
bool Person::Chase() {

	// cout << "in person chase" << endl;
	if (myPos.Sees(myTarget->Pos())) {
		// cout << "see target";
		// cout << "Person radius in meters " << myPos.myRadius << endl;
		cout << "Person sees target!" << endl;
		cout << "person coords" << endl;
		myPos.Print();
  //   	cout << "Person angle in radians " << myPos.myAngleInRadians << endl;
		return false;
	} else {
		// cout << "doesnt see target" << endl;
		myPos.IncrementPosition(0.0, -2.0);
		cout << "person coords" << endl;
		myPos.Print();
		return false;
	}
	
}
