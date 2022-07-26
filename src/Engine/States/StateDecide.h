#pragma once
#include "IState.h"
#include <iostream>

class StateDecide : public IState
{
private:
	IBoard* board;
	std::string message;
public:
	explicit StateDecide(IBoard* board);
	GameState init_state() override;
	std::string& get_message() override;
};
