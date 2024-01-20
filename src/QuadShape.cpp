#include <GL/glew.h>
#include <GL/gl.h>
#include <QuadShape.hpp>

namespace L2DGL::Graphics
{
    QuadShape::QuadShape(Vector2 size)
    {
        setSize(size);
        create();
    }

    void QuadShape::create()
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        float vertices[_verticesCount][_vectorSize]{
            {_size.x, _size.y},
            {_size.x, -_size.y},
            {-_size.x,_size.y},
            {-_size.x, -_size.y}};

        unsigned int indices[]{
            0, 1, 2,
            1, 2, 3};

        glGenVertexArrays(1, &_VAO);
        glBindVertexArray(_VAO);

        glGenBuffers(1, &_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &_EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, _vectorSize, GL_FLOAT, GL_FALSE, _vectorSize * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }

    void QuadShape::draw()
    {
        glBindVertexArray(_VAO);
        glDrawElements(GL_TRIANGLES, _verticesCount, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    Vector2 QuadShape::getSize()
    {
        return _size;
    }

    void QuadShape::setSize(Vector2 size)
    {
        _size = size;
    }

    Vector2 QuadShape::getPosition()
    {
        return _position;
    }

    void QuadShape::setPosition(Vector2 position)
    {
        _position = position;
    }
}