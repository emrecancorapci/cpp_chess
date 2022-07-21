#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

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
	Piece(const vector2& pos, const bool& is_white);

	const HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	const char states[3] = {' ', '_', '|'};
	char type_txt = 0;

	vector2 position;
	bool is_white;

	bool selected;
	bool targeted;

	bool moved;

public:
	virtual ~Piece() = default;

	bool get_color() const;
	bool get_selected() const;
	bool get_targeted() const;
	vector2 get_position() const;

	void set_color(bool set);
	void set_selected(bool set);
	void set_targeted(bool set);

	char get_state() const;

	virtual void draw_piece() const;
	virtual void show_moves(std::vector<std::vector<Piece>> board) const = 0;
};
