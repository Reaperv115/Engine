#include "PCH/EGPCH.h"
#include "Model.h"

namespace Engine
{
	bool Model::loadModel(const std::string& filepath)
	{
		FILE* file = fopen(filepath.c_str(), "r");
		if (!file)
			errorLogger.Log(std::string("failed to open model file"));
		else
		{
			while (1)
			{
				char lineHeader[128];
				int res = fscanf(file, lineHeader);
				if (res == EOF)
					break;

				if (strcmp(lineHeader, "v") == 0)
				{

				}
			}
		}

		return true;
	}
}
