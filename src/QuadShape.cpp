#include <QuadShape.hpp>

namespace L2DGL::Graphics
{

    QuadShape::QuadShape(Vector2 size)
    {
        const char *vertexShaderPath = "/home/feitoza/Sources/personal_projects/Little2DGraphicsLib/src/DefaultVertexShader.vert";
        const char *fragmentShaderPath = "/home/feitoza/Sources/personal_projects/Little2DGraphicsLib/src/DefaultFragmentShader.frag";

        _shader = Shader(vertexShaderPath, fragmentShaderPath);
        setSize(size);
        create();
    }

    void QuadShape::create()
    {
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

    void QuadShape::paint(Color color)
    {
        _color = color;
        _shader.activate();
        _shader.setVariableFloat4("Color", new float[4]{color.r, color.g, color.b, color.a});
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