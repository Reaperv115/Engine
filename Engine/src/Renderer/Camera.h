#pragma once
#include "../Helper_Libraries/glm/glm.hpp"
#include <ext.hpp>

namespace Engine
{
	class Camera
	{
	public:
		Camera();

		void Move();

	public:
		//matrices
		glm::mat4 projMat;
		glm::mat4 viewMat;
		glm::mat4 worldMat;

		glm::vec3 defaultforwardVector = glm::vec3(0.0f, 0.0f, 1.0f);
		glm::vec3 defaultrightVector = glm::vec3(1.0f, 0.0f, 0.0f);
		glm::vec3 defaultbackVector = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 defaultleftVector = glm::vec3(-1.0f, 0.0f, 0.0f);
		glm::vec3 defaultupVector = glm::vec3(0.0f, 1.0f, 0.0f);

		glm::vec3 forwardVec;
		glm::vec3 rightVec;
		glm::vec3 backVec;
		glm::vec3 leftVec;

		glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraRotation = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 cameraTarg = glm::vec3(1.0f, 1.0f, 1.0f);
		glm::float32 position;
		glm::float32 rotation;

	};
}

