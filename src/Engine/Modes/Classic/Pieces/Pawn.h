#pragma once
#include "Piece.h"

namespace classic
{
	class Pawn final : public Piece
	{
		const char type_char = 'P';

	public:
		Pawn(const Vector2& pos, const bool& isWhite) : Piece(pos, isWhite, 'P') {}

		std::vector<Vector2> show_moves(const std::vector<std::vector<Piece*>>& board) const override;
	};
}
 