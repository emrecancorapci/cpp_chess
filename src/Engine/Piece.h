#pragma once

class Piece
{
private:
	int type{};
	bool color{};
	int state{};
public:

	Piece(int type, bool color, int state);
	Piece(int type, bool color);

	void set_state(int state);
	int get_state() const;

	void clear();
	void draw() const;

};

char draw_state(const int& state);
char draw_type(const int& type);
