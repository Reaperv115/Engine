#pragma once
#include <string>


namespace Engine
{
    class Shaders
    {
    public:
        Shaders(){}
#pragma region shaders
        std::string vertexShader = R"(
        #version 330 core
        layout(location = 0) in vec4 position;
        void main()
        {
            gl_Position = position ;
        }
        )";
        std::string pixelShader = R"(
        #version 330 core
        layout(location = 0) out vec4 color;
        void main()
        {
            color = vec4(1.0, 0.0, 0.0, 1.0);
        }
	    )";
#pragma endregion Vertex and Pixel shaders
    };
}