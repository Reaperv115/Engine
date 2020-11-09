#pragma once
#include "Core.h"
#include "Utilities/ErrorLogger.h"
#include <iostream>
#include "res/shaders/Shaders.h"

namespace Engine
{
	class ENGINE_API Application
	{
	public:
		Application();
		~Application();

		static int createShader(const std::string& vertexShader, const std::string& pixelShader);
		static unsigned int compileShader(unsigned int type, const std::string& source);

		int Run();

	public:
		ErrorLogger errorLogger;
	};

	Application* CreateApplication();
}

