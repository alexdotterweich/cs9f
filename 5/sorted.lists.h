#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>
#include <string>

using namespace std;


template <class NODETYPE> class SortedList;
template <class NODETYPE> class SortedListIterator;
template <class NODETYPE>

class ListNode {
friend class SortedList<NODETYPE>;
friend class SortedListIterator<NODETYPE>;
public:
	ListNode (const NODETYPE &);
	NODETYPE Info ();
private:
	NODETYPE myInfo;
	ListNode* myNext;
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode (const NODETYPE &value) {
	myInfo = value;
	myNext = 0;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::Info () {
	return myInfo;
}

template <class NODETYPE>
class SortedList {
friend class SortedList<NODETYPE>;
friend class SortedListIterator<NODETYPE>;
public:
	SortedList (); // constructor
	~SortedList (); // destructor
	SortedList (const SortedList <NODETYPE> &); // copy constructor 
	void Insert (const NODETYPE &);
	bool IsEmpty ();
	SortedList<NODETYPE>& operator = (const SortedList <NODETYPE> &value);
private:
	ListNode <NODETYPE>* myFirst;
};

template <class NODETYPE>
SortedList<NODETYPE>::SortedList(){	// constructor
	myFirst = 0;
}

template <class NODETYPE>
SortedList<NODETYPE>::~SortedList(){	// destructor
	if (!IsEmpty ()) {
		std::cerr << "*** in destructor, destroying: ";
		ListNode <NODETYPE>* current = myFirst;
		ListNode <NODETYPE>* temp;
		while (current != 0) {
			std::cerr << " " << current->myInfo;
			temp = current;
			current = current->myNext;
			delete temp;
		}
		std::cerr << std::endl;
	}
}

template <class NODETYPE>
SortedList<NODETYPE>::SortedList(const SortedList <NODETYPE> & list) {	// copy constructor
	std::cerr << "*** in copy constructor" << std::endl;
	ListNode <NODETYPE>* listCurrent = list.myFirst;
	ListNode <NODETYPE>* newCurrent = 0;
	while (listCurrent != 0) {
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == 0) {
			myFirst = temp;
			newCurrent = myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;
	}
}

template <class NODETYPE>
void SortedList<NODETYPE>::Insert(const NODETYPE & value){	// Insert
	ListNode <NODETYPE> *toInsert 
	  = new ListNode <NODETYPE> (value);
	if (IsEmpty ()) {
		myFirst = toInsert;
	} else if (value < myFirst->Info ()) {
		toInsert->myNext = myFirst;
		myFirst = toInsert;
	} else {
		ListNode <NODETYPE> *temp = myFirst;
		for (temp = myFirst; 
			  temp->myNext != 0 && temp->myNext->Info () < value; 
			  temp = temp->myNext) {
		}
		toInsert->myNext = temp->myNext;
		temp->myNext = toInsert;
	}
}

template <class NODETYPE>
bool SortedList<NODETYPE>::IsEmpty (){	// IsEmpty
	return myFirst == 0;
}

// function that overloads the assignment operator ("=") for sorted lists. 
// Your function should first delete all the ListNode objects in the variable 
// being assigned to (the left hand side of the =). It should then construct 
// a copy of the list on the right hand side of the = to assign to the variable 
// on the left hand side.
template <class NODETYPE>
SortedList<NODETYPE>& SortedList<NODETYPE>::operator = (const SortedList <NODETYPE> &value) {
	// need print statements for output
	if (this == &value) {
		std::cerr << "Error! Assigning list to itself." << std::endl;
		return *this;
	} std::cout << "*** in operator=, destroying: ";

	// delete all ListNode objects
	ListNode <NODETYPE> * del = this->myFirst; // 1st thing to delete
	while (del != 0) {
		ListNode <NODETYPE> *deleteNext = del->myNext;
		std::cout << " " << del->Info(); // for print!
		delete del;
		del = deleteNext;
	} std::cout << std::endl;

	// construct a copy of the list on the right hand side  
	// of the = to assign to the variable on the left hand side
	ListNode <NODETYPE>* listCurrent = value.myFirst;
	ListNode <NODETYPE>* newCurrent = 0;
	while (listCurrent != 0) { //assign rhs to vals on lhs
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == 0) {
			myFirst = temp;
			newCurrent = myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;

	}
	return *this;
}

// SortedListIterator class that allows elements
// of a sorted list to be returned, one by one
template <class NODETYPE>
class SortedListIterator {
friend class SortedList<NODETYPE>;
friend class ListNode<int>;
public:
	SortedListIterator(); // constructor
	SortedListIterator(const SortedList <NODETYPE> &); // copy constructor
	bool MoreRemain();
	NODETYPE Next();
private:
	SortedList <NODETYPE>* mySecond;

};

template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator() { // constructor
	mySecond = new SortedList <NODETYPE>();
}

template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator(const SortedList <NODETYPE> & list) { // copy constructor
	mySecond = new SortedList <NODETYPE>();
	ListNode <NODETYPE>* listCurrent = list.myFirst;
	ListNode <NODETYPE>* newCurrent = 0;
	while (listCurrent != 0) {
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == 0) {
			mySecond->myFirst = temp;
			newCurrent = mySecond->myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;
	}

}

template <class NODETYPE>
bool SortedListIterator<NODETYPE>::MoreRemain() { // moreremain?
	return !(mySecond->IsEmpty());
}

template <class NODETYPE>
NODETYPE SortedListIterator<NODETYPE>::Next() { // next
	if (mySecond -> IsEmpty()) {
		return 0;
	} else {
		ListNode<NODETYPE> *temp = mySecond->myFirst;
		mySecond->myFirst = temp->myNext;
		return temp->Info();
	}
}




#endif