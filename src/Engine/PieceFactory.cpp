	#include "PieceFactory.h"

Pawn* PieceFactory::create_pawn(const Vector2& pos, const bool& is_white)
{
	return new Pawn(pos, is_white);
}

Rock* PieceFactory::create_rock(const Vector2& pos, const bool& is_white)
{
	return new Rock(pos, is_white);
}

Knight* PieceFactory::create_knight(const Vector2& pos, const bool& is_white)
{
	return new Knight(pos, is_white);
}

Bishop* PieceFactory::create_bishop(const Vector2& pos, const bool& is_white)
{
	return new Bishop(pos, is_white);
}

Queen* PieceFactory::create_queen(const Vector2& pos, const bool& is_white)
{
	return new Queen(pos, is_white);
}

King* PieceFactory::create_king(const Vector2& pos, const bool& is_white)
{
	return new King(pos, is_white);
}
