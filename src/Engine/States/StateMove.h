#pragma once
#include "StateBase.h"

class StateMove : public StateBase
{
public:
	void init_state(const bool& is_turn_white) const override;
};
