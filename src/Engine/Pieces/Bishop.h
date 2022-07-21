#pragma once
#include "Piece.h"

class Bishop : public Piece
{
private :
	const char type_txt = 'B';

public:
	Bishop(const vector2& pos, const bool& is_white);

	void show_moves(std::vector<std::vector<Piece>> board) const override;
};
