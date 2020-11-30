#pragma once

namespace Engine
{
	class Mesh
	{
	public:
		Mesh(float* pos, unsigned int* indi);

	public:
		float* positions;
		unsigned int* indices;
		float size = 0;
	};
}

