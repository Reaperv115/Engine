#pragma once
#include "Vertex.h"
#include "Utilities\IndexBuffer.h"
#include "Utilities\VertexBuffer.h"

namespace Engine
{
	class Mesh
	{
	public:
		Mesh(Vertex* vertexArr, unsigned int* indexArray, unsigned int numofVerts, unsigned int numofIndices);
		Mesh();

	public:
		void initvertexbufferObject(unsigned int buffer, float size, float& data);
		void initindexbufferObject(unsigned int buffer, float size, unsigned int& data);

	public:
		Vertex* vertexArray;
		unsigned int* indexArray;
		unsigned int numofVertices;
		unsigned int numofIndices;

	public:
		VertexBuffer vbo;
		IndexBuffer ibo;
	};
}

