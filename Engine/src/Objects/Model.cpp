#include "PCH/EGPCH.h"
#include "Model.h"

namespace Engine
{
	void Model::loadModel(const std::string& filepath, std::vector<Vertex>& data)
	{
		std::stringstream ss;
		std::ifstream file(filepath);
		std::string prefix;
		std::string line;

		if (!file.is_open())
			errorLogger.Log(std::string("unable to open model file"));
		else
		{
			while (std::getline(file, line))
			{
				ss.clear();
				ss.str(line);
				ss >> prefix;


				if (prefix == "v")
				{
					glm::vec3 vertex;
					ss >> vertex.x >> vertex.y >> vertex.z;
					tempPositions.push_back(vertex);
				}
				if (prefix == "f")
				{
					unsigned int index;
					while (ss >> index)
					{
						this->modelIndices.push_back(index - 1);

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
			data[i].color = glm::vec3(1.0f, 0.0f, 0.0f);
		}

		std::cout << "num of verts: " << data.size() << std::endl;
		std::cout << "num of indices: " << this->modelIndices.size() << std::endl;

	}
}
