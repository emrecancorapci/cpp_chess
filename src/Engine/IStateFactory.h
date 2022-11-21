#pragma once
#include "IState.h"

namespace engine
{
	class IStateFactory
	{
	public:
		virtual ~IStateFactory() = default;
		virtual IState* set_state(const GameState& stateName) = 0;
	};
}
