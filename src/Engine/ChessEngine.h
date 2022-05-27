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
	piece_color turn_color_ = piece_color::white;

	std::string from,to, cmd, message = "";

	bool is_running_ = true;

	int change_state();
	bool select_piece(const std::string& piece) const;


public:

	chess_engine();

	void run();
	void new_match() const;

};
