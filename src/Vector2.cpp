#include <Vector2.hpp>

namespace L2DGL::Math
{
    Vector2::Vector2()
    {
        this->x = 0;
        this->y = 0;
    }
    Vector2::Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
}
