#pragma once
#include "Piece.h"

class Queen final: public Piece
{
private:
	const char type_char = 'Q';

public:
	Queen(const vector2& pos, const bool& is_white) : Piece(pos, is_white, 'Q') {}
	
	void show_moves(const std::vector<std::vector<Piece>>& board) const override;
};
