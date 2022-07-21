#pragma once
#include "ChessBoard.h"
#include <iostream>

#define CLEAR system("cls");

class ChessEngine final
{
private:
	IBoard* chessBoard;

	enum class game_state
	{
		decide,
		select,
		move,
		exit,
		invalid
	};

	game_state state = game_state::decide;
	bool is_white_turn = true;

	std::string from;
	std::string to;
	std::string cmd;
	std::string message;

	bool is_running_ = true;

	int change_state();
	void change_turn();

public:

	ChessEngine();

	void run();
	void new_match() const;

};
