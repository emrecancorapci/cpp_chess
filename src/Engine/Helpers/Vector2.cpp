#include "Vector2.h"

Vector2 Vector2::operator-(const Vector2& vec2) const
{
	return {this->x - vec2.x, this->y - vec2.y};
}

Vector2 Vector2::operator+(const Vector2& vec2) const
{
	return {this->x + vec2.x, this->y + vec2.y};
}

Vector2 convert_vector2(const std::string& pos)
{
	const int y = static_cast<int>(pos[1])-48;
	const int x = static_cast<int>(pos[0])-96;
	return {8-y,x-1};
}
