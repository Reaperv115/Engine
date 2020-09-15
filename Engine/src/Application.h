#pragma once
#include "Core.h"

namespace Engine
{
	class ENGINE_API Application
	{
	public:
		Application();
		~Application();

		int Run();
	};

	Application* CreateApplication();
}

