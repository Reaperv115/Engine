#pragma once
#include "glm.hpp"
#include "Utilities\ErrorLogger.h"
#include "Objects\Vertex.h"

namespace Engine
{
	class Model
	{
	public:
		void loadModel(const std::string& filepath, std::vector<Vertex>& data);
	public:
		std::vector<glm::vec3> tempPositions;
		std::vector<unsigned int> modelIndices;
	private:
		ErrorLogger errorLogger;
	};
}

