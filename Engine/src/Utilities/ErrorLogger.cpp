#include "ErrorLogger.h"

namespace Engine
{
	ErrorLogger::ErrorLogger()
	{

	}

	void ErrorLogger::Log(std::string message)
	{
		std::string errorMessage = "Error: " + message;
		MessageBoxA(NULL, errorMessage.c_str(), "Error", MB_ICONERROR);
	}
}