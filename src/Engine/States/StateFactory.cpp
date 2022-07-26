#include "StateFactory.h"

StateFactory::StateFactory(IBoard* board)
{
	map_state.insert(std::pair<GameState, IState*>(GameState::decide, new StateDecide(board)));
	map_state.insert(std::pair<GameState, IState*>(GameState::move, new StateMove(board)));
}

IState* StateFactory::set_state(const GameState& state_name)
{
	return map_state[state_name];
}
