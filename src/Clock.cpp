#include <Clock.hpp>

namespace L2DGE::Systems
{
  void Clock::countFrame()
  {
    double currentTime = getTime();
    _frameCount++;
    
    if(currentTime - _lastTime >= 1.000){
	_fps = _frameCount;
	_lastTime = currentTime;
	_frameCount = 0;
    }
  }

  double Clock::getTime(){ return glfwGetTime(); }
  unsigned int Clock:: getFPS(){ return _fps; }
  unsigned int Clock::getFrame() { return _frameCount; }
  
}
