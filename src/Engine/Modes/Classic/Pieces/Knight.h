#pragma once
#include "Piece.h"

namespace classic
{
	class Knight final : public Piece
	{
		const char type_char = 'H';

	public:
		Knight(const Vector2& pos, const bool& isWhite) : Piece(pos, isWhite, 'H') {}

		void show_moves(const std::vector<std::vector<Piece>>& board) const override;
	};

}
