#pragma once
#include "Piece.h"

namespace classic
{
	class Rock final : public Piece
	{
		const char _typeChar = 'R';

	public:
		Rock(const Vector2& pos, const bool& isWhite) : Piece(pos, isWhite, 'R') {}

		std::vector<Vector2> show_moves(const std::vector<std::vector<Piece*>>& board) const override;
	};
}
