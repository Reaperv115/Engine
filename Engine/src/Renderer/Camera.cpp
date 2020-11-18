#include "EGPCH.h"
#include "Camera.h"


namespace Engine
{
	Camera::Camera()
	{
		//projMat = glm::perspectiveFovLH(glm::degrees(90.0f), 900.0f, 600.0f, 0.1f, 100.0f);
		projMat = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
		viewMat = glm::lookAtLH(cameraPos, cameraTarg, defaultupVector);
		worldMat = glm::mat4(1.0f);
		//worldMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.0f));
	}

	void Camera::Move()
	{
		if (GetAsyncKeyState('W'))
		{
			cameraPos.z += 0.005f;
			cameraTarg.z += cameraPos.z;
			viewMat = glm::lookAtLH(cameraPos, cameraTarg, defaultupVector);
		}
		if (GetAsyncKeyState('S'))
		{
			cameraPos.z -= 0.005f;
			cameraTarg.z -= cameraPos.z;
			viewMat = glm::lookAtLH(cameraPos, cameraTarg, defaultupVector);
		}
	}
}
