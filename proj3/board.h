// #ifndef BOARD_H
// #define BOARD_H
#include <vector>
#include <string>
using namespace std;

class Board {
public:
	Board();
	void SetCell(int player, int row, int col, char c);
	void Print (int player);
private:
	vector<vector<char> > board;

};

// #endif; 
