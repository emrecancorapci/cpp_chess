#pragma once
#include "IState.h"
#include "../Helpers/MessageHandler.h"

class StateMove final : public IState
{
private:
	IBoard* _board;
	MessageHandler* _messageHandler;

public:
	StateMove(IBoard* board, MessageHandler* messageHandler)
	: _board(board), _messageHandler(messageHandler){}

	GameState init_state() override;
};
