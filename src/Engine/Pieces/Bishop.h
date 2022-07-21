#pragma once
#include "Piece.h"

class Bishop final : public Piece
{
private :
	const char type_char = 'B';

public:
	Bishop(const vector2& pos, const bool& is_white) : Piece(pos, is_white, 'B') {}

	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
