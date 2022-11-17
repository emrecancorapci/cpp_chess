#include "StateFactory.h"

StateFactory::StateFactory(IBoard* board, MessageHandler* messageHandler)
{
	_mapState.insert(std::pair<GameState, IState*>(GameState::decide, new StateDecide(board, messageHandler)));
	_mapState.insert(std::pair<GameState, IState*>(GameState::move, new StateMove(board, messageHandler)));
}

IState* StateFactory::set_state(const GameState& stateName)
{
	return _mapState[stateName];
}
