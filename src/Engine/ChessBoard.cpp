#include "ChessBoard.h"
#include <algorithm>

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
	fill_board(piece_color::white);
	fill_board(piece_color::black);
}

void chess_board::empty_board()
{
	board = std::vector(
		ROW,std::vector<Piece*>(
		COLUMN, nullptr));
}

void chess_board::fill_board(const piece_color& color)
{
	int row = 0, pawn_row = 1, i = 0;

	if (color == piece_color::white)
	{
		row = 7;
		pawn_row = 6;
	}

	board[row][0] = new Rock(vector2{row,0}, color);
	board[row][1] = new Knight(vector2{row,1}, color);
	board[row][2] = new Bishop(vector2{row,2}, color);
	board[row][3] = new Queen(vector2{row,3}, color);
	board[row][4] = new King(vector2{row,4}, color);
	board[row][5] = new Bishop(vector2{row,5}, color);
	board[row][6] = new Knight(vector2{row,6}, color);
	board[row][7] = new Rock(vector2{row,7}, color);

	for(auto& piece : board[pawn_row])
	{
		piece = new Pawn(vector2{pawn_row,i}, color);
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
			if (piece == nullptr)
			{
				std::cout << "   ";
				continue;
			}
			piece->draw_piece();
		}
		std::cout << std::endl;
	}

	std::cout << std::string( 24, ' ' ) << std::endl;
}

bool chess_board::is_playable(const std::string& pos, const piece_color& turn_color)
{
	return get_piece(pos)->get_color() == turn_color;
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
