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
		void getmouseInput();
		void updatemouseInput(const double& offsetX, const double& offsetY);
	public:
		void updateCamera();

	public:
		//matrices
		glm::mat4 projMat;
		glm::mat4 viewMat;
		glm::mat4 worldMat;

		// default deirectional vectors
		glm::vec3 defaultforwardVector = glm::vec3(0.0f, 0.0f, 1.0f);
		glm::vec3 defaultrightVector = glm::vec3(1.0f, 0.0f, 0.0f);
		glm::vec3 defaultbackVector = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 defaultleftVector = glm::vec3(-1.0f, 0.0f, 0.0f);
		glm::vec3 defaultupVector = glm::vec3(0.0f, 1.0f, 0.0f);

		// camera transform components
		glm::vec3 cameraPosition;
		glm::vec3 cameraRotation;
		glm::vec3 cameraTarget;
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
		glm::vec3 cameraFront = glm::normalize(glm::cross(cameraUp, cameraRight));

		// used for camera rotation
		float roll;
		float pitch;
		float yaw;
		double mouseX, lastmouseX, mouseoffsetX;
		double mouseY, lastmouseY, mouseoffsetY;
		bool firstMouse;

		float movementSpeed = 0.3f;
	};
}

