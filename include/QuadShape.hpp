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
        Vector2 _size;
        int _vectorSize = 2;
        int _verticesCount = 6;
        unsigned int _VBO, _VAO, _EBO;
        void create();

    public:
        QuadShape(Vector2 size);
        void draw();
        Vector2 getSize();
        void setSize(Vector2 size);
        Vector2 getPosition();
        void setPosition(Vector2 position);
    };
}
#endif