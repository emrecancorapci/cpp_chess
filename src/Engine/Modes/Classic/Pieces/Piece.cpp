#include "Piece.h"

#include <Windows.h>

Piece::Piece(const Vector2& pos, const bool& isWhite, const char& type)
: _typeTxt(type), _position(pos), _isWhite(isWhite),
  _isSelected(false), _targeted(false), _isMoved(false)
{}


Vector2 Piece::get_position() const
{
	return _position;
}

bool Piece::get_color() const
{
	return _isWhite;
}

bool Piece::is_selected() const
{
	return _isSelected;
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
	_isSelected = set;
}

void Piece::set_targeted(const bool& set)
{
	_targeted = set;
}

void Piece::draw_piece() const
{
	const WORD color = _isSelected ? 138 : _isWhite ? 143 : 128;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	printf(" %c ", _typeTxt);
}
