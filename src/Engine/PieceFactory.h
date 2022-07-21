#pragma once

#include "Pieces/Pawn.h"
#include "Pieces/Rock.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"

class PieceFactory
{

public:
	static Pawn* create_pawn(const vector2& pos, const bool& is_white);
	static Rock* create_rock(const vector2& pos, const bool& is_white);
	static Knight* create_knight(const vector2& pos, const bool& is_white);
	static Bishop* create_bishop(const vector2& pos, const bool& is_white);
	static Queen* create_queen(const vector2& pos, const bool& is_white);
	static King* create_king(const vector2& pos, const bool& is_white);
};
