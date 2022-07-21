#pragma once

#include <vector>

#include "Pieces/PieceFactory.h"

#define ROW 8
#define COLUMN 8

class chess_board
{
private:
	std::vector<std::vector<Piece*>> board;

	void empty_board();
	void fill_board(const bool& is_white);
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
	bool is_playable(const std::string& pos, const bool& is_turn_white);
};