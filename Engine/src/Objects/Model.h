#pragma once
#include "glm.hpp"
#include "Utilities\ErrorLogger.h"
#include "Objects\Vertex.h"

namespace Engine
{
	class Model
	{
	public:
		void loadModel(const std::string& filepath, MeshStructure& positions);
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

