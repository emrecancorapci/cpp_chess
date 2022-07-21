#pragma once
#include "Piece.h"

class Knight : public Piece
{
private :
	const char type_char = 'H';

public:
	Knight(const vector2& pos, const bool& is_white) : Piece(pos, is_white, 'H') {}

	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
