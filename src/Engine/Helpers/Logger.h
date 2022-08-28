#pragma once
#include <map>
#include "Vector2.h"

class Logger
{
private:
	//std::map<Vector2, Vector2> _moves;
public:
	void log_move(const Vector2& home, const Vector2& target);
	//std::string log_get_all();
};
