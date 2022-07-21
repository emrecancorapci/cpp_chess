#pragma once
#include <string>

class state_base
{
	enum class game_state
	{
		decide,
		select,
		move,
		exit,
		invalid
	};
protected:
	inline std::string static message;

	std::string show_message();
public:
	virtual void init_state(const bool& is_turn_white) const = 0;
};
