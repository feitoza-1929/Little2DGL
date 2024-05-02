#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <GL/glew.h>
#include <stdlib.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Vector2.hpp>
#include <Color.hpp>
#include <Shader.hpp>
#include <VertexBuffer.hpp>

using namespace L2DGE::Math;

namespace L2DGE::Graphics
{
  class Renderable
  {
  protected:
    unsigned int _primitiveType, _vertexCount;
    unsigned int _VAO;
    VertexBuffer *_VBO, *_EBO;
    Shader *_shader;
    Color *_color;
    Vector2 *_position, *_size;

  public:
    Renderable(Vector2& position, Vector2& size, Color& color, unsigned int primitiveType);
    unsigned int getVAO();
    VertexBuffer* getEBO();
    VertexBuffer* getVBO();
    unsigned int getPrimitiveType();

    Color* getColor();
    Vector2* getPosition();
    Vector2* getSize();
    Shader *getShader();
    unsigned int getVertexCount();

    void paint(Color &color);
    void move(const Vector2 &position);
    void rotate(float angle);
    void scale(const Vector2 &scaleOffset);
    
  };
}
#endif
