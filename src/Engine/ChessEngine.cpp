#include <iostream>
#include <array>

#include "ChessEngine.h"

chess_engine::chess_engine() : chessBoard(new chess_board) {}

void DrawPiece(const Piece& piece);
char PieceState(const int& state);
char PieceType(const int& type);
std::vector<int> PositionTranslator(std::string pos);

void chess_engine::new_match() const
{
	chessBoard->new_board();
}

void chess_engine::select_piece(const std::string& piece) const
{
	auto* board = chessBoard->get_board();
	std::vector<int> position = PositionTranslator(piece);

	(*board)[position[0]][position[1]].state = SELECTED;
}


int chess_engine::update(const std::string& from, const std::string& to) const
{
	auto* board = chessBoard->get_board();

	const auto pos_from = PositionTranslator(from);
	const auto pos_to = PositionTranslator(to);

	// Get piece and clear
	Piece piece = (*board)[pos_from[0]][pos_from[1]];
	(*board)[pos_from[0]][pos_from[1]].clear();

	// Put piece
	piece.state = NORMAL;
	(*board)[pos_to[0]][pos_to[1]] = piece;

	return 1;
}

void chess_engine::draw() const
{
	const auto* board = chessBoard->get_board();

	for (const auto& row : *board)
	{
		std::cout << std::endl;

		for (const auto piece : row)
			DrawPiece(piece);

		std::cout << std::endl;
	}
}


void DrawPiece(const Piece& piece)
{
	std::cout << PieceState(piece.state) << PieceType(piece.type) << PieceState(piece.state);
}

char PieceState(const int& state)
{
	switch (state)
	{
	case SELECTED:
		return '-';
	case TARGET:
		return '|';
	default:
		return ' ';
	}
}

char PieceType(const int& type)
{
	switch (type)
	{
	case PAWN:
		return 'P';
	case ROCK:
		return 'R';
	case KNIGHT:
		return 'H';
	case BISHOP:
		return 'B';
	case QUEEN:
		return 'Q';
	case KING:
		return 'K';
	default: 
		return '_';
	}
}

std::vector<int> PositionTranslator(std::string pos)
{
	int x = int(pos[0])-96-1;
	int y = int(pos[1])-48-1;
	return std::vector<int>{x,y};
}