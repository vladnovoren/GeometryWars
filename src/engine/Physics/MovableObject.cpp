#include "MovableObject.hpp"

using namespace engine::phys;

MovableObject::MovableObject(const Vector2f& position, const Vector2f& velocity)
    : position_(position), velocity_(velocity) {
}

Vector2f MovableObject::GetPosition() const {
  return position_;
}

Vector2f MovableObject::GetVelocity() const {
  return velocity_;
}

void MovableObject::SetPosition(const Vector2f& position) {
  position_ = position;
}

void MovableObject::SetVelocity(const Vector2f& velocity) {
  velocity_ = velocity;
}
