#pragma once

namespace Engine
{
	class VertexArray
	{
	public:
		VertexArray();
	public:
		void createvertexBuffer(int numBuffers, unsigned int& buffer, float size, float& data);
		void enablevertexArray(int index, int size, float stride, const void* spotoffirstvertexAttribute);
	};
}

