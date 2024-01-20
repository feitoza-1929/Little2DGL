#version 330 core

in layout(location = 0) vec3 AttributePosition;
in layout(location = 1) vec3 AttributeColor;

out vec4 Color;

void main()
{
    gl_Position = vec4(AttributePosition, 1.0);
    Color = vec4(AttributeColor, 1.0);
}