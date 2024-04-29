#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <GLFW/glfw3.h>

namespace L2DGE::Systems
{
  class Clock
  {
  private:
    inline static unsigned int _fps;
    inline static unsigned int _frameCount;
    inline static double _lastTime = glfwGetTime();
    
  public:
    static double getTime();
    static unsigned int getFPS();
    static unsigned int getFrame();
    
    static void countFrame();
  };
}

#endif
