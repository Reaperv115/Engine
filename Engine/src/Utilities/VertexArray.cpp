#include "EGPCH.h"
#include "VertexArray.h"
#include <glad/glad.h>

namespace Engine
{
	VertexArray::VertexArray()
	{

	}
	void VertexArray::createvertexBuffer(int numBuffers, unsigned int& buffer, float size, float& data)
	{
		glGenBuffers(numBuffers, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, size, &data, GL_DYNAMIC_DRAW);
	}

	void VertexArray::enablevertexArray(int index, int size, float stride, const void* spotoffirstvertexAttribute)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, spotoffirstvertexAttribute);
	}
}
