#pragma once
#include "../Helper_Libraries/glm/glm.hpp"
#include <ext.hpp>

namespace Engine
{
	class Camera
	{
	public:
		Camera();

	public:
		glm::mat4 worldMat, viewMat, projMat;
	};
}

