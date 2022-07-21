#pragma once
#include "state_base.h"

class state_move : public state_base
{
public:
	void init_state(const bool& is_turn_white) const override;
};
