#pragma once

#include <vector>

#include "Piece.h"

#define ROW 8
#define COLUMN 8

#define PIECES_MATRIX std::vector<std::vector<Piece>>

class chess_board
{
	PIECES_MATRIX board;

	void empty_board();
	void fill_board(const piece_color& color);
public:
	chess_board();

	void new_board();

	bool update(const std::string& from, const std::string& to);
	void draw() const;

	Piece* get_piece_ptr(const std::string& position);
	Piece get_piece(const std::string& pos) const;
	void put_piece(Piece piece, const std::string& pos);
	void clear_pos(const std::string& pos);


	PIECES_MATRIX* get_board();
	bool is_playable(const std::string& pos, const piece_color& turn);
};

struct vector2
{
	int x,y;
};

vector2 convert_vector2(const std::string& pos);