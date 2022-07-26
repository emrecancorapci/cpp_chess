#pragma once
#include <iostream>

#include "States/StateFactory.h"

#define CLEAR system("cls");

class ChessEngine final
{
private:
	IBoard* chessBoard;
	StateFactory* stateFactory;

	GameState game_state = GameState::decide;
	IState* current_state;

	bool is_running_ = true;

	int change_state();
	void change_turn();

public:
	ChessEngine();

	void run();
	void new_match() const;
	bool check_move(std::string from, std::string to);

};
