#version 150 core

in vec2 Texcoord;
out vec4 outColor;

uniform sampler2D surface_texture;
uniform sampler1D palette_texture;

void main()
{
    outColor = texture(palette_texture, texture(surface_texture, Texcoord).r);
};
