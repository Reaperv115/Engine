#pragma once
#include "glm.hpp"
#include "Utilities\ErrorLogger.h"

namespace Engine
{
	class Model
	{
	public:
		bool loadModel(const std::string& filepath, std::vector<glm::vec3>& positions, std::vector<unsigned int>& indices);
	public:
		std::vector<glm::vec3> tempPositions;
		std::vector<unsigned int> tempIndices;
		unsigned int positionsIndiex = 0;
		unsigned int indicesIndex = 0;

	private:
		ErrorLogger errorLogger;
		unsigned int indiceIndex = 0;
	};
}

