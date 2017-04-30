#include <iostream>
#include "inventory.h"
#include <vector>
#include <string>

using namespace std;



// a constructor, which creates an empty inventory
Inventory::Inventory() { 
	cout << "Creating empty inventory" << endl;
}


// adds amount to the quantity of the named item in the inventory
// or inserts the item into the inventory with the given quantity
// if it's not already in stock
// Quantities in the inventory are allowed to be negative
void Inventory::Update(string item, int amount) {
  //if inventory contains item
  for(int i = 0; i < invent.size(); i++){
    if (invent[i].itemName == item) {
      invent[i].quantity += amount;
      return;
    } 
  }
  Inv newItem = Inv();
  newItem.quantity = amount;
  newItem.itemName = item; 
  invent.push_back(newItem);
}



bool compareItemByName(Inv obj1, Inv obj2) {
  if (obj1.itemName < obj2.itemName){
    return true;
  } else {
    return false;
  }
}

bool compareItemByQuantity(Inv obj1, Inv obj2) {
  if (obj1.quantity < obj2.quantity){
    return true;
  } else {
    return false;
  }
}
// prints inventory entries—name plus quantity—sorted alphabetically by name
void Inventory::ListByName() {
  vector<Inv> wordListVector;
  for(int i = 0; i < invent.size(); i++) {
    wordListVector.push_back(invent[i]);

  }
  sort(wordListVector.begin(), wordListVector.end(), compareItemByName);
  for(int i = 0; i < wordListVector.size(); i++){
    cout <<  wordListVector[i].itemName << " " << wordListVector[i].quantity << endl;
    // cout << wordListVector[i].quantity << " " << 
  }
}

// prints inventory entries—name plus quantity—sorted in increasing order by quantity
void Inventory::ListByQuantity() {
  vector<Inv> quantListVector;
  for(int i = 0; i < invent.size(); i++) {
    quantListVector.push_back(invent[i]);
  }
  sort(quantListVector.begin(), quantListVector.end(), compareItemByQuantity);
  for(int i = 0; i < quantListVector.size(); i++){
    cout <<  quantListVector[i].itemName <<  " " << quantListVector[i].quantity << endl;
  }
}

// int main() {
//   return 0; 
// }
