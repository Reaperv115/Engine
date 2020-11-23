#include "EGPCH.h"
#include "Camera.h"


namespace Engine
{
	Camera::Camera()
	{
		//projMat = glm::orthoLH(600, 2000, 1000, 400, 1, 100);
		this->updateCamera();
		this->cameraPosition = glm::vec3(0.0f, 0.0f, 10.0f);
		this->projMat = glm::perspectiveFov(glm::radians(45.0f), 640.0f, 480.0f, 0.1f, 1000.0f);
		this->viewMat = glm::lookAt(cameraPosition, this->cameraFront, cameraUp);
		this->worldMat = glm::mat4(1.0f);
		//worldMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.0f));
	}

	void Camera::Move()
	{
		if (GetAsyncKeyState('W'))
		{
			this->cameraPosition += this->cameraFront * this->movementSpeed;
			this->updateCamera();
			this->viewMat = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
		}
		if (GetAsyncKeyState('S'))
		{
			this->cameraPosition -= this->cameraFront * this->movementSpeed;
			this->updateCamera();
			this->viewMat = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
		}
		if (GetAsyncKeyState('A'))
		{
			this->cameraPosition -= this->cameraRight * this->movementSpeed;
			this->updateCamera();
			this->viewMat = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
		}
		if (GetAsyncKeyState('D'))
		{
			this->cameraPosition += this->cameraRight * this->movementSpeed;
			this->updateCamera();
			this->viewMat = glm::lookAt(this->cameraPosition, this->cameraPosition + this->cameraFront, this->cameraUp);
		}
	}

	void Camera::updateCamera()
	{
		this->cameraFront = glm::normalize(glm::cross(this->defaultupVector, this->defaultrightVector));
		this->cameraRight = glm::normalize(glm::cross(this->cameraFront, this->defaultupVector));
		this->cameraUp = glm::normalize(glm::cross(this->cameraRight, this->cameraFront));
	}
}
