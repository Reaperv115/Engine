#pragma once
#include "Core.h"
#include "Utilities\ErrorLogger.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>

namespace Engine
{
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string PixelSource;
	};

	class ENGINE_API Application
	{
	public:
		Application();
		~Application();

		static int createShader(const std::string& vertexShader, const std::string& pixelShader);
		static unsigned int compileShader(unsigned int type, const std::string& source);
		static ShaderProgramSource parseShader(const std::string& filepath);

		int Run();

	public:
		ErrorLogger errorLogger;
	};

	Application* CreateApplication();
}

