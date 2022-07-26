#pragma once
#include "Piece.h"

class Pawn final : public Piece
{
private :
	const char type_char = 'P';

public:
	Pawn(const vector2& pos, const bool& is_white) : Piece(pos, is_white, 'P') {}

	void show_moves(const std::vector<std::vector<Piece>>& board) const override;
};
 