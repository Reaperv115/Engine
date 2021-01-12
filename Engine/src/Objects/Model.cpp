#include "PCH/EGPCH.h"
#include "Model.h"

namespace Engine
{
	void Model::loadModel(const std::string& filepath, std::vector<Vertex>& data)
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
					this->tempPositions.push_back(vertex);
				}
				if (prefix == "f")
				{
					unsigned int index;
					while (ss >> index)
					{
						this->modelIndices.push_back(index);

						if (ss.peek() == ' ')
						{
							ss.ignore(1, ' ');
						}
					}
					
				}
				
			}
		}
		data.resize(tempPositions.size());

		for (int i = 0; i < data.size(); ++i)
		{
			data[i].position = tempPositions[i];
		}

		std::cout << "num of verts: " << data.size() << std::endl;
		std::cout << "num of indices: " << this->modelIndices.size() << std::endl;

	}
}
