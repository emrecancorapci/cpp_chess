#pragma once
#include "Piece.h"

class Knight : public Piece
{
private :
	static const char type_txt = 'H';
	static const piece_type type = piece_type::knight;

	vector2 position;

public:
	Knight(vector2 pos, piece_color color);

	void draw_piece() const override;
	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
