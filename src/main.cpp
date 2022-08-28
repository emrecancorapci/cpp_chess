#include "Engine/ChessEngine.h"
#include "Engine/Helpers/Logger.h"

int main()
{
	Logger* logger = new Logger;
	IBoard* classicChessBoard = new ChessBoard(logger);
	auto* messageHandler = new MessageHandler;

	auto* stateFactory = new StateFactory(classicChessBoard, messageHandler);

	const auto engine = new ChessEngine(classicChessBoard, stateFactory, messageHandler);

	engine->run();
}
