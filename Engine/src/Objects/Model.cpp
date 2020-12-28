#include "PCH/EGPCH.h"
#include "Model.h"

namespace Engine
{
	bool Model::loadModel(const std::string& filepath, std::vector<glm::vec3>& positions, std::vector<unsigned int>& indices)
	{
		std::stringstream ss;
		std::ifstream fileStream(filepath);
		std::string lineheader;
		std::string prefix;

		if (!fileStream.is_open())
			errorLogger.Log((std::string)"Error: couldn't find file");
		else
		{
			while (std::getline(fileStream, lineheader))
			{
				ss.clear();
				ss.str(lineheader);
				ss >> prefix;

				if (prefix == "v")
				{
					glm::vec3 vertex;
					ss >> vertex.x >> vertex.y >> vertex.z;
					positions.push_back(vertex);
				}
				if (prefix == "f")
				{
					unsigned int index;
					while (ss >> index)
					{
						tempIndices.push_back(index);

						if (ss.peek() == ' ')
						{
							ss.ignore(1, ' ');
						}
					}
					
				}
				
			}
		}
		indices.resize(tempIndices.size());

		for (int i = 0; i < tempIndices.size(); ++i)
		{
			indices[i] = tempIndices[i] - 1;
		}

		std::cout << "num of verts: " << positions.size() << std::endl;
		std::cout << "num of indices: " << indices.size() << std::endl;

		if (positions.size() != 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}
