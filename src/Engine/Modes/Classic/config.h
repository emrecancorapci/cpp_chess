#pragma once
#include "StateFactory.h"
#include "ChessBoard.h"


namespace classic
{
	class Config
	{
		ChessBoard* _chessBoard;
		StateFactory* _stateFactory;

	public:
		Config(Logger* logger, MessageHandler* msgHandler):
			_chessBoard(new ChessBoard(logger)),
			_stateFactory(new StateFactory(_chessBoard, msgHandler)){}

		ChessBoard* get_board() const { return _chessBoard; }
		StateFactory* get_state_factory() const { return _stateFactory; }
	};
}