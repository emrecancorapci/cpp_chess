#pragma once
#include <map>

#include "../../IState.h"
#include "../../IStateFactory.h"
#include "../../Helpers/MessageHandler.h"
#include "ChessBoard.h"

namespace classic
{	
	class StateFactory final : public engine::IStateFactory
	{
	private:
		std::map<engine::GameState, engine::IState*> _mapState;
	public:
		explicit StateFactory(engine::IBoard* board, MessageHandler* messageHandler);

		engine::IState* set_state(const engine::GameState& stateName) override;
	};
}
