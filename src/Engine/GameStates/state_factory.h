#pragma once
#include "state_base.h"
#include "state_decide.h"
#include "state_move.h"

#include <map>

class state_factory
{
private:
	enum state_type
	{
		decide,
		select,
		move,
		exit
	};
	
	std::map<state_type, state_base*> state_map;
public:
	explicit state_factory();

	state_base* set_state(const state_type& state_name);

	static state_type get_state_decide() { return decide; }
	static state_type get_state_select() { return select; }
	static state_type get_state_move() { return move; }
	static state_type get_state_exit() { return exit; }
};
