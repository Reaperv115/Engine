#include "PCH/EGPCH.h"
#include "VertexBuffer.h"
#include <glad/glad.h>

namespace Engine
{
	VertexBuffer::VertexBuffer()
	{

	}
	void VertexBuffer::createvertexBuffer(int numBuffers, unsigned int& buffer, float size, std::vector<glm::vec3>& data)
	{
		glGenBuffers(numBuffers, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_DYNAMIC_DRAW);
	}

	void VertexBuffer::enablevertexArray(int index, int size, float stride, const void* spotoffirstvertexAttribute)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, spotoffirstvertexAttribute);
	}
}
