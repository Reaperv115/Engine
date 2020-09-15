#pragma once
#include <string>
#include <Windows.h>

namespace Engine
{
	class ErrorLogger
	{
	public:
		ErrorLogger();
		void Log(std::string message);
	};
}

