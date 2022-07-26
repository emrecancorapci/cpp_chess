#include "Piece.h"

Piece::Piece(const vector2& pos, const bool& is_white, const char& type)
: type_txt(type), position(pos), is_white(is_white)
{
	selected = false;
	targeted = false;
	moved = false;
}


vector2 Piece::get_position() const
{
	return position;
}

char Piece::get_state() const
{
	return selected ? states[1] : targeted ? states[2] : states[0];
}

bool Piece::get_color() const
{
	return is_white;
}

bool Piece::is_selected() const
{
	return selected;
}

bool Piece::is_targeted() const
{
	return targeted;
}

bool Piece::check_type(const Piece& piece) const
{
	return typeid(this).name() == typeid(piece).name();
}

template <class T>
bool Piece::check_type() const
{
	return typeid(this).name() == typeid(T).name();
}

void Piece::set_position(const int& x, const int& y)
{
	position = {x,y};
}

void Piece::set_position(const vector2& pos)
{
	position = pos;
}

void Piece::set_color(const bool& set)
{
	is_white = set;
}

void Piece::set_selected(const bool& set)
{
	selected = set;
}

void Piece::set_targeted(const bool& set)
{
	targeted = set;
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (is_white ? 143: 128));

	std::cout << get_state() << type_txt << get_state();
}