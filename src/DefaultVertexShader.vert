#version 330 core

in layout(location = 0) vec3 AttributePosition;

void main()
{
    gl_Position = vec4(AttributePosition, 1.0);
}