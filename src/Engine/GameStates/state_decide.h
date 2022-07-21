#pragma once
#include "state_base.h"
#include <iostream>

class state_decide : public state_base
{
private:
	
public:
	state_decide();
	void init_state(const bool& is_turn_white) const override;
};
