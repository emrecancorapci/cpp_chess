#include "Piece.h"

Piece::Piece(const Vector2& pos, const bool& isWhite, const char& type)
: _typeTxt(type), _position(pos), _isWhite(isWhite), _selected(false), _targeted(false), _moved(false)
{}


Vector2 Piece::get_position() const
{
	return _position;
}

char Piece::get_state() const
{
	return _selected ? _states[1] : _targeted ? _states[2] : _states[0];
}

bool Piece::get_color() const
{
	return _isWhite;
}

bool Piece::is_selected() const
{
	return _selected;
}

bool Piece::is_targeted() const
{
	return _targeted;
}

void Piece::set_position(const int& x, const int& y)
{
	_position = {x,y};
}

void Piece::set_position(const Vector2& pos)
{
	_position = pos;
}

void Piece::set_color(const bool& set)
{
	_isWhite = set;
}

void Piece::set_selected(const bool& set)
{
	_selected = set;
}

void Piece::set_targeted(const bool& set)
{
	_targeted = set;
}

void Piece::draw_piece() const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (_isWhite ? 143: 128));

	std::cout << get_state() << _typeTxt << get_state();
}
