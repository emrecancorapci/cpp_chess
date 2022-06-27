#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

enum class piece_color
{
	white,
	black,
	colorless
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

struct vector2
{
	int x,y;
	vector2 operator-(const vector2& vec2) const;
	vector2 operator+(const vector2& vec2) const;
};

vector2 convert_vector2(const std::string& pos);
	
class Piece
{
protected:
	Piece(){}

	const HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	const char states[3] = {' ', '_', '|'};

	piece_type type;
	piece_color color;
	piece_state state = piece_state::normal;

	bool has_moved = false;
	vector2 position;


public:
	virtual ~Piece() = default;

	piece_state get_state() const;
	piece_type get_type() const;
	piece_color get_color() const;
	vector2 get_pos() const;

	void set_state(piece_state set);
	void set_color(piece_color set);

	void clear();

	virtual void draw_piece() const = 0;
	virtual void show_moves(std::vector<std::vector<Piece>> board) const = 0;
};

char draw_state(const int& state);
char draw_type(const int& type);
