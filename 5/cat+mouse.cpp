#include <iostream>
#include "park.h"
using namespace std;

void RunChase (Scene allAnimals) {
	for (int time=1; time<=30; time++) {
		for (int k=0; k<allAnimals.Length (); k++) {
			cout << time << endl;
			if (allAnimals[k]->Chase ()) {
				cout << "Chase over! Mouse caught at time " << time << "\n";
				return;
			}
			
		}
		

		cout << endl;
	}
	cout << "Chase took too long; all animals drifted away." 
		  << endl;
}
int main () {
	Scene allAnimals;
	// cout << "finished constructor" << endl;
	RunChase (allAnimals);
	return 0;
}