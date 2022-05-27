#include "Piece.h"


Piece::Piece(const piece_type type, const piece_color color) : type(type), color(color) {}

void Piece::clear()
{
	type = piece_type::empty;
	color = piece_color::nc;
	state = piece_state::normal;
}

void Piece::draw() const
{
	if(color == piece_color::white)
		SetConsoleTextAttribute(console_color, 143);
	else if (color == piece_color::black)
		SetConsoleTextAttribute(console_color, 128);
	else
		SetConsoleTextAttribute(console_color, 136);

	std::cout	<< states[static_cast<int>(state)]
				<< types[static_cast<int>(type)]
				<< states[static_cast<int>(state)];
}

void Piece::set_state(const piece_state set)
{
	state = set;
}

void Piece::set_type(const piece_type set)
{
	type = set;
}

void Piece::set_color(const piece_color set)
{
	color = set;
}

piece_state Piece::get_state() const
{
	return state;
}

piece_type Piece::get_type() const
{
	return type;
}

piece_color Piece::get_color() const
{
	return color;
}
