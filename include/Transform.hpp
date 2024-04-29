#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <iostream>
#include <Vector2.hpp>

namespace L2DGE::Math
{
  class Transform
  { 
  public:
    float transformation[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
    
    Transform();
    void scale(const Vector2& vector);
    void translate(const Vector2& offset);
    void rotate(float angle);
    void print();
    float* getTransformation();
  };
}
#endif
