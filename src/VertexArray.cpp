#include <VertexArray.hpp>

namespace L2DGE::Graphics
{
  VertexArray::VertexArray(unsigned int primitiveType, unsigned int vertexCount) : _primitiveType(primitiveType), _vertexCount(vertexCount)
  {
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
  }

  void VertexArray::bind()
  {
    glBindVertexArray(_VAO);
  }

  void VertexArray::unbind()
  {
    glBindVertexArray(0);
  }

  unsigned int VertexArray::getVertexCount()
  {
    return _vertexCount;
  }

  unsigned int VertexArray::getPrimitiveType()
  {
    return _primitiveType;
  }
}



