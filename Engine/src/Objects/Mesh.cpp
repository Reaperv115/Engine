#include "PCH/EGPCH.h"
#include "Mesh.h"

namespace Engine
{
	Mesh::Mesh(float* pos, unsigned int* indi)
	{
		positions = pos;
		indices = indi;
	}
}
