#pragma once
#include "StateFactory.h"
#include "PieceFactory.h"
#include "ChessBoard.h"

class Classic
{
	StateFactory* stateFactory;
	ChessBoard* chessBoard;
public:
	Classic(Logger* logger, MessageHandler* msgHandler);
	ChessBoard* getBoard() { return chessBoard; }
	StateFactory* getStateFactory() { return stateFactory; }
};

