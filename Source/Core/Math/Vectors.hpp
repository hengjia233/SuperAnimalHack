#pragma once

class Vector2 final
{
public:
	Vector2(float x, float y) noexcept
		: x(x), y(y)
	{}

	float x, y;
};

class Vector3 final
{
public:
	Vector3(float x, float y, float z) noexcept
		: x(x), y(y), z(z)
	{}

	float x, y, z;
};
