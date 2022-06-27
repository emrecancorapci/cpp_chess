#pragma once
#include "Piece.h"

class Rock : public Piece
{
private :
	static const char type_txt = 'R';
	static const piece_type type = piece_type::rock;

	vector2 position;

public:
	Rock(vector2 pos, piece_color color);

	void draw_piece() const override;
	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
