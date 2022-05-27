#pragma once
#include <Windows.h>
#include <iostream>

enum class piece_color
{
	white,
	black,
	nc
};

enum class piece_type
{
	pawn,
	rock,
	knight,
	bishop,
	queen,
	king,
	empty
};

enum class piece_state
{
	normal,
	selected,
	target,
};

class Piece
{
private:
	piece_type type;
	piece_color color;
	piece_state state = piece_state::normal;

	const char types[7] = {'P', 'R', 'H', 'B', 'Q', 'K', '_'};
	const char states[3] = {' ', '_', '|'};

	const HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

public:
	Piece(piece_type type, piece_color color);
	Piece(piece_type type, piece_color color, piece_state state);

	void set_state(piece_state set);
	void set_type(piece_type set);
	void set_color(piece_color set);

	piece_state get_state() const;
	piece_type get_type() const;
	piece_color get_color() const;

	void clear();
	void draw() const;
};

char draw_state(const int& state);
char draw_type(const int& type);
