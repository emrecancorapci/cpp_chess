#include "ChessBoard.h"

chess_board::chess_board()
{
	empty_board(board);
}

PIECES_MATRIX* chess_board::get_board() { return &board; }

void chess_board::new_board()
{
	empty_board(board);
	fill_board(board, WHITE);
	fill_board(board, BLACK);
}


void chess_board::empty_board(PIECES_MATRIX& chessBoard)
{
	const int row = 8;
	const int column = 8;

	chessBoard = PIECES_MATRIX(row, std::vector<Piece>(column, 
			Piece(EMPTY, NULL)));
}

void chess_board::fill_board(PIECES_MATRIX& chessBoard, const bool& color)
{
	// Put pieces but pawns
	chessBoard[static_cast<int>(color) * 7] =
	{
			Piece(ROCK, color),
			Piece(KNIGHT, color),
			Piece(BISHOP, color),
			Piece(QUEEN, color),
			Piece(KING, color),
			Piece(BISHOP, color),
			Piece(KNIGHT, color),
			Piece{ROCK, color}
	};

	// Now put pawns
	for (int column = 0; column < COLUMN; column++)
	{
		chessBoard[color * 5 + 1][column] = Piece(PAWN, color);
	}
}

Piece* chess_board::get_piece_ptr(const int& row, const int& column)
{
	return &board[row][column];
}

Piece chess_board::get_piece(const int& row, const int& column) const
{
	return board[row][column];
}

void chess_board::put_piece(Piece piece, const int& row, const int& column)
{
	piece.set_state(NORMAL);
	board[row][column] = piece;
}

void chess_board::clear_pos(const int& row, const int& column)
{
	board[row][column] = Piece(EMPTY, NULL);
}

