#version 150 core

in vec2 Texcoord;
out vec4 outColor;
uniform sampler2D surface_texture;
uniform sampler1D palette_texture;
void main()
{
    outColor = texture(palette_texture, texture(surface_texture, Texcoord).r);
    //outColor = texture(surface_texture, Texcoord);
     //   outColor = vec4(0.1, 0.8, 0.9, 1.0);
};