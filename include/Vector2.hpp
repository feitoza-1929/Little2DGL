#ifndef VECTOR_2_HPP
#define VECTOR_2_HPP

namespace L2DGE::Math
{
  class Vector2
  {
  public:
    Vector2();
    Vector2(float x, float y);
    Vector2* operator+(const Vector2 &right);
    Vector2* operator-(const Vector2 &right);
    Vector2* operator+=(const Vector2 &right);
    Vector2* operator-=(const Vector2 &right);
    
    float x;
    float y;
  };
}
#endif
