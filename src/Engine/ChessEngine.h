#pragma once
#include "States/StateFactory.h"
#include "Helpers/MessageHandler.h"
#include "States/IState.h"

class ChessEngine
{
private:
	IBoard* _chessBoard;
	StateFactory* _stateFactory;
	MessageHandler* _messageHandler;

public:
	ChessEngine(IBoard* board, StateFactory* factory, MessageHandler* handler):
	_chessBoard(board), _stateFactory(factory), _messageHandler(handler){}

	void run() const;
	void new_match() const;
};
