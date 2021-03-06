#pragma once
#include "Piece.h"

class Rock final: public Piece
{
private :
	const char type_char = 'R';

public:
	Rock(const vector2& pos, const bool& is_white) : Piece(pos, is_white, 'R') {}

	void show_moves(const std::vector<std::vector<Piece>>& board) const override;
};
