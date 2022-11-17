#include "Classic.h"

Classic::Classic(Logger* logger, MessageHandler* msgHandler)
{
	chessBoard = new ChessBoard(logger);
	stateFactory = new StateFactory(chessBoard, msgHandler);
}