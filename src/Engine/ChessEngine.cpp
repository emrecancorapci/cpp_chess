#include <iostream>
#include <array>

#include "ChessEngine.h"

chess_engine::chess_engine() : chessBoard(new chess_board) {chessBoard->new_board();}

struct vector2
{
	int x;
	int y;
};

vector2 convert_vector2(std::string pos);

void chess_engine::new_match() const
{
	chessBoard->new_board();
}

void chess_engine::select_piece(const std::string& piece) const
{
	const vector2 position = convert_vector2(piece);

	chessBoard->get_piece_ptr(position.x, position.y)->set_state(SELECTED);
}


void chess_engine::update_board(const std::string& from, const std::string& to) const
{
	const vector2 pos_from = convert_vector2(from);
	const vector2 pos_to = convert_vector2(to);

	// Get piece
	const Piece piece = chessBoard->get_piece(pos_from.x,pos_from.y);

	// Put piece
	chessBoard->put_piece(piece, pos_to.x, pos_to.y);
	chessBoard->get_piece_ptr(pos_from.x,pos_from.y)->set_state(NORMAL);

	// Clear before
	chessBoard->clear_pos(pos_from.x,pos_from.y);
}

void chess_engine::draw_board() const
{
	for (const auto* board = chessBoard->get_board();
		const auto& row : *board)
	{
		std::cout << std::endl;

		for (const Piece piece : row)
			piece.draw();

		std::cout << std::endl;
	}
}

void chess_engine::run()
{
	while(is_running)
	{
		draw_board();

		if (cmd == "exit")
			state = Exit;
		else if (cmd == "move")
			state = Select;
		else if (cmd == "cancel")
			state = Decide;
		else
			state = Invalid;

		change_state();

		CLEAR
	}
}

int chess_engine::change_state()
{
	switch (state)
	{
		case Decide:
			std::cout << "Decide :" << std::endl;
			std::cin >> cmd;

			break;

		case Select:
			std::cout << "Select :" << std::endl;
			std::cin >> cmd;

			select_piece(cmd);
			from = cmd;

			state = Move;
			break;

		case Move:
			std::cout << "Move :" << std::endl;
			std::cin >> cmd;

			update_board(from, cmd);

			state = Decide;

			break;

		case Exit:
			is_running = false;
			break;

		case Invalid:
			std::cout << "Wrong text!" << std::endl;
			state = Decide;
			std::cin >> cmd;
	}
	return 1;
}

vector2 convert_vector2(const std::string pos)
{
	const int x = static_cast<int>(pos[0])-96-1;
	const int y = static_cast<int>(pos[1])-48-1;
	return vector2{x,y};
}

