#version 150 core

out vec4 outColor;

uniform int color_index;

void main()
{
	outColor = vec4(color_index / 255.0, 0.0, 0.0, 1.0);
};
