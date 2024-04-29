#include <Render.hpp>
#include <iostream>
namespace L2DGE::Graphics
{
  Render::Render(){};
  void Render::draw(Renderable &renderable)
  {
    renderable.getShader()->activate();
    glBindVertexArray(renderable.getVAO());
    glDrawElements(renderable.getPrimitiveType(), renderable.getVertexCount(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  }
}
