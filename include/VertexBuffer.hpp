#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include <GL/glew.h>

namespace L2DGE::Graphics
{
  class VertexBuffer
  {
  protected:
    unsigned int _target;
    unsigned int _VBO;
    unsigned int _vertexCount;

  public:
    VertexBuffer(unsigned int target, float *data, int dataSize);
    VertexBuffer(unsigned int target, unsigned int *data, int dataSize);
    void bind();
    void unbind();
    unsigned int getVertexCount();
  };
}
#endif
