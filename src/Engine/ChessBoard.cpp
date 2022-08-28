#include "ChessBoard.h"
#include "Helpers/Vector2.h"

#include <thread>

void ChessBoard::new_board()
{
	empty_board();

	std::thread whiteFiller([&]{fill_board(true);});
	std::thread blackFiller([&]{fill_board(false);});

	whiteFiller.join();
	blackFiller.join();
}

bool ChessBoard::update(const std::string& home, const std::string& target)
{
	move_piece(home, target);
	clear_pos(home);

	return true;
}

void ChessBoard::empty_board()
{
	_board = std::vector(
		ROW,std::vector<Piece*>(
		COLUMN, nullptr));
}

void ChessBoard::fill_board(const bool& is_white)
{
	const int row{is_white? 7 : 0};
	const int pawnRow{is_white? 6 : 1};	

	std::thread nonPawnFiller([&]{
		_board[row][0] = PieceFactory::create_rock(Vector2{ row,0 }, is_white);
		_board[row][1] = PieceFactory::create_knight(Vector2{row,1}, is_white);
		_board[row][2] = PieceFactory::create_bishop(Vector2{row,2}, is_white);
		_board[row][3] = PieceFactory::create_queen(Vector2{row,3}, is_white);
		_board[row][4] = PieceFactory::create_king(Vector2{row,4}, is_white);
		_board[row][5] = PieceFactory::create_bishop(Vector2{row,5}, is_white);
		_board[row][6] = PieceFactory::create_knight(Vector2{row,6}, is_white);
		_board[row][7] = PieceFactory::create_rock(Vector2{row,7}, is_white);
	});

	std::thread pawnFiller([&]{
		for (int i = 0; i < COLUMN; i++)
		{	
			_board[pawnRow][i] = PieceFactory::create_pawn(Vector2{pawnRow,i}, is_white);
		}
	});

	nonPawnFiller.join();
	pawnFiller.join();
}

void ChessBoard::change_turn()
{
	_isWhiteTurn = !_isWhiteTurn;
}


bool ChessBoard::check_move(const std::string& home, const std::string& target)
{
	// TODO: implement check_move

	// if(get_piece(target)->check_type<Queen>()) return false;

	return true;
}

void ChessBoard::draw(const std::string& message) const
{
	system("cls");

	for (const auto& row : _board)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);

		std::cout << std::string( 24, ' ' ) << std::endl;

		for(const auto& piece : row)
		{
			if (piece != nullptr)
			{
				piece->draw_piece();
				continue;
			}
			printf("   ");
		}
		printf("\n");
	}

	std::cout << std::string( 24, ' ' ) << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	printf("%s\n", message.c_str());
}

bool ChessBoard::is_playable(const std::string& pos) const
{
	const auto piece = get_piece(pos);
	const bool isPieceNull = piece == nullptr;

	if(isPieceNull) return false;

	const bool isPlayable = piece->get_color() == _isWhiteTurn && !isPieceNull;

	piece->set_selected(isPlayable);
	return isPlayable;
}

void ChessBoard::move_piece(const std::string& home, const std::string& target)
{
	const auto vHome = convert_vector2(home);
	const auto vTarget = convert_vector2(target);

	delete _board[vTarget.x][vTarget.y];
	_board[vTarget.x][vTarget.y] = _board[vHome.x][vHome.y];

	_board[vTarget.x][vTarget.y]->set_selected(false);
	_board[vTarget.x][vTarget.y]->set_position(vTarget.x, vTarget.y);

	_logger->log_move(vHome, vTarget);
}

void ChessBoard::clear_pos(const std::string& pos)
{
	const auto [x, y] = convert_vector2(pos);
	_board[x][y] = nullptr;
}

Piece* ChessBoard::get_piece(const std::string& position)
{
	const auto [x, y] = convert_vector2(position);

	return _board[x][y];
}

Piece* ChessBoard::get_piece(const std::string& position) const
{
	const auto [x, y] = convert_vector2(position);

	return _board[x][y];
}
