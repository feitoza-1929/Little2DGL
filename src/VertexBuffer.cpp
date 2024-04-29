#include <VertexBuffer.hpp>

namespace L2DGE::Graphics
{
  VertexBuffer::VertexBuffer(unsigned int target, float *data, int dataSize)
    : _target(target)
  {
    glGenBuffers(1, &_VBO);
    glBindBuffer(target, _VBO);
    glBufferData(target, dataSize, data, GL_STATIC_DRAW);
  }

  VertexBuffer::VertexBuffer(unsigned int target,unsigned int *data, int dataSize)
    : _target(target)
  {
    glGenBuffers(1, &_VBO);
    glBindBuffer(target, _VBO);
    glBufferData(target, dataSize, data, GL_STATIC_DRAW);
  }

  void VertexBuffer::bind()
  {
    glBindBuffer(_target, _VBO);
  }

  void VertexBuffer::unbind()
  {
    glUnmapBuffer(_target);
  }
}
