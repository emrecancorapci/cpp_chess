#pragma once

#include "../../../IState.h"
#include "../../../IBoard.h"
#include "../../../Helpers/MessageHandler.h"

namespace classic
{
	class StateMove final : public engine::IState
	{
	private:
		engine::IBoard* _board;
		MessageHandler* _messageHandler;

	public:
		StateMove(engine::IBoard* board, MessageHandler* messageHandler)
			: _board(board), _messageHandler(messageHandler) {}

		engine::GameState init_state() override;
	};

}
