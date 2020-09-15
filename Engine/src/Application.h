#pragma once
#include "Core.h"
#include "Utilities\ErrorLogger.h"

namespace Engine
{
	class ENGINE_API Application
	{
	public:
		Application();
		~Application();

		int Run();

	public:
		ErrorLogger errorLogger;
	};

	Application* CreateApplication();
}

