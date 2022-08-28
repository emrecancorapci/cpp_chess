#pragma once
#include "Piece.h"

class King final : public Piece
{
private :
	const char type_char = 'K';
	
public:
	King(const Vector2& pos, const bool& is_white) : Piece(pos, is_white, 'K') {}

	void show_moves(const std::vector<std::vector<Piece>>& board) const override;
};
