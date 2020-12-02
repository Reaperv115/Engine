#include "PCH/EGPCH.h"
#include "Mesh.h"

namespace Engine
{
	Mesh::Mesh(Vertex* vertexArr, unsigned int* indexArray, unsigned int numofVerts, unsigned int numofIndices)
	{
		this->numofVertices = numofVerts;
		this->numofIndices = numofIndices;
		this->vertexArray = new Vertex[this->numofVertices];
		for (size_t i = 0; i < numofVerts; ++i)
		{
			this->vertexArray[i] = vertexArr[i];
		}

		this->indexArray = new unsigned int[this->numofIndices];
		for (size_t i = 0; i < numofIndices; ++i)
		{
			this->indexArray[i] = indexArray[i];
		}
	}

	Mesh::Mesh()
	{

	}

	void Mesh::initvertexbufferObject(unsigned int buffer, float size, float& data)
	{
		vbo.createvertexBuffer(1, buffer, size, data);
		vbo.enablevertexArray(0, 2, sizeof(float) * 2, 0);
	}

	void Mesh::initindexbufferObject(unsigned int buffer, float size, unsigned int& data)
	{
		ibo.generateBuffer(1, buffer, size, data);
	}
}
