#include "Piece.h"

#include <Windows.h>

namespace classic
{
	Piece::Piece(const Vector2& pos, const bool& isWhite, const char& type)
	: _typeTxt(type), _position(pos), _isWhite(isWhite),
	  _isSelected(false), _isTargeted(false), _isMoved(false)
	{}

	auto Piece::get_position() const -> Vector2 { return _position; }
	auto Piece::get_color() const -> bool { return _isWhite; }
	auto Piece::is_selected() const -> bool { return _isSelected; }
	auto Piece::is_targeted() const -> bool { return _isTargeted; }

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
		_isTargeted = set;
	}
	void Piece::draw_piece() const
	{
		const WORD color = _isSelected ? 138 : _isWhite ? 143 : 128;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

		printf(" %c ", _typeTxt);
	}
}

