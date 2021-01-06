#pragma once
#include "Objects\Vertex.h"

namespace Engine
{
	class IndexBuffer
	{
	public:
		IndexBuffer();

		void generateBuffer(int numBuffers, unsigned int bufferObject, float size, std::vector<unsigned int>& data);
	};
}

