#version 150 core

in vec2 Texcoord;
out vec4 outColor;

uniform sampler2D surface_texture;
uniform int color_key;

void main()
{
	vec4 c = texture(surface_texture, Texcoord);
	if(c.r == color_key) {
		outColor = vec4(0, 0, 0, 0);
	} else {
		outColor = c;
	}
};
