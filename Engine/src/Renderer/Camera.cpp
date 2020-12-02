#include "PCH/EGPCH.h"
#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glad\glad.h>


namespace Engine
{
	Camera::Camera()
	{
		this->firstMouse = true;
		this->updateCamera();
		this->cameraPosition = glm::vec3(0.0f, 0.0f, 10.0f);
		this->projMat = glm::perspectiveFov(glm::radians(45.0f), 1920.0f, 1080.0f, 0.1f, 1000.0f);
		this->viewMat = glm::lookAt(cameraPosition, this->cameraFront, cameraUp);
		this->worldMat = glm::mat4(1.0f);
	}

	void Camera::Move()
	{
		if (GetAsyncKeyState('W'))
		{
			this->cameraPosition += this->cameraFront * this->movementSpeed;
			this->updateCamera();
		}
		if (GetAsyncKeyState('S'))
		{
			this->cameraPosition -= this->cameraFront * this->movementSpeed;
			this->updateCamera();
		}
		if (GetAsyncKeyState('A'))
		{
			this->cameraPosition -= this->cameraRight * this->movementSpeed;
			this->updateCamera();
		}
		if (GetAsyncKeyState('D'))
		{
			this->cameraPosition += this->cameraRight * this->movementSpeed;
			this->updateCamera();
		}

	}

	void Camera::updateCamera()
	{
		// adjusting rotation
		this->cameraFront.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
		this->cameraFront.y = sin(glm::radians(this->pitch));
		this->cameraFront.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

		// creating and normalizing directional vectors
		this->cameraFront = glm::normalize(this->cameraFront);
		this->cameraRight = glm::normalize(glm::cross(this->cameraFront, this->defaultupVector));
		this->cameraUp = glm::normalize(glm::cross(this->cameraRight, this->cameraFront));

		// updating view matrix
		this->viewMat = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
	}

	void Camera::getmouseInput()
	{

		if (this->firstMouse)
		{
			this->lastmouseX = this->mouseX;
			this->lastmouseY = this->mouseY;
			this->firstMouse = false;
		}

		this->mouseoffsetX = this->mouseX - this->lastmouseX;
		this->mouseoffsetY = this->lastmouseY - this->mouseY;

		this->lastmouseX = this->mouseX;
		this->lastmouseY = this->mouseY;

	}

	void Camera::updatemouseInput(const double& offsetX, const double& offsetY)
	{
		this->pitch += static_cast<float>(offsetY) * this->movementSpeed;
		this->yaw += static_cast<float>(offsetX) * this->movementSpeed;

		if (this->pitch > 80.0f)
			this->pitch = 80.0f;
		else if (this->pitch < -80.0f)
			this->pitch = -80.0f;

		if (this->yaw > 360.0f || this->yaw < -360.0f)
			this->yaw = 0.0f;
		updateCamera();
	}
}
