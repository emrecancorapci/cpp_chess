#include <iostream>

#include "StateMove.h"

GameState StateMove::init_state()
{
	// Selection of the piece to move
	std::string from, to;

	std::cout << "Select :\n";
	std::cin >> from;

	const bool isSelectable = _board->is_playable(from);

	if(!isSelectable)
	{
		_messageHandler->set_message("Invalid selection");
		return GameState::move;
	}


	_board->draw(from + " selected");

	std::cout << "Move :\n";
	std::cin >> to;
	std::cout << from << "-" << to;

	const bool isPlayable = _board->check_move(from, to);

	if (isPlayable)
	{
		_board->update(from,  to);
		_messageHandler->set_message(from + " moved to " + to);
		_board->change_turn();
	}

	return GameState::decide;
}
