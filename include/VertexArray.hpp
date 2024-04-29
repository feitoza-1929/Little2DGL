#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include <GL/glew.h>

namespace L2DGE::Graphics
{
  class VertexArray
  {
  protected:
    unsigned int _VAO;
    unsigned int _vertexCount;
    unsigned int _primitiveType;

  public:
    VertexArray(unsigned int primitiveType, unsigned int vertexCount);
    void bind();
    void unbind();
    unsigned int getVertexCount();
    unsigned int getPrimitiveType();
  };
}
#endif
