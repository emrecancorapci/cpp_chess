#include "ChessEngine.h"

namespace engine
{
	ChessEngine::ChessEngine(IBoard* board, IStateFactory* factory, MessageHandler* handler) :
		_chessBoard(board), _stateFactory(factory), _messageHandler(handler)
	{}

	void ChessEngine::new_match() const
	{
		_chessBoard->new_board();
	}

	void ChessEngine::run() const
	{
		GameState gameState = GameState::decide;
		bool isRunning = true;
		std::string message;

		_chessBoard->new_board();
		_stateFactory->set_state(gameState);

		while (isRunning)
		{
			message = _messageHandler->get_message();
			_chessBoard->draw(message);
			gameState = _stateFactory->set_state(gameState)->init_state();
		}
	}
}
