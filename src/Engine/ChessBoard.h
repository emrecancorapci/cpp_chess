#pragma once

#include <vector>
#include <iostream>

#include "IBoard.h"
#include "PieceFactory.h"
#include "Helpers/Logger.h"

#define ROW 8
#define COLUMN 8

class ChessBoard final : public IBoard
{
private:
	std::vector<std::vector<Piece*>> _board;
	Logger* _logger;

	bool _isWhiteTurn = true;

	Piece* get_piece(const std::string& position);
	Piece* get_piece(const std::string& position) const;

	void move_piece(const std::string& home, const std::string& target);
	void clear_pos(const std::string& pos);

	void empty_board();
	void fill_board(const bool& isWhite);

public:
	explicit ChessBoard(Logger* logger) : _logger(logger) {}

	void new_board() override;

	bool update(const std::string& home, const std::string& target) override;
	bool check_move(const std::string& home, const std::string& target) override;
	void draw(const std::string& message) const override;

	bool is_playable(const std::string& pos) const override;

	void change_turn() override;
};
