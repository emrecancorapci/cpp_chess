#include "PieceFactory.h"

namespace classic
{
	Pawn* PieceFactory::create_pawn(const Vector2& pos, const bool& isWhite)
	{
		return new Pawn(pos, isWhite);
	}

	Rock* PieceFactory::create_rock(const Vector2& pos, const bool& isWhite)
	{
		return new Rock(pos, isWhite);
	}

	Knight* PieceFactory::create_knight(const Vector2& pos, const bool& isWhite)
	{
		return new Knight(pos, isWhite);
	}

	Bishop* PieceFactory::create_bishop(const Vector2& pos, const bool& isWhite)
	{
		return new Bishop(pos, isWhite);
	}

	Queen* PieceFactory::create_queen(const Vector2& pos, const bool& isWhite)
	{
		return new Queen(pos, isWhite);
	}

	King* PieceFactory::create_king(const Vector2& pos, const bool& isWhite)
	{
		return new King(pos, isWhite);
	}
}