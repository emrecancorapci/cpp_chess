#pragma once
#include "Piece.h"

namespace classic
{
	class King final : public Piece
	{
	public:
		King(const Vector2& pos, const bool& isWhite) : Piece(pos, isWhite, 'K') {}

		void show_moves(const std::vector<std::vector<Piece>>& board) const override;
	};
}
