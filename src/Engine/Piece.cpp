#include "Piece.h"

#include <iostream>

#include "ChessBoard.h"

Piece::Piece(const int type, const bool color) : type(type), color(color) {}

void Piece::set_state(const int state)
{
	this->state = state;
}

int Piece::get_state() const
{
	return state;
}

void Piece::clear()
{
	type = EMPTY;
	color = NULL;
	state = NORMAL;
}

void Piece::draw() const
{
	std::cout << draw_state(state) << draw_type(type) << draw_state(state);
}

char draw_state(const int& state)
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

char draw_type(const int& type)
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