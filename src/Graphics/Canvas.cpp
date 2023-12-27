#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>

#include "Canvas.hpp"
#include "Shapes/QuadShape.hpp"

namespace Little2DGL{ namespace Graphics
{
        Canvas::Canvas(int width, int height, char* title)
        {
            _width = width;
            _height = height;

            glfwInit();

            _canvasReference = glfwCreateWindow(width, height, title, NULL, NULL);
            glfwMakeContextCurrent(_canvasReference);

            glewInit();
            return;
        }

        bool Canvas::isOpen()
        {
            return !glfwWindowShouldClose(_canvasReference);
        }

        void Canvas::close()
        {
            glfwDestroyWindow(_canvasReference);
            glfwTerminate();
        }

        void Canvas::clean()
        {
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void Canvas::flip()
        {
            glfwSwapBuffers(_canvasReference);
            glfwPollEvents();
        }

        int Canvas::getWidth()
        {
            return _width;
        }

        int Canvas::getHeight()
        {
            return _height;
        }
}}