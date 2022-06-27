#pragma once
#include "Piece.h"

class Queen : public Piece
{
private :
	static const char type_txt = 'Q';
	static const piece_type type = piece_type::queen;

	vector2 position;

public:
	Queen(vector2 pos, piece_color color);

	void draw_piece() const override;
	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
