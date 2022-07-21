#include "Pawn.h"

Pawn::Pawn(const vector2& pos, const bool& is_white) : Piece(pos, is_white) {}

void Pawn::show_moves(std::vector<std::vector<Piece>> board) const
{
	std::cout << "kill me";
}