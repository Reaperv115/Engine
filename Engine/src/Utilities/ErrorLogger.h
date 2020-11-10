#pragma once
#include "EGPCH.h"

namespace Engine
{
	class ErrorLogger
	{
	public:
		ErrorLogger();
		void Log(std::string& message);
	};
}

