#pragma once
#include <iostream>
#include "IState.h"
#include "../Helpers/MessageHandler.h"

class StateDecide final : public IState
{
private:
	IBoard* _board;
	MessageHandler* _messageHandler;
public:
	StateDecide(IBoard* board, MessageHandler* messageHandler)
	: _board(board), _messageHandler(messageHandler){}

	GameState init_state() override;
};
