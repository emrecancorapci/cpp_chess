#include "ChessBoard.h"

chess_board::chess_board()
{
	empty_board();
}

std::vector<std::vector<Piece*>>* chess_board::get_board()
{
	return &board;
}

void chess_board::new_board()
{
	empty_board();
	fill_board(true);
	fill_board(false);
}

void chess_board::empty_board()
{
	board = std::vector(
		ROW,std::vector<Piece*>(
		COLUMN, nullptr));
}

void chess_board::fill_board(const bool& is_white)
{
	PieceFactory factory;
	int row = 0, pawn_row = 1, i = 0;

	if (is_white)
	{
		row = 7;
		pawn_row = 6;
	}

	board[row][0] = factory.createRock(vector2{ row,0 }, is_white);
	board[row][1] = factory.createKnight(vector2{row,1}, is_white);
	board[row][2] = factory.createBishop(vector2{row,2}, is_white);
	board[row][3] = factory.createQueen(vector2{row,3}, is_white);
	board[row][4] = factory.createKing(vector2{row,4}, is_white);
	board[row][5] = factory.createBishop(vector2{row,5}, is_white);
	board[row][6] = factory.createKnight(vector2{row,6}, is_white);
	board[row][7] = factory.createRock(vector2{row,7}, is_white);

	for(auto& piece : board[pawn_row])
	{
		piece = factory.createPawn(vector2{pawn_row,i}, is_white);
		i++;
	}
}

bool chess_board::update(const std::string& from, const std::string& target)
{
	put_piece(from, target);
	clear_pos(from);

	return true;
}

//bool chess_board::check_move(const std::string& home, const std::string& target)
//{
//	const Piece* p_home = get_piece(home);
//	const Piece* p_target = get_piece(target);
//
//	const vector2 v_home = convert_vector2(home);
//	const vector2 v_target = convert_vector2(target);
//	const vector2 move_vector = v_home - v_target;
//
//	const bool is_target_empty = p_target == nullptr;
//
//	if (p_home->get_color() == piece_color::white)
//	{
//		switch (p_home->get_type())
//		{
//			case piece_type::pawn:
//				// Is target at the top
//				if (move_vector.y == 1)
//				{
//					// Is target at the same column
//					if (move_vector.x == 0)
//					{
//						return is_target_empty;
//					}
//					// Is target at the next column and black
//					if (move_vector.x == 1 || move_vector.x == -1)
//					{
//						const bool is_black = p_target->get_color() == piece_color::black;
//						return !is_target_empty && is_black;
//					}
//				}
//				else if (move_vector.y == 2)
//				{
//
//				}
//				break;
//		case piece_type::rock:
//			break;
//		case piece_type::knight:
//			break;
//		case piece_type::bishop:
//			break;
//		case piece_type::queen:
//			break;
//		case piece_type::king:
//			break;
//		case piece_type::empty:
//			break;
//		default: ;
//		}
//	}
//
//	else if (p_home->get_color() == piece_color::black)
//	{
//		switch (p_home->get_type())
//		{
//		case piece_type::pawn:
//			break;
//		case piece_type::rock:
//			break;
//		case piece_type::knight:
//			break;
//		case piece_type::bishop:
//			break;
//		case piece_type::queen:
//			break;
//		case piece_type::king:
//			break;
//		case piece_type::empty:
//			break;
//		default: ;
//		}
//	}
//	return false;
//}

void chess_board::draw() const
{
	for (const auto& row : board)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);

		std::cout << std::string( 24, ' ' ) << std::endl;

		for(const auto& piece : row)
		{
			if (piece != nullptr)
			{
				piece->draw_piece();
				continue;
			}
			std::cout << "   ";
		}
		std::cout << std::endl;
	}

	std::cout << std::string( 24, ' ' ) << std::endl;
}

bool chess_board::is_playable(const std::string& pos, const bool& is_turn_white)
{
	return get_piece(pos)->get_color() == is_turn_white;
}

void chess_board::put_piece(const std::string& home, const std::string& target)

{
	const auto v_home = convert_vector2(home);
	const auto v_target = convert_vector2(target);

	delete board[v_target.x][v_target.y];
	board[v_target.x][v_target.y] = board[v_home.x][v_home.y];
}

void chess_board::clear_pos(const std::string& pos)
{
	const auto position = convert_vector2(pos);
	board[position.x][position.y] = nullptr;
}

Piece* chess_board::get_piece(const std::string& position) const
{
	const auto [x, y] = convert_vector2(position);

	return board[x][y];
}
Piece* chess_board::get_piece(const int& x, const int& y) const
{
	return board[x][y];
}
Piece* chess_board::get_piece(const vector2& vector) const
{
	return board[vector.x][vector.y];
}
