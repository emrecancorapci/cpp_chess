#pragma once
#include <vector>
#include "Piece.h"

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

class chess_board
{
	PIECES_MATRIX board;

	static void empty_board(PIECES_MATRIX& chessBoard);
	static void fill_board(PIECES_MATRIX& chessBoard, const bool& color);
public:
	chess_board();

	void new_board();
	void clear_states();

	Piece* get_piece_ptr(const int& row, const int& column);
	Piece get_piece(const int& row, const int& column) const;
	void put_piece(Piece piece, const int& row, const int& column);
	void clear_pos(const int& row, const int& column);


	PIECES_MATRIX* get_board();
};
