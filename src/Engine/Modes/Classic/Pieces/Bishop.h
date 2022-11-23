#pragma once
#include "Piece.h"

namespace classic
{
	class Bishop final : public Piece
	{
		const char type_char = 'B';

	public:
		Bishop(const Vector2& pos, const bool& is_white) : Piece(pos, is_white, 'B') {}

		std::vector<Vector2> show_moves(const std::vector<std::vector<Piece*>>& board) const override;
	};
}
