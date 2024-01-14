#include <Vector2.hpp>

#ifndef __QUAD_SHAPE_HPP
#define __QUAD_SHAPE_HPP

using namespace L2DGL::Math;

namespace L2DGL::Graphics
{
    class QuadShape
    {
    private:
        Vector2 _position;
        Vector2 _scale;
        int _vectorSize = 2;
        int _verticesCount = 6;
        unsigned int _VBO, _VAO, _EBO;

    public:
        QuadShape(Vector2 scale);
        void draw();
        Vector2 getScale();
        void setScale(Vector2 scale);
        Vector2 getPosition();
        void setPosition(Vector2 position);
    };
}
#endif