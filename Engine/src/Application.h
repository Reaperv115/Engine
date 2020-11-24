#pragma once
#include "Core.h"
#include "Utilities/ErrorLogger.h"
#include "res/shaders/Shaders.h"
#include "Renderer/Camera.h"
#include "Utilities/VertexArray.h"

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
		VertexArray vao;
		Camera camera;
	};

	Application* CreateApplication();
}

