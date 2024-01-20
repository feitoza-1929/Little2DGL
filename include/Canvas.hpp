#ifndef __CANVAS_HPP
#define __CANVAS_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdbool.h>

namespace L2DGL::Canvas
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
}
#endif
