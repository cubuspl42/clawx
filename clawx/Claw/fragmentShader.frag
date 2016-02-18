#version 150 core

in vec2 Texcoord;
out vec4 outColor;
uniform sampler2D surface_texture;
void main()
{
	vec4 c = texture(surface_texture, Texcoord);
	if(c.r == 0) {
		outColor = vec4(0, 0, 0, 0);
	} else {
		outColor = c;
	}
    //outColor = vec4(0.5, 0.5, 0.4, 1.0);
};
