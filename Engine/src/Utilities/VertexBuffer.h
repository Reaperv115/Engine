#pragma once
#include "Objects\Vertex.h"

namespace Engine
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
	public:
		void createvertexBuffer(int numBuffers, unsigned int& buffer, float size, std::vector<glm::vec3>& data);
		void enablevertexArray(int index, int size, float stride, const void* spotoffirstvertexAttribute);

	public:
	};
}

