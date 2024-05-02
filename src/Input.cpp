#include <Input.hpp>

namespace L2DGE::Systems
{
  bool Input::_keys[256];
  
  bool Input::isKeyDown(KeyCode code)
  {
    if(_keys[code] == true)
      return true;
    return false;
  }

  void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
  {
    if(key > 256)
      return;
    
    if(action == InputState::KEY_DOWN)
      _keys[key] = true;
    else if(action == InputState::KEY_UP)
      _keys[key] = false;
  }
}
