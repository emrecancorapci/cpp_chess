#include "ChessBoard.h"

vector2 convert_vector2(const std::string& pos)
{
	const int x = static_cast<int>(pos[1])-48-1;
	const int y = static_cast<int>(pos[0])-96-1;
	return {x,y};
}

chess_board::chess_board()
{
	empty_board();
}

PIECES_MATRIX* chess_board::get_board()
{
	return &board;
}

bool chess_board::is_playable(const std::string& pos, const piece_color& turn)
{
	if(get_piece_ptr(pos)->get_color() == turn)
		return true;
	else
		return false;

}

void chess_board::new_board()
{
	empty_board();
	fill_board(piece_color::white);
	fill_board(piece_color::black);
}

void chess_board::empty_board()
{
	board = PIECES_MATRIX(ROW, std::vector<Piece>(COLUMN, 
			Piece(piece_type::empty, piece_color::nc)));
}

void chess_board::fill_board(const piece_color& color)
{
	int add = 0, pawn_add = 1;

	if (color == piece_color::white)
	{
		add = 7;
		pawn_add = 6;
	}

	// Put pieces but pawns
	for (int piece = 0; piece < ROW; piece++)
		board[add][piece].set_color(color);

	board[add][0].set_type(piece_type::rock);
	board[add][1].set_type(piece_type::knight);
	board[add][2].set_type(piece_type::bishop);
	board[add][3].set_type(piece_type::queen);
	board[add][4].set_type(piece_type::king);
	board[add][5].set_type(piece_type::bishop);
	board[add][6].set_type(piece_type::knight);
	board[add][7].set_type(piece_type::rock);

	// Now put pawns
	for (int piece = 0; piece < ROW; piece++)
	{
		board[pawn_add][piece].set_color(color);
		board[pawn_add][piece].set_type(piece_type::pawn);
	}
}

bool chess_board::update(const std::string& from, const std::string& to)
{
	const Piece piece = get_piece(from);
	clear_pos(from);

	put_piece(piece, to);
	
}

void chess_board::draw() const
{
	for (const auto& row : board)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);

		std::cout << std::string( 24, ' ' ) << std::endl;

		for (const Piece& piece : row)
			piece.draw();

		std::cout << std::endl;
	}

	std::cout << std::string( 24, ' ' ) << std::endl;
}

Piece* chess_board::get_piece_ptr(const std::string& position)
{
	const auto [x, y] = convert_vector2(position);

	return &board[x][y];
}

Piece chess_board::get_piece(const std::string& pos) const
{
	const auto [row, column] = convert_vector2(pos);

	return board[row][column];
}

void chess_board::put_piece(Piece piece, const std::string& pos)
{
	const auto [row, column] = convert_vector2(pos);

	piece.set_state(piece_state::normal);
	board[row][column].set_color(piece.get_color());
	board[row][column].set_type(piece.get_type());
	board[row][column].set_state(piece.get_state());
}

void chess_board::clear_pos(const std::string& pos)
{
	const auto [row, column] = convert_vector2(pos);

	board[row][column].set_color(piece_color::nc);
	board[row][column].set_type(piece_type::empty);
	board[row][column].set_state(piece_state::normal);
}