#include "QuadShape.hpp"
#include <GL/glew.h>
#include <GL/gl.h>

namespace Little2DGL{namespace Graphics
{
    QuadShape::QuadShape(float width, float heigth)
    {
        float vertices[_verticesCount][_vectorSize] = {
            {width, heigth},
            {width, -heigth},
            {-width, heigth},
            {-width, -heigth},
            {width, -heigth},
            {-width, heigth}
        };

        glGenVertexArrays(1, &_VAO);
        glBindVertexArray(_VAO);

        glGenBuffers(1, &_VBO);
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, _vectorSize, GL_FLOAT, GL_FALSE, NULL, (void*)0);
        glEnableVertexAttribArray(0);
    }

    void QuadShape::draw()
    {
        glBindVertexArray(_VAO);
        glDrawArrays(GL_LINE_LOOP, 0, _verticesCount);
    }
}}