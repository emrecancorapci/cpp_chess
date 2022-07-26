#pragma once

#include <vector>
#include <iostream>

#include "IBoard.h"
#include "PieceFactory.h"

#define ROW 8
#define COLUMN 8

class ChessBoard final : public IBoard
{
private:
	std::vector<std::vector<Piece*>> board;

	std::vector<std::vector<Piece*>>* get_board();

	bool is_white_turn = true;

	Piece* get_piece(const std::string& position) const;
	Piece* get_piece(const int& x, const int& y) const;
	Piece* get_piece(const vector2& vector) const;

	void move_piece(const std::string& home, const std::string& target);
	void clear_pos(const std::string& pos);

	void empty_board();
	void fill_board(const bool& is_white);

public:
	ChessBoard();

	void new_board() override;

	bool update(const std::string& home, const std::string& target) override;
	bool check_move(const std::string& home, const std::string& target) override;
	void draw(const std::string& message) const override;

	bool is_playable(const std::string& pos) const override;

	void change_turn() override;
};
