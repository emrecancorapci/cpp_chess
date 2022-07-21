#include "state_factory.h"

state_factory::state_factory()
{
	state_map.insert(std::pair<state_type, state_base*>(decide, new state_decide()));
	state_map.insert(std::pair<state_type, state_base*>(move, new state_move()));
}

state_base* state_factory::set_state(const state_type& state_name)
{
	return state_map[state_name];
}
