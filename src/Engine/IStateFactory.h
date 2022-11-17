#pragma once
#include "IState.h"

class IStateFactory
{
public:
	virtual IState* set_state(const GameState& stateName) = 0;
};