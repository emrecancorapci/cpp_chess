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
	Piece(const vector2& pos, const bool& is_white, const char& type);

	const HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	const char states[3] = {' ', '_', '|'};
	char type_txt;

	vector2 position;
	bool is_white;

	bool selected;
	bool targeted;

	bool moved;
	
public:
	virtual ~Piece() = default;

	vector2 get_position() const;
	bool get_color() const;
	bool is_selected() const;
	bool is_targeted() const;

	bool check_type(const Piece& piece) const;
	template <class T> bool check_type() const;
	

	void set_position(const int& x, const int& y);
	void set_position(const vector2& pos);
	void set_color(const bool& set);
	void set_selected(const bool& set);
	void set_targeted(const bool& set);

	char get_state() const;
	void draw_piece() const;

	virtual void show_moves(std::vector<std::vector<Piece>> board) const = 0;

};

