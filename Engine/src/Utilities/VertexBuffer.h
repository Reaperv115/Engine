#pragma once

namespace Engine
{
	class VertexBuffer
	{
	public:
		VertexBuffer();
	public:
		void createvertexBuffer(int numBuffers, unsigned int& buffer, float size, float& data);
		void enablevertexArray(int index, int size, float stride, const void* spotoffirstvertexAttribute);

	public:
	};
}

