#pragma once

#include "Pieces/Pawn.h"
#include "Pieces/Rock.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"

namespace classic
{
	class PieceFactory
	{
	public:
		static Pawn* create_pawn(const Vector2& pos, const bool& isWhite);
		static Rock* create_rock(const Vector2& pos, const bool& isWhite);
		static Knight* create_knight(const Vector2& pos, const bool& isWhite);
		static Bishop* create_bishop(const Vector2& pos, const bool& isWhite);
		static Queen* create_queen(const Vector2& pos, const bool& isWhite);
		static King* create_king(const Vector2& pos, const bool& isWhite);
	};
}