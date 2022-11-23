#include "Rock.h"

std::vector<Vector2> classic::Rock::show_moves(const std::vector<std::vector<Piece*>>& board) const
{
	const auto [x,y] = get_position();
	const auto boardSize = Vector2(board[0].size(), board.size()); 

	std::vector<Vector2> positions;

	if(x > 0)
	{
		for(int i = x-1; i >= 0; --i) // x-1 x-2 ... 0
		{
			const auto piece = board[i][y];
			positions.push_back(piece->get_position());

			if(piece != nullptr) break;
		}
	}

	if(x < boardSize.x)
	{
		for(int i = x+1; i < boardSize.x; ++i) // x+1 x+2 ... boundary
		{
			const auto piece = board[i][y];
			positions.push_back(piece->get_position());

			if(piece != nullptr) break;
		}
	}

	if(y > 0)
	{
		for(int i = y-1; i >= 0; --i) // y-1 y-2 ... 0
		{
			const auto piece = board[x][i];
			positions.push_back(piece->get_position());

			if(piece != nullptr) break;
		}
	}

	if(y < boardSize.y)
	{
		for(int i = y+1; i < boardSize.y; ++i) // y+1 y+2 ... boundary
		{
			const auto piece = board[x][i];
			positions.push_back(piece->get_position());

			if(piece != nullptr) break;
		}
	}

	return positions;
}
