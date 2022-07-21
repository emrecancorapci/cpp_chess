#pragma once
#include "ChessBoard.h"

#include <iostream>
#include <array>
#include <string>
#include <Windows.h>

#define CLEAR system("cls");

class chess_engine
{
	chess_board* chessBoard = new chess_board;

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
	std::string message = "";

	bool is_running_ = true;

	int change_state();
	bool select_piece(const std::string& position) const;


public:

	chess_engine();

	void run();
	void new_match() const;

};
