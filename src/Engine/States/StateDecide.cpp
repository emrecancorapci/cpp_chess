#include "StateDecide.h"

GameState StateDecide::init_state()
{
	std::string command;

	std::cout << "Decide (move, exit) :" << std::endl;
	std::cin >> command;

	if (command == "exit") return GameState::exit;

	if (command == "move")
	{
		return GameState::move;
	}
	else 
	{
		std::cout << "Invalid command" << std::endl;
		return GameState::decide;
	}
}
