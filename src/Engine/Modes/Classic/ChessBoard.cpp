#include "ChessBoard.h"

#include <thread>
#include <Windows.h>
#include "../../Helpers/Vector2.h"

#define SET_CONSOLE_COLOR(C) (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), C))

namespace classic
{
	void ChessBoard::new_board()
	{
		empty_board();

		std::thread whiteFiller([&] {fill_board(true); });
		std::thread blackFiller([&] {fill_board(false); });

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
			ROW, std::vector<Piece*>(COLUMN, nullptr));
	}

	void ChessBoard::fill_board(const bool& isWhite)
	{
		const int row{ isWhite ? 7 : 0 };
		const int pawnRow{ isWhite ? 6 : 1 };

		std::thread nonPawnFiller([&] {
			_board[row][0] = PieceFactory::create_rock(Vector2{ row,0 }, isWhite);
			_board[row][1] = PieceFactory::create_knight(Vector2{ row,1 }, isWhite);
			_board[row][2] = PieceFactory::create_bishop(Vector2{ row,2 }, isWhite);
			_board[row][3] = PieceFactory::create_queen(Vector2{ row,3 }, isWhite);
			_board[row][4] = PieceFactory::create_king(Vector2{ row,4 }, isWhite);
			_board[row][5] = PieceFactory::create_bishop(Vector2{ row,5 }, isWhite);
			_board[row][6] = PieceFactory::create_knight(Vector2{ row,6 }, isWhite);
			_board[row][7] = PieceFactory::create_rock(Vector2{ row,7 }, isWhite);
			});

		std::thread pawnFiller([&] {
			for (int i = 0; i < COLUMN; i++)
				_board[pawnRow][i] = PieceFactory::create_pawn(Vector2{ pawnRow,i }, isWhite);
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
			SET_CONSOLE_COLOR(136);

			printf("%s\n", std::string(24, ' ').c_str());

			for (const auto& piece : row)
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

		printf("%s\n", std::string(24, ' ').c_str());

		SET_CONSOLE_COLOR(15);

		printf("%s\n", message.c_str());
	}

	bool ChessBoard::is_playable(const std::string& pos) const
	{
		const auto [x, y] = convert_vector2(pos);
		const bool inBoundaries = x < 0 || x >= ROW || y < 0 || y >= COLUMN;
		if (inBoundaries) return false;

		const auto piece = get_piece(pos);
		const bool isPieceNull = piece == nullptr;

		if (isPieceNull) return false;

		const bool isPlayable = piece->get_color() == _isWhiteTurn;

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

	Piece* ChessBoard::get_piece(const std::string& pos)
	{
		const auto [x, y] = convert_vector2(pos);

		return _board[x][y];
	}

	Piece* ChessBoard::get_piece(const std::string& pos) const
	{
		const auto [x, y] = convert_vector2(pos);

		return _board[x][y];
	}

}