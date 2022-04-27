#include <iostream>

#include "Engine/ChessEngine.h"

#define STATE_DECIDE 0
#define STATE_SELECT 1
#define STATE_MOVE 2

#define DRAW engine.draw();
#define CLEAR system("cls");

int main()
{
	chess_engine engine;
	int state = 0;
	std::string cmd, from;

	engine.new_match();

	while(engine.is_running)
	{
		DRAW

		if (cmd == "exit")
			engine.is_running = false;
		else if (cmd == "move")
			state = STATE_SELECT;
		else if (cmd == "cancel")
			state = STATE_DECIDE;

		switch (state)
		{
		case STATE_DECIDE:
			std::cout << "Decide :" << std::endl;
			std::cin >> cmd;
			break;

		case STATE_SELECT:
			std::cout << "Select :" << std::endl;
			std::cin >> cmd;

			engine.select_piece(cmd);
			from = cmd;

			state = STATE_MOVE;
			break;

		case STATE_MOVE:
			std::cout << "Move :" << std::endl;
			std::cin >> cmd;

			int success = engine.update(from, cmd);
			state = STATE_DECIDE;

			break;

		default:
			std::cout << "Wrong text!" << std::endl;
			state = STATE_DECIDE;
		}

		CLEAR
	}
}
