#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
using namespace std;


// a constructor, which initializes all the cells to a period
Board::Board(){
	// vector<int>::iterator it;
	board = vector<vector<char> > (19, vector<char> (19, '.'));
	// for(it = board.begin(); it != board.end(); it++){

	// 	it->fill('.');
	// }
}

// stores the given character argument at board position [row][col],
// computed from the given player's perspective
void Board::SetCell(int player, int row, int col, char c) {
	if(player == 0) {
		board[row][col] = c;
	} else {
		board[19 - row - 1][19 - col - 1] = c;
	}
}

// prints the board from the given player's perspective
void Board::Print(int player) {
	for(int x = 0; x < 19; x++) {
		for(int y = 0; y < 19; y++) {
			if(player == 0) {
				cout << board[x][y] << " ";
				// if((x+1)%19  == 0) {
				// 	cout << "\n";
				// } 
			} else {
				cout << board[19 - x - 1][19 - y - 1] << " ";
			}
		} cout << endl;
	}
}

int main() {
	Board b = Board();
	while(!cin.eof()) {
		string cmdWord; int player, row, col; char c; 
		string line;
		getline(cin, line);
		istringstream lineIn (line.c_str());
		if (!(lineIn >> cmdWord)){
	      cerr << "No input! Try again." << "\n";
		} else if (cmdWord=="set") {
			lineIn >> player >> row >> col >> c;
			b.SetCell(player, row, col, c);
		} else if (cmdWord=="print") {
			lineIn >> player;
			b.Print(player);
		} else if (cmdWord=="quit") {
			exit(0);
		} else {
      		cerr << "Unrecognizable command word." << endl;
    	}
    }
	return 0;
}