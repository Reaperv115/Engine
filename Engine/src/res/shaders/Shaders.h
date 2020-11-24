#pragma once
#include "EGPCH.h"
#include <../glm/glm.hpp>

namespace Engine
{
    class Shaders
    {
    public:
        Shaders(const char* vertexPath, const char* pixelPath);

    public:
        unsigned int iD;

    public:
        void setmatrixUniform(const std::string& shadervariableName, glm::mat4& value);
        void setFloat(const std::string& shadervariableName, float n1, float n2, float n3, float n4);
        void Use();

        unsigned int getID();
    };
}