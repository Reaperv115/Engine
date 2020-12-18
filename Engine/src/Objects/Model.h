#pragma once

namespace Engine
{
	class Model
	{
	public:
		bool loadModel(const std::string& filepath);
	public:
		float *positions;
		unsigned int *indices;
		unsigned int positionsIndiex = 0;
		unsigned int indicesIndex = 0;

	private:
		ErrorLogger errorLogger;
	};
}

