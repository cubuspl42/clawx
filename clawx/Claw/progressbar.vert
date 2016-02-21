#version 150 core

in vec2 position;

uniform mat4 trans;

void main()
{
    gl_Position = trans * vec4(position.x, position.y, 0, 1);
};
