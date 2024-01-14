#include <GL/glew.h>
#include <GL/gl.h>
#include <QuadShape.hpp>

namespace L2DGL::Graphics
{
    QuadShape::QuadShape(Vector2 scale)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        float vertices[_verticesCount][_vectorSize]{
            {scale.x, scale.y},
            {scale.x, -scale.y},
            {-scale.x, scale.y},
            {-scale.x, -scale.y}};

        unsigned int indices[]
        {
            0,1,2,
            1,2,3
        };

        glGenVertexArrays(1, &_VAO);
        glBindVertexArray(_VAO);

        glGenBuffers(1, &_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glGenBuffers(1, &_EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, _vectorSize, GL_FLOAT, GL_FALSE, _vectorSize * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

    void QuadShape::draw()
    {
        glBindVertexArray(_VAO);
        glDrawElements(GL_TRIANGLES, _verticesCount, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    Vector2 QuadShape::getScale()
    {
        return _scale;
    }

    void QuadShape::setScale(Vector2 scale)
    {
        _scale = scale;
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