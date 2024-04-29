#ifndef INPUT_HPP
#define INPUT_HPP

#include <cstdint>
#include <iostream>
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <RenderState.hpp>

namespace L2DGE::Systems
{
  typedef enum KeyCode {
      SPACE = 32,
      A = 65,
      D = 68,
      S = 83,
      W = 87,
      ESCAPE = 256
  } KeyCode;

  typedef enum InputState {
      KEY_UP,
      KEY_DOWN,
      KEY_HELD
  } InputState;

  class Input
  {
  private:
    static bool _keys[256];
  public:
    static bool isKeyDown(KeyCode code);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
  };
}
#endif
