#include "PCH/EGPCH.h"
#include "Shaders.h"
#include<glad/glad.h>

namespace Engine
{
	Shaders::Shaders(const char* vertexPath, const char* pixelPath)
	{
		std::string vertexCode, pixelCode;
		std::ifstream vshaderFile, pshaderFile;

		vshaderFile.open(vertexPath);
		pshaderFile.open(pixelPath);
		std::stringstream vshaderStream, pshaderStream;

		vshaderStream << vshaderFile.rdbuf();
		pshaderStream << pshaderFile.rdbuf();

		vshaderFile.close();
		pshaderFile.close();

		vertexCode = vshaderStream.str();
		pixelCode = pshaderStream.str();

		const char* vshaderCode = vertexCode.c_str();
		const char* pshaderCode = pixelCode.c_str();

		unsigned int vertex, pixel;
		int success;
		char infoLog[512];


		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vshaderCode, NULL);
		glCompileShader(vertex);
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "VERTEX SHADER COMPILATION FAILED" << std::endl;
		}

		pixel = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(pixel, 1, &pshaderCode, NULL);
		glCompileShader(pixel);
		glGetShaderiv(pixel, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(pixel, 512, NULL, infoLog);
			std::cout << "PIXEL SHADER COMPILATION FAILED" << std::endl;
		}

		iD = glCreateProgram();
		glAttachShader(iD, vertex);
		glAttachShader(iD, pixel);
		glLinkProgram(iD);

		glGetProgramiv(iD, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(iD, 512, NULL, infoLog);
			std::cout << "ERROR LINKING SHADER TO PROGRAM" << std::endl;
		}

		glDeleteShader(vertex);
		glDeleteShader(pixel);
	}

	void Shaders::setmatrixUniform(const std::string& shadervariableName, glm::mat4& value)
	{
		glUniformMatrix4fv(glGetUniformLocation(iD, shadervariableName.c_str()), 1, GL_FALSE, &value[0][0]);
	}
	void Shaders::setFloat(const std::string& shadervariableName, float n1, float n2, float n3, float n4)
	{
		glUniform4f(glGetUniformLocation(iD, shadervariableName.c_str()), n1, n2, n3, n4);
	}
	void Shaders::Use()
	{
		glUseProgram(iD);
	}

	unsigned int Shaders::getID()
	{
		return iD;
	}
}