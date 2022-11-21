#pragma once
#include "Piece.h"

namespace classic
{
	class Rock final : public Piece
	{
		const char type_char = 'R';

	public:
		Rock(const Vector2& pos, const bool& isWhite) : Piece(pos, isWhite, 'R') {}

		void show_moves(const std::vector<std::vector<Piece>>& board) const override;
	};
}
