#include "Rock.h"

Rock::Rock(const vector2 pos, const piece_color col)
{
	color = col;
	position = pos;
}

void Rock::draw_piece() const
{
	if(color == piece_color::white)
		SetConsoleTextAttribute(console_color, 143);
	else if (color == piece_color::black)
		SetConsoleTextAttribute(console_color, 128);

	std::cout	<< states[static_cast<int>(state)]
				<< type_txt
				<< states[static_cast<int>(state)];
}

void Rock::show_moves(std::vector<std::vector<Piece>> board) const
{

}