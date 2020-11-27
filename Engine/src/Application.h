#pragma once
#include "Core.h"

#include "Utilities/ErrorLogger.h"
#include "res/shaders/Shaders.h"
#include "Renderer/Camera.h"
#include "Utilities/VertexArray.h"
#include "Utilities/IndexBuffer.h"

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
		IndexBuffer ibo;
		Camera camera;
	};

	Application* CreateApplication();
}

