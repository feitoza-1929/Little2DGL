#include <Vector2.hpp>

namespace L2DGE::Math
{
  Vector2::Vector2()
  {
    this->x = 0;
    this->y = 0;
  }
  Vector2::Vector2(float x, float y)
  {
    this->x = x;
    this->y = y;
  }

  Vector2* Vector2::operator+(const Vector2 &right)
  {
    return new Vector2(this->x + right.x, this->y + right.x);
  }

  Vector2* Vector2::operator-(const Vector2 &right)
  {
    return new Vector2(this->x - right.x, this->y - right.y);
  }

  Vector2* Vector2::operator+=(const Vector2 &right)
  {
    this->x += right.x;
    this->y += right.y;
    return this;
  }

  Vector2* Vector2::operator-=(const Vector2 &right)
  {
    this->x -= right.x;
    this->y -= right.y;
    return this;
  }
  
}
