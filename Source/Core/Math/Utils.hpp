#pragma once

#include "Vectors.hpp"

namespace Utils
{
	template <typename T>
	inline T Sign(T val) {
		if (val < 0)
		{
			return val * -1;
		}

		return val;
	}

	inline Vector2 Sign(const Vector2& val)
	{
		return Vector2(Sign(val.x), Sign(val.y));
	}

	inline Vector3 Sign(const Vector3& val)
	{
		return Vector3(Sign(val.x), Sign(val.y), Sign(val.z));
	}
}
