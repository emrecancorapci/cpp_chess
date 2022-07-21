#pragma once
#include "States/StateBase.h"
#include "States/StateDecide.h"
#include "States/StateMove.h"

#include <map>

class StateFactory
{
private:
	enum state_type
	{
		decide,
		select,
		move,
		exit
	};
	
	std::map<state_type, StateBase*> state_map;
public:
	explicit StateFactory();

	StateBase* set_state(const state_type& state_name);

	static state_type get_state_decide() { return decide; }
	static state_type get_state_select() { return select; }
	static state_type get_state_move() { return move; }
	static state_type get_state_exit() { return exit; }
};
