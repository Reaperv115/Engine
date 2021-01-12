#version 330 core

layout(location = 1) in vec3 position;


uniform mat4 WVP;

void main()
{

	gl_Position = WVP * vec4(v_position, 1.0);
}