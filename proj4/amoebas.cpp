#include "amoebas.h"
#include <iostream>

using namespace std;

Amoeba::Amoeba (string s) {		// an amoeba is born, named s
	myName = s;
	myParent = 0;
	myOlderSibling = 0;
	myOldestChild = 0;
	myYoungestChild = 0;
}

// Access functions

string Amoeba::Name () {
	return myName;
}

Amoeba* Amoeba::Parent () {
	return myParent;
}

void Amoeba::AddChild (Amoeba* newChild) {
	// make child point to parent
	newChild->myParent = this;

	// check for parent having other children
	Amoeba* otherSibling = myYoungestChild;
	if (!otherSibling) {			// the new amoeba is an only child
		myYoungestChild = newChild;	// make the parent's child
		myOldestChild = newChild;	// ptrs point to the new one
		newChild->myOlderSibling = 0;	// no older sibling
	} else {				// there are other kids; make this one the youngest
		myYoungestChild = newChild;	// no younger siblings,
		newChild->myOlderSibling = otherSibling;	// but new kid now
	}		// has older siblings.
}

// prints the names of the amoeba's children, one per line
void Amoeba::PrintChildren() {
	Amoeba* child = myYoungestChild;
	int i = 0;
	if (child == 0) {
		return;
	}
	while (child != 0) {
		// if (child == 0) {
		// 	return;
		// }
		cout << child->Name() << endl;
		child = child->myOlderSibling;
	}
	return;
}

// prints the names of the amoeba's grandchildren, one per line
void Amoeba::PrintGrandchildren() {
	Amoeba* child = myYoungestChild;
	int i = 0;
	while (child != 0 ) {
		child->PrintChildren();
		child = myOlderSibling;
		
	}
}

// prints the names of all the amoeba's descendants
// child-name
//     grandchild-name
// 			great-grandchild-name
// 	    		great-great-grandchild-name
//     grandchild-name
// child-name
//     grandchild-name
// child-name
// child-name
//     grandchild-name

void Amoeba::PrintDescendants() {
	Amoeba* child = myYoungestChild;
	// cout << child->Name() << endl;
	std::string indent = "";
	int i = 0;
	while (child != 0 ) {
		child->PrintHelper(indent);
		child = child->myOlderSibling;

	}
}

void Amoeba::PrintHelper(std::string indent) {
	cout << indent << Name() << endl;
	Amoeba* child = myYoungestChild;
	while (child != 0) {
		indent = "    ";
		child->PrintHelper(indent);
		child = child ->myOlderSibling;
		// myYoungestChild = child;
	}
}








