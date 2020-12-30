#include "PCH/EGPCH.h"
#include "Model.h"

namespace Engine
{
	void Model::loadModel(const std::string& filepath, MeshStructure& mesh)
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
					mesh.positions.push_back(vertex);
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
		mesh.indices.resize(tempIndices.size());

		for (int i = 0; i < tempIndices.size(); ++i)
		{
			mesh.indices[i] = tempIndices[i] - 1;
		}

		std::cout << "num of verts: " << mesh.positions.size() << std::endl;
		std::cout << "num of indices: " << mesh.indices.size() << std::endl;

	}
}
