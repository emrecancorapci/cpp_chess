#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	empty_board();
}

std::vector<std::vector<Piece*>>* ChessBoard::get_board()
{
	return &board;
}

void ChessBoard::new_board()
{
	empty_board();
	fill_board(true);
	fill_board(false);
}

void ChessBoard::empty_board()
{
	board = std::vector(
		ROW,std::vector<Piece*>(
		COLUMN, nullptr));
}

void ChessBoard::fill_board(const bool& is_white)
{
	const int row{is_white? 0 : 7};
	const int pawn_row{is_white? 1 : 6};	

	board[row][0] = PieceFactory::create_rock(vector2{ row,0 }, is_white);
	board[row][1] = PieceFactory::create_knight(vector2{row,1}, is_white);
	board[row][2] = PieceFactory::create_bishop(vector2{row,2}, is_white);
	board[row][3] = PieceFactory::create_queen(vector2{row,3}, is_white);
	board[row][4] = PieceFactory::create_king(vector2{row,4}, is_white);
	board[row][5] = PieceFactory::create_bishop(vector2{row,5}, is_white);
	board[row][6] = PieceFactory::create_knight(vector2{row,6}, is_white);
	board[row][7] = PieceFactory::create_rock(vector2{row,7}, is_white);

	int i = 0;
	for(auto& piece : board[pawn_row])
	{
		piece = PieceFactory::create_pawn(vector2{pawn_row,i}, is_white);
		i++;
	}
}

bool ChessBoard::update(const std::string& from, const std::string& target)
{
	move_piece(from, target);
	clear_pos(from);

	return true;
}

bool ChessBoard::check_move(const std::string& home, const std::string& target)
{
	// TODO: implement check_move

	if(get_piece(target)->check_type<Queen>()) return false;

	return true;
}

void ChessBoard::draw(const std::string& message) const
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	std::cout << message << std::endl;
}

bool ChessBoard::is_playable(const std::string& pos, const bool& is_turn_white) const
{
	const auto piece = get_piece(pos);
	return piece->get_color() == is_turn_white && piece != nullptr;
}

void ChessBoard::move_piece(const std::string& home, const std::string& target)

{
	const auto [home_x, home_y] = convert_vector2(home);
	const auto [target_x, target_y] = convert_vector2(target);

	delete board[target_x][target_y];
	board[target_x][target_y] = board[home_x][home_y];

	board[target_x][target_y]->set_selected(false);
	board[target_x][target_y]->set_position(target_x, target_y);
}

void ChessBoard::clear_pos(const std::string& pos)
{
	const auto [x, y] = convert_vector2(pos);
	board[x][y] = nullptr;
}

Piece* ChessBoard::get_piece(const std::string& position) const
{
	const auto [x, y] = convert_vector2(position);

	return board[x][y];
}
Piece* ChessBoard::get_piece(const int& x, const int& y) const
{
	return board[x][y];
}
Piece* ChessBoard::get_piece(const vector2& vector) const
{
	return board[vector.x][vector.y];
}
