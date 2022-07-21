#pragma once
#include "StateBase.h"
#include <iostream>

class StateDecide : public StateBase
{
private:
	
public:
	void init_state(const bool& is_turn_white) const override;
};
