#include "StateMove.h"
#include <iostream>

StateMove::StateMove(IBoard* board)
{
	this->board = board;
}

GameState StateMove::init_state()
{
	// Selection of the piece to move
	std::string from, to;

	std::cout << "Select :\n";
	std::cin >> from;

	const bool is_selectable = board->is_playable(from);

	if(!is_selectable)
	{
		message = "Invalid selection";
		return GameState::move;
	}

	// Movement of the piece

	message = from + " selected.";
	board->draw(message);

	std::cout << "Move :\n";
	std::cin >> to;
	std::cout << from << "-" << to;

	const bool is_playable = board->check_move(from, to);

	if (is_playable)
	{
		board->update(from,  to);
		message = from + " moved to " + to;
		board->change_turn();
	}

	return GameState::decide;
}

std::string& StateMove::get_message()
{
	return message;
}
