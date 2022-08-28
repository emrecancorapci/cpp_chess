#pragma once
#include <string>

struct Vector2
{
	int x,y;
	Vector2 operator-(const Vector2& vec2) const;
	Vector2 operator+(const Vector2& vec2) const;
};

Vector2 convert_vector2(const std::string& pos);