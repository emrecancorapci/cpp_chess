#pragma once
#include "Piece.h"

class Bishop : public Piece
{
private :
	static const char type_txt = 'B';
	static const piece_type type = piece_type::bishop;

	vector2 position;

public:
	Bishop(vector2 pos, piece_color color);

	void draw_piece() const override;
	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
