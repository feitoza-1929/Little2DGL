#ifndef __COLOR_HPP
#define __COLOR_HPP

namespace L2DGL::Math
{
    class Color
    {
    public:
        Color();
        Color(float r, float g, float b);
        Color(float r, float g, float b, float a);
        float r;
        float g;
        float b;
        float a;
    };
}
#endif