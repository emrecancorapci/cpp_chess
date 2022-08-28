#pragma once
#include "IState.h"
#include "../ChessBoard.h"
#include "../Helpers/MessageHandler.h"
#include "StateDecide.h"
#include "StateMove.h"

#include <map>

class StateFactory
{
private:
	std::map<GameState, IState*> _mapState;
public:
	explicit StateFactory(IBoard* board, MessageHandler* messageHandler);

	IState* set_state(const GameState& stateName);
};
