#include "Piece.h"

Piece::Piece(const vector2& pos, const bool& is_white) : is_white(is_white), position(pos)
{
	selected = false;
	targeted = false;
	moved = false;
}

char Piece::get_state() const
{
	return selected ? states[1] : targeted ? states[2] : states[0];
}

vector2 Piece::get_position() const
{
	return position;
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

void Piece::draw_piece() const
{
	if (is_white)
		SetConsoleTextAttribute(console_color, 143);
	else
		SetConsoleTextAttribute(console_color, 128);

	std::cout << get_state() << type_txt << get_state();
}