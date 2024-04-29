#version 330 core
out vec4 o_FragmentColor;

uniform vec4 u_Color;


void main()
{
   o_FragmentColor = u_Color;
}