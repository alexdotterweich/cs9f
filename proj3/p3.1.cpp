#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "inventory.h"
using namespace std;

//   update word number
//   list names
//   list quantities
//   batch file-name
//   quit

// define these functions
 void InterpretCommands (istream& cmds, Inventory& i);

// echo the command and its arguments
void InterpretUpdate (istream& is, Inventory& i){
  string word; int number;
  is >> word >> number;
  // bool correctCmd = (word == "word") && (number == "number");
  if (is.fail() || !is.eof()) {
    cerr << "Please enter words and numbers to be interpreted." << endl;
  }
  cout << "update " << word << " " << number << endl;
  i.Update(word, number);
}

// echo the command and its arguments
void InterpretList (istream& is, Inventory& i){
  string namesOrQuantities;
  is >> namesOrQuantities;
  bool correctCmd = (namesOrQuantities == "names") || (namesOrQuantities == "quantities");
  if (is.fail() || !is.eof() || !(correctCmd)) {
    cerr << "Please enter names or quantites to be interpreted." << endl;
  }
  cout << "list " << namesOrQuantities << endl;
  if (namesOrQuantities == "names") {
    cout << "calling list by name"<< endl;
    i.ListByName();
    return;
  }
  else {
    cout << "calling list by q"<< endl;
    i.ListByQuantity();
    return;
  }
}

// read, recognize, and process commands from the specified file
// then (assuming that a quit command has not been read) resume reading commands from cin
// Assume that the file does not contain any batch commands
void InterpretBatch (istream& is, Inventory& i){
  string fileName;
  // is >> fileName;
  // inFile.open(fileName + "txt");
  if (!(is >> fileName)) {
    cerr << "Please enter file name to be interpreted." << endl;
  }
  cout << "batch " << fileName << endl;
  // ??
  fstream stuffInFile (fileName, ios::in);
  InterpretCommands(stuffInFile, i);
}

// terminate the program using the one-argument exit function declared in <cstdlib>
void InterpretQuit (istream& is){
  cout << "quit" << endl;
  exit(0);
}

void InterpretCommands (istream& cmds, Inventory& i) {

  string line, cmdWord;
  while (getline(cmds, line)) {
    istringstream lineIn (line.c_str());
    // lineIn >> cmdWord;
    if (!(lineIn >> cmdWord)){
      cerr << "No words inputted! Try again." << "\n";
    } else if (cmdWord=="update") {
      InterpretUpdate (lineIn, i);
    } else if (cmdWord=="list") {
      InterpretList (lineIn, i);
    } else if (cmdWord=="batch") {
      InterpretBatch (lineIn, i);
    } else if (cmdWord=="quit") {
      InterpretQuit (lineIn);
    } else {
      cerr << "Unrecognizable command word." << endl;
    }
  }
}

int main ( ) {
  Inventory i;
  InterpretCommands (cin, i);
  return 0;
}