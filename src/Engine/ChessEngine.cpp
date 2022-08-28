#include "ChessEngine.h"

void ChessEngine::new_match() const
{
	_chessBoard->new_board();
}

void ChessEngine::run() const
{
	GameState gameState = GameState::decide;
	bool isRunning = true;

	_chessBoard->new_board();
	_stateFactory->set_state(gameState);

	while(isRunning)
	{
		std::string message = _messageHandler->get_message();
		_chessBoard->draw(message);
		gameState = _stateFactory->set_state(gameState)->init_state();
	}
}

