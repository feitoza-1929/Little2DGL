#ifndef RENDER_HPP
#define RENDER_HPP

#include <GL/glew.h>
#include <stdlib.h>

#include <Renderable.hpp>

using namespace L2DGE::Math;

namespace L2DGE::Graphics
{
    class Render
    {
    public:
      Render();
      void draw(Renderable& renderable);
    };
}
#endif
