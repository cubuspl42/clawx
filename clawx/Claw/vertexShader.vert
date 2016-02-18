#version 150 core

in vec2 position;
in vec2 texcoord;
out vec2 Texcoord;
uniform mat4 trans;
uniform vec2 pos;

void main()
{
    Texcoord = texcoord;
    gl_Position = trans * vec4(position.x + pos.x, position.y + pos.y, 0, 1);
    //gl_Position = pos * vec4(position, 0.0, 1.0);

};
