#pragma once
#include "Piece.h"


namespace classic
{
	class Queen final : public Piece
	{
	private:
		const char _typeChar = 'Q';

	public:
		Queen(const Vector2& pos, const bool& isWhite) : Piece(pos, isWhite, 'Q') {}

		std::vector<Vector2> show_moves(const std::vector<std::vector<Piece*>>& board) const override;
	};
}
