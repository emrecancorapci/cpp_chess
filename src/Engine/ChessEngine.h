#pragma once
#include "ChessBoard.h"
#include <string>

#define CLEAR system("cls");

class chess_engine
{
	chess_board* chessBoard;

	std::string cmd = "cancel";
	std::string from;

	enum State
	{
		Decide,
		Select,
		Move,
		Exit,
		Invalid
	};

	State state = Decide;

	int change_state();

	void update_board(const std::string& from, const std::string& to) const;
	void draw_board() const;

	void select_piece(const std::string& piece) const;
	bool check_move();


public:
	bool is_running = true;

	chess_engine();

	void run();
	void new_match() const;

};


