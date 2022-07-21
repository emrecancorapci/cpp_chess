#include "ChessEngine.h"

ChessEngine::ChessEngine()
{
	chessBoard = new ChessBoard;
	new_match();
}

void ChessEngine::new_match() const
{
	chessBoard->new_board();
}

void ChessEngine::run()
{
	while(is_running_)
	{
		chessBoard->draw(message);
		change_state();
		CLEAR
	}
}

int ChessEngine::change_state()
{
	bool is_playable;

	switch (state)
	{
	case game_state::decide:
		std::cout << "Decide (move, exit) :" << std::endl;
		std::cin >> cmd;

		if (cmd == "exit")
			state = game_state::exit;
		else if (cmd == "move")
		{
			state = game_state::select;
			message = is_white_turn ? "White turn." : "Black turn.";
		}

		break;

	case game_state::select:
		std::cout << "Select piece:" << std::endl;
		std::cin >> from;

		is_playable = chessBoard->is_playable(from, is_white_turn);

		if (is_playable)
		{
			state = game_state::move;
			message = from + " selected.";
		}
		else
		{
			state = game_state::select;
			message = "Wrong selection!";
		}

		break;

	case game_state::move:
		std::cout << "Move :" << std::endl;
		std::cin >> to;

		std::cout << from << "-" << to;

		is_playable = chessBoard->check_move(from, to);

		if (is_playable)
		{
			chessBoard->update(from,  to);
			message = from + " moved to " + to;
			change_turn();
		}


		state = game_state::decide;
		break;

	case game_state::exit:
		is_running_ = false;
		break;

	case game_state::invalid:
		message = "Wrong text!";
		state = game_state::decide;
	}
	return 1;
}

void ChessEngine::change_turn()
{
	is_white_turn = is_white_turn ? false : true;
}
