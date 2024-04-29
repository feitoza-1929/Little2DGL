#include <Window.hpp>

namespace L2DGE::Graphics
{
  Window::Window(unsigned int width, unsigned int height, const char* title)
    : _width(width), _height(height), _render(new Render())
  {
    glfwInit();
    
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    renderState.window = _window;
    
    glfwMakeContextCurrent(_window);
    glfwSetKeyCallback(_window, Input::keyCallback);
    
    glewInit();
  }

  void Window::draw(Renderable& renderable)
  {
    _render->draw(renderable);
  }

  bool Window::isOpen()
  {
    return !glfwWindowShouldClose(_window);
  }

  void Window::close()
  {
    glfwDestroyWindow(_window);
    glfwTerminate();
  }

  void Window::beginDraw()
  {
    Clock::countFrame();
    glClear(GL_COLOR_BUFFER_BIT);
  }

  void Window::endDraw()
  {
    glfwSwapBuffers(_window);
    glfwPollEvents();
  }
}
