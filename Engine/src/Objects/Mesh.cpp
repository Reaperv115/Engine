#include "PCH/EGPCH.h"
#include "Mesh.h"
#include <glad/glad.h>

namespace Engine
{
	Mesh::Mesh(std::vector<Vertex>& vertices, unsigned int numVerts, std::vector<unsigned int>& indices, unsigned int numIndices)
	{
		// resizing and filling model indices vector
		this->modelIndices.resize(numIndices);
		for (int i = 0; i < indices.size(); ++i)
		{
			this->modelIndices[i] = indices[i];
			++this->numofIndices;
		}

		// resizing and filling model vertices vector
		this->modelVertices.resize(numVerts);
		for (int i = 0; i < numVerts; ++i)
		{
			this->modelVertices[i] = vertices[i].position;
		}

		// creating vertex and index buffer objects
		initvertexbufferObject(this->vbo, this->modelVertices.size() * sizeof(glm::vec3), this->modelVertices);
		initindexbufferObject(this->ibo, this->modelIndices.size() * sizeof(unsigned int), this->modelIndices);
	}

	Mesh::Mesh()
	{

	}

	void Mesh::initvertexbufferObject(unsigned int buffer, float size, std::vector<glm::vec3>& data)
	{
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)offsetof(Vertex, position));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (GLvoid*)offsetof(Vertex, color));
		glEnableVertexAttribArray(1);
	}

	void Mesh::initindexbufferObject(unsigned int buffer, float size, std::vector<unsigned int>& data)
	{
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
	}
}
