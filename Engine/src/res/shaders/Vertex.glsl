#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 WVP;

void main()
{
    gl_Position = WVP * position;
}