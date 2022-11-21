#pragma once
#include "Helpers/MessageHandler.h"

#include "IStateFactory.h"
#include "IBoard.h"

namespace engine
{
	class ChessEngine
	{
		IBoard* _chessBoard;
		IStateFactory* _stateFactory;
		MessageHandler* _messageHandler;

	public:
		ChessEngine(IBoard* board, IStateFactory* factory, MessageHandler* handler);

		void run() const;
		void new_match() const;
	};

}
