#pragma once

namespace engine
{
	enum class GameState
	{
		decide,
		select,
		move,
		exit,
		invalid
	};

	class IState
	{
	public:
		virtual ~IState() = default;
		virtual GameState init_state() = 0;
	};
}
