#include "StateFactory.h"
#include "States/StateDecide.h"
#include "States/StateMove.h"

namespace classic
{
	StateFactory::StateFactory(engine::IBoard* board, MessageHandler* messageHandler)
	{
		_mapState.insert(std::pair<engine::GameState, engine::IState*>(engine::GameState::decide, new StateDecide(board, messageHandler)));
		_mapState.insert(std::pair<engine::GameState, engine::IState*>(engine::GameState::move, new StateMove(board, messageHandler)));
	}

	engine::IState* StateFactory::set_state(const engine::GameState& stateName)
	{
		return _mapState[stateName];
	}
}