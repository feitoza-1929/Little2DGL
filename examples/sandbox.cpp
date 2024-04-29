#include <Window.hpp>
#include <Renderable.hpp>
#include <Render.hpp>
#include <Color.hpp>
#include <Vector2.hpp>
#include <Input.hpp>
#include <Clock.hpp>

#include <iostream>

using namespace L2DGE::Graphics;
using namespace L2DGE::Systems;

int main()
{
  Window window(600, 600, "Sandbox");
  
  Vector2 position(0,0);
  Vector2 size(0.2,0.2);
  Color color(0.5,0,0);
  Renderable quad(position, size, color, GL_TRIANGLES);
  
  while(window.isOpen())
  {
    window.beginDraw();

    if(Input::isKeyDown(KeyCode::A))
      quad.move(Vector2(0.2, 0.1));
    
    window.draw(quad);
    window.endDraw();
  }
  return 0;
}
