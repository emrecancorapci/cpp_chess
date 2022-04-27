#pragma once
#include "ChessBoard.h"

class chess_engine
{
	chess_board* chessBoard;

public:
	bool is_running = true;

	chess_engine();
	void new_match() const;
	void select_piece(const std::string& piece) const;
	int update(const std::string& from, const std::string& to) const;
	void draw() const;
	void change_state(int state);
};
