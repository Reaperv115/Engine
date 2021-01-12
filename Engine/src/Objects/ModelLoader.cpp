#include "PCH/EGPCH.h"
#include "ModelLoader.h"

namespace Engine
{
	/*void ModelLoader::loadModel(const std::string& filepath, std::vector<Vertex>& model)
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
					tempVertices.push_back(vertex);
				}
				if (prefix == "f")
				{
					int counter = 0;

					unsigned int index;
					while (ss >> index)
					{
							tempIndices.push_back(index);
						
					}
					
				}
				
			}
		}
		model.resize(tempVertices.size());

		for (int i = 0; i < tempVertices.size(); ++i)
		{
			model[i].indice = tempIndices[i] - 1;
			model[i].position = tempVertices[i];
			model[i].color = glm::vec3(1.0f, 1.0f, 1.0f);
		}

		std::cout << "num of verts: " << model.size() << std::endl;

	}*/
}
