#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private :
	static const char type_txt = 'P';
	static const piece_type type = piece_type::pawn;

	vector2 position;

public:
	Pawn(vector2 pos, piece_color color);

	void draw_piece() const override;
	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
 