#pragma once

#include "Pawn.h"
#include "Rock.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

class PieceFactory
{
public:
	Pawn* createPawn(const vector2& pos, const bool& is_white);
	Rock* createRock(const vector2& pos, const bool& is_white);
	Knight* createKnight(const vector2& pos, const bool& is_white);
	Bishop* createBishop(const vector2& pos, const bool& is_white);
	Queen* createQueen(const vector2& pos, const bool& is_white);
	King* createKing(const vector2& pos, const bool& is_white);
};
