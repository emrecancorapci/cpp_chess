#include "Pawn.h"

std::vector<Vector2> classic::Pawn::show_moves(const std::vector<std::vector<Piece*>>& board) const
{
	const auto [x,y] = get_position();
	const auto boardSize = Vector2(board[0].size(), board.size());
	std::vector<Vector2> positions;

	const int targetFront = _isWhite ? y+1 : y-1;
	const auto frontPiece = board[x][targetFront];
	const auto leftAttackPiece = board[x-1][targetFront];
	const auto rightAttackPiece = board[x+1][targetFront];

	const int targetFirstMove = _isWhite ? y+2 : y-2;
	const auto firstMovePiece = board[x][targetFirstMove];

	if(frontPiece == nullptr)
	{
		positions.push_back(frontPiece->get_position());

		if(firstMovePiece == nullptr && !_isMoved)
			positions.push_back(firstMovePiece->get_position());
	}

	if(leftAttackPiece != nullptr)
		positions.push_back(leftAttackPiece->get_position());
	if(rightAttackPiece != nullptr)
		positions.push_back(rightAttackPiece->get_position());

	return positions;
}