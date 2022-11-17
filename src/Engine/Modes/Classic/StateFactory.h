#pragma once
#include <map>

#include "../../IState.h"
#include "../../IStateFactory.h"
#include "../../Helpers/MessageHandler.h"
#include "ChessBoard.h"
#include "States/StateDecide.h"
#include "States/StateMove.h"

class StateFactory : public IStateFactory
{
private:
	std::map<GameState, IState*> _mapState;
public:
	explicit StateFactory(IBoard* board, MessageHandler* messageHandler);

	IState* set_state(const GameState& stateName);
};
