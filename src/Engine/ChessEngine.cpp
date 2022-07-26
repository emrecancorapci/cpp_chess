#include "ChessEngine.h"

#include "States/StateFactory.h"
#include "States/IState.h"

ChessEngine::ChessEngine()
{
	chessBoard = new ChessBoard;
	stateFactory = new StateFactory(chessBoard);
	current_state = stateFactory->set_state(game_state);

	new_match();
}

void ChessEngine::new_match() const
{
	chessBoard->new_board();
}

void ChessEngine::run()
{
	while(is_running_)
	{
		current_state = stateFactory->set_state(game_state);
		game_state = current_state->init_state();
		chessBoard->draw(current_state->get_message());

		CLEAR
	}
}