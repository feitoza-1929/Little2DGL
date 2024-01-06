#include <QuadShape.hpp>
#include <Canvas.hpp>

using namespace L2DGL::Graphics;
using namespace L2DGL::Canvas;

int main()
{
    Canvas canvas(800, 600, "Test");
    QuadShape quad(0.5, 0.4);

    while (canvas.isOpen())
    {
        canvas.clean();
        quad.draw();
        canvas.flip();
    }

    canvas.close();

    return 0;
}
