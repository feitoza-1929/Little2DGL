#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

#include <Render.hpp>
#include <RenderState.hpp>
#include <Renderable.hpp>
#include <Input.hpp>
#include <Clock.hpp>

using namespace L2DGE::Systems;
namespace L2DGE::Graphics
{
  class Window
  {
  private:
    Render *_render;
    GLFWwindow *_window;
    unsigned int _width;
    unsigned int _height;
    
  public:
    Window(unsigned int width, unsigned int height, const char* title);
    void draw(Renderable &renderable);
    void beginDraw();
    void endDraw();
    bool isOpen();
    void close();
    unsigned int getWidth();
    unsigned int  getHeight();
  };
}
#endif
