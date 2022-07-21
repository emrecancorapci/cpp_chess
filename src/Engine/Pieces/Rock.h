#pragma once
#include "Piece.h"

class Rock : public Piece
{
private :
	const char type_txt = 'R';

public:
	Rock(const vector2& pos, const bool& is_white);

	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
