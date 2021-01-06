#pragma once
#include "glm.hpp"
#include "Utilities\ErrorLogger.h"
#include "Objects\Vertex.h"
#include "Core.h"

namespace Engine
{
	class ENGINE_API ModelLoader
	{
	public:
		void loadModel(const std::string& filepath, std::vector<Vertex>& model);
	private:
		std::vector<glm::vec3> tempVertices;
		std::vector<glm::vec2> temptextureCoords;
		std::vector<unsigned int> tempIndices;
		std::vector<unsigned int> temptextureIndices;

	private:
		ErrorLogger errorLogger;
		std::vector<Vertex> vertices;
	};
}

