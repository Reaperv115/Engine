#pragma once
#include "Core.h"
#include "Utilities/ErrorLogger.h"
#include "res/shaders/Shaders.h"
#include "Renderer/Camera.h"
#include "Objects\Mesh.h"
#include "Objects\Model.h"

namespace Engine
{

	class ENGINE_API Application
	{
	public:
		Application();
		~Application();

		int Run();

	public:
		float deltaTime = 0.0f;
		float lastFrame = 0.0f;
		

	public:
		ErrorLogger errorLogger;
		std::vector<Mesh*> cubeMesh;
		Model model;
		Camera camera;

	private:
		std::vector<glm::vec3> cubePositions;
		std::vector<unsigned int> cubeIndices;
	};

	Application* CreateApplication();
}

