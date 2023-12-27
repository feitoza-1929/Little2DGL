#include <GLFW/glfw3.h>
#include <stdbool.h>

#ifndef __CANVAS_HPP
#define __CANVAS_HPP

namespace Little2DGL{ namespace Graphics
{
    class Canvas
    {
    private:
        GLFWwindow *_canvasReference;
        int _width;
        int _height;

    public:
        Canvas(int width, int height, char* title);
        bool isOpen();
        void close();
        void clean();
        void flip();
        int getWidth();
        int getHeight();
    };
}}
#endif
