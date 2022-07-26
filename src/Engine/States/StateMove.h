#pragma once
#include "IState.h"

class StateMove final : public IState
{
private:
	IBoard* board;
	std::string message;
public:
	explicit StateMove(IBoard* board);
	GameState init_state() override;
	std::string& get_message() override;
};
