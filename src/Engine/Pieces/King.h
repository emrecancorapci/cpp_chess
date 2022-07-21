#pragma once
#include "Piece.h"

class King final : public Piece
{
private :
	const char type_txt = 'K';

public:
	King(const vector2& pos, const bool& is_white);

	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
