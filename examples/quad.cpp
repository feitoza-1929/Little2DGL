#include <QuadShape.hpp>
#include <Canvas.hpp>
#include <Vector2.hpp>

using namespace L2DGL::Graphics;
using namespace L2DGL::Canvas;
using namespace L2DGL::Math;

int main()
{
    Canvas canvas(800, 600, "Test");
    QuadShape quad(Vector2(0.4, 0.3));

    while (canvas.isOpen())
    {
        canvas.clean();
        quad.draw();
        canvas.flip();
    }

    canvas.close();

    return 0;
}
