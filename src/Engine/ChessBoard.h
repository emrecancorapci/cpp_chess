#pragma once

#include <vector>

#include "Pieces/Piece.h"
#include "Pieces/Pawn.h"
#include "Pieces/Rock.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"

#define ROW 8
#define COLUMN 8

class chess_board
{
private:
	std::vector<std::vector<Piece*>> board;

	void empty_board();
	void fill_board(const piece_color& color);
public:
	chess_board();

	void new_board();

	bool update(const std::string& from, const std::string& target);
	bool check_move(const std::string& home, const std::string& target);
	void draw() const;

	Piece* get_piece(const std::string& position) const;
	Piece* get_piece(const int& x, const int& y) const;
	Piece* get_piece(const vector2& vector) const;

	void put_piece(const std::string& home, const std::string& target);
	void clear_pos(const std::string& pos);


	std::vector<std::vector<Piece*>>* get_board();
	bool is_playable(const std::string& pos, const piece_color& turn);
};