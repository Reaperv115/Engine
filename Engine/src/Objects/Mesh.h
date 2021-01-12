#pragma once
#include "Vertex.h"
#include "Utilities\IndexBuffer.h"
#include "Utilities\VertexBuffer.h"


namespace Engine
{
	class Mesh
	{
	public:
		Mesh(std::vector<Vertex>& vertices, unsigned int numVerts, std::vector<unsigned int>& indices, unsigned int numIndices);
		Mesh();

	public:
		void initvertexbufferObject(unsigned int buffer, float size, std::vector<glm::vec3>& data);
		void initindexbufferObject(unsigned int buffer, float size, std::vector<unsigned int>& data);

	public:
		unsigned int numofIndices = 0;

	private:
		std::vector<glm::vec3> modelVertices;
		std::vector<unsigned int> modelIndices;

	private:
		unsigned int vbo = 1;
		unsigned int ibo = 1;
	};
}

