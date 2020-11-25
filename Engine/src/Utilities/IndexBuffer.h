#pragma once

namespace Engine
{
	class IndexBuffer
	{
	public:
		IndexBuffer();

		void generateBuffer(int numBuffers, unsigned int bufferObject, float size, unsigned int& data);
	};
}

