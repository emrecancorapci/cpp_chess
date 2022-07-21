#include "ChessEngine.h"

chess_engine::chess_engine()
{
	chessBoard->new_board();
}

void chess_engine::new_match() const
{
	chessBoard->new_board();
}

void chess_engine::run()
{
	while(is_running_)
	{
		chessBoard->draw();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << message << std::endl;

		change_state();

		CLEAR
	}
}

int chess_engine::change_state()
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

		is_playable = select_piece(from);

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

		is_playable = chessBoard->update(from,  to);

		// Check move gonna implemented

		if (true)
		{
			message = from + " moved to " + to;
			is_white_turn = is_white_turn ? false : true;
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

bool chess_engine::select_piece(const std::string& position) const
{
	const auto piece = chessBoard->get_piece(position);
	if (piece == nullptr)
		return false;

	const bool is_colors_match = piece->get_color() == is_white_turn;

	if (is_colors_match)
		piece->set_selected(true);

	return is_colors_match;
}
