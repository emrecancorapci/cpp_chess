#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include "../Helpers/Vector2.h"

class Piece
{
protected:
	Piece(const Vector2& pos, const bool& isWhite, const char& type);

	const char _states[3] = {' ', '_', '|'};
	char _typeTxt;

	Vector2 _position;
	bool _isWhite;

	bool _selected;
	bool _targeted;

	bool _moved;
	
public:
	virtual ~Piece() = default;

	Vector2 get_position() const;
	char get_state() const;
	bool get_color() const;
	bool is_selected() const;
	bool is_targeted() const;

	bool check_type(const Piece& piece) const;

	void set_position(const int& x, const int& y);
	void set_position(const Vector2& pos);
	void set_color(const bool& set);
	void set_selected(const bool& set);
	void set_targeted(const bool& set);

	void draw_piece() const;

	virtual void show_moves(const std::vector<std::vector<Piece>>& board) const = 0;

};

