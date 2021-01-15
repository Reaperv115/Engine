#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

out vec3 vs_color;

uniform mat4 WVP;

void main()
{
	vs_color = color;

	gl_Position = WVP * vec4(position, 1.0);
}