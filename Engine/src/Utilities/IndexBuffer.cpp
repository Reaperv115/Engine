#include "PCH/EGPCH.h"
#include "IndexBuffer.h"
#include <glad/glad.h>

namespace Engine
{
	IndexBuffer::IndexBuffer()
	{

	}

	void IndexBuffer::generateBuffer(int numBuffers, unsigned int bufferObject, float size, std::vector<unsigned int>& data)
	{
		glGenBuffers(numBuffers, &bufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data[0], GL_DYNAMIC_DRAW);
	}
}