#pragma once
#include "EGPCH.h"

namespace Engine
{
    class Shaders
    {
    public:
        Shaders(){}

        std::string vertexShader = R"(
        #version 330 core

        layout(location = 0) in vec4 position;

        uniform mat4 WVP;

        void main()
        {
            gl_Position = WVP * position;
        }
        )";
        std::string pixelShader = R"(
        #version 330 core

        layout(location = 0) out vec4 color;

        uniform vec4 u_Color;

        void main()
        {
            color = u_Color;
        }
	    )";
    };
}