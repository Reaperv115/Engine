#version 330 core

in vec3 vs_color;

out vec4 ps_color;

 void main()
 {
     ps_color = vec4(vs_color, 1.0);
 }