#include "Piece.h"

void Piece::clear()
{
	type = piece_type::empty;
	color = piece_color::colorless;
	state = piece_state::normal;
}

void Piece::set_state(const piece_state set)
{
	state = set;
}

void Piece::set_color(const piece_color set)
{
	color = set;
}

vector2 Piece::get_pos() const
{
	return position;
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

vector2 convert_vector2(const std::string& pos)
{
	const int y = static_cast<int>(pos[1])-48;
	const int x = static_cast<int>(pos[0])-96;
	return {8-y,x-1};
}

vector2 vector2::operator-(const vector2& vec2) const
{
	return {this->x - vec2.x, this->y - vec2.y};
}

vector2 vector2::operator+(const vector2& vec2) const
{
	return {this->x + vec2.x, this->y + vec2.y};
}
