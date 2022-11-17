#pragma once
#include "IStateFactory.h"
#include "IState.h"

#include "Helpers/MessageHandler.h"

class ChessEngine
{
private:
	IBoard* _chessBoard;
	IStateFactory* _stateFactory;
	MessageHandler* _messageHandler;

public:
	ChessEngine(IBoard* board, IStateFactory* factory, MessageHandler* handler):
	_chessBoard(std::move(board)), _stateFactory(std::move(factory)), _messageHandler(handler){}

	void run() const;
	void new_match() const;
};
