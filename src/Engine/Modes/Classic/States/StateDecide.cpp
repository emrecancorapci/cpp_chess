#include "StateDecide.h"

#include <iostream>

namespace classic
{
	engine::GameState StateDecide::init_state()
	{
		std::string command;

		std::cout << "Decide (move, exit) :" << std::endl;
		std::cin >> command;

		if (command == "exit") return engine::GameState::exit;

		if (command == "move") return engine::GameState::move;

		std::cout << "Invalid command" << std::endl;
		return engine::GameState::decide;
	}
}
