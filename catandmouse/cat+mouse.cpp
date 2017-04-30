#include <iostream>
#include <cmath>
using namespace std;

#include "positions.h"

// You define the GetPositions function.
// It should read legal cat and mouse positions from the user
// and return the position values in its two arguments.
void GetPositions (Position& cat, Position& mouse) {
	float catAngle; float catRadius; float mouseAngle;
	cout << "Enter the cat's radius: " << "\n";
	cin >> catRadius;

	cout << "Enter the cat's angle: " << "\n";
	cin >> catAngle;

	cout << "Enter the mouse's angle: " << "\n";
	cin >> mouseAngle;
	cat.SetAbsolutePosition(catRadius, (catAngle*3.14159)/180);
	mouse.SetAbsolutePosition(1, (mouseAngle*3.14159)/180);
}

// You define the RunChase function.
// Given initialized cat and mouse positions,
// it should simulate the cat chasing the mouse, printing the 
// result of each movement of cat and mouse.  Either the cat will 
// catch the mouse, or 30 time units will go by and the cat will 
// give up.
void RunChase (Position cat, Position mouse ) {
	float minsPassed = 1; Position oldCatPos;
	cout << "Postions at Minute " << minsPassed << "\n";
	cout << "\n";
	for(int i = 1; i < 30; i++) {
		oldCatPos = cat;
		if(cat.Sees(mouse)) {
			cat.IncrementPosition(-1.0, 0.0);
			cout << "Cat postion: \n";
			cat.Print();

		}
		else {
			cat.IncrementPosition(0.0, 1.25);
			cout << "Cat postion: \n";
			cat.Print();
		}

		if (mouse.IsBetween(oldCatPos, cat) && cat.IsAtStatue()) {
			cout << "Chase over! Mouse caught at time " << minsPassed << "\n";
			return; 
		}

		mouse.IncrementPosition(0.0, 1.0);
		cout << "\n";
		cout << "Mouse postion: \n";
		mouse.Print();
		cout << "\n";

		//increment mins
		minsPassed += 1; 
		cout << "Postions at Minute " << minsPassed << "\n";
		cout << "\n";
	}

	cout << "Cat gave up! 30 mins have passed \n";
	return;
}

int main () {
	Position cat, mouse;
	GetPositions (cat, mouse);
	RunChase (cat, mouse);
	return 0;
}
