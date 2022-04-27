#include "ChessBoard.h"

void empty_board(PIECES_MATRIX& chessBoard);
void fill_board(PIECES_MATRIX& chessBoard, const bool& color);

chess_board::chess_board()
{
	empty_board(board);
}

PIECES_MATRIX* chess_board::get_board()
{
	return &board;
}

void chess_board::new_board()
{
	empty_board(board);
	fill_board(board, WHITE);
	fill_board(board, BLACK);
}


void empty_board(PIECES_MATRIX& chessBoard)
{
	chessBoard = PIECES_MATRIX(8, std::vector<Piece>(8, Piece(EMPTY, NULL)));
}

void fill_board(PIECES_MATRIX& chessBoard, const bool& color)
{
	// Put pieces but pawns
	chessBoard[static_cast<int>(color)*7] =
	{
			Piece{ROCK, color},
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
		chessBoard[1 + color*5][column] = Piece(PAWN, color);
	}
}