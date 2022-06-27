#pragma once
#include "Piece.h"

class King: public Piece
{
private :
	static const char type_txt = 'K';
	static const piece_type type = piece_type::king;

	vector2 position;

public:
	King(vector2 pos, piece_color color);

	void draw_piece() const override;
	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
