#include <Transform.hpp>

namespace L2DGE::Math
{
  Transform::Transform()
  {
  }

  void Transform::scale(const Vector2& vector)
  {
     transformation[0] *= vector.x;
     transformation[5] *= vector.y;
  }
  //TODO need to fix translation
  void Transform::translate(const Vector2& offset)
  {
    transformation[12] = offset.x;
    transformation[13] = offset.y;
  }

  float* Transform::getTransformation(){ return transformation; }
  
  void Transform::print()
  {
    for(int i = 0; i < 16; i++)
    {
      std::cout << transformation[i] << " ";
    }
    std::cout << "\n";
  }
}
