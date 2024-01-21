#ifndef __QUAD_SHAPE_HPP
#define __QUAD_SHAPE_HPP

#include <GL/glew.h>
#include <GL/gl.h>

#include <Vector2.hpp>
#include <Color.hpp>
#include <Shader.hpp>

using namespace L2DGL::Math;

namespace L2DGL::Graphics
{
    class QuadShape
    {
    private:
        Shader _shader;
        Vector2 _position;
        Vector2 _size;
        Color _color;

        int _vectorSize = 2;
        int _verticesCount = 6;

        unsigned int _VBO, _VAO, _EBO;
        void create();

    public:
        QuadShape() = default;
        QuadShape(Vector2 size);
        void draw();
        void paint(Color color);
        Vector2 getSize();
        void setSize(Vector2 size);
        Vector2 getPosition();
        void setPosition(Vector2 position);
    };
}
#endif