#include "../Graphics/Shapes/QuadShape.hpp"
#include "../Graphics/Canvas.hpp"

int main()
{
    Little2DGL::Graphics::Canvas canvas(800, 600, "Test");
    Little2DGL::Graphics::QuadShape quad(0.5, 0.4);

    while (canvas.isOpen())
    {
        canvas.clean();
        quad.draw();
        canvas.flip();
    }

    canvas.close();

    return 0;
}
