#pragma once

#include <glm.hpp>

struct MeshStructure
{
	std::vector<glm::vec3> positions;
	std::vector<unsigned int> indices;
	glm::vec3 color;
	glm::vec3 texture;
	glm::vec3 normal;
};