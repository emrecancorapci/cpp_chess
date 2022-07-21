#include "StateFactory.h"

StateFactory::StateFactory()
{
	state_map.insert(std::pair<state_type, StateBase*>(decide, new StateDecide()));
	state_map.insert(std::pair<state_type, StateBase*>(move, new StateMove()));
}

StateBase* StateFactory::set_state(const state_type& state_name)
{
	return state_map[state_name];
}
