#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private :
	const char type_txt = 'P';

public:
	Pawn(const vector2& pos, const bool& is_white);

	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
 