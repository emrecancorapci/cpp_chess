#pragma once
#include <vector>

#define WHITE false
#define BLACK true

#define ROW 8
#define COLUMN 8

#define EMPTY 0
#define PAWN 1
#define ROCK 2
#define KNIGHT 3
#define BISHOP 4
#define QUEEN 5
#define KING 6

#define NORMAL 0
#define SELECTED 1
#define TARGET 2

#define PIECES_MATRIX std::vector<std::vector<Piece>>

struct Piece
{
	int type;
	bool color;
	int state;

	void clear()
	{
	type = EMPTY;
	color = NULL;
	state = NORMAL;
	}
};



class chess_board
{
	PIECES_MATRIX board;
public:
	chess_board();
	void new_board();
	void clear_states();
	PIECES_MATRIX* get_board();
	Piece* get_piece(const int& row, const int& column);
};
