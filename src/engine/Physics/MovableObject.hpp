#pragma once

#include "Core/GameObject.hpp"
#include "Primitives.hpp"

namespace engine::phys {

class MovableObject : public GameObject {
 public:
  MovableObject() = default;
  MovableObject(const Vector2f& position, const Vector2f& velocity);

  [[nodiscard]] Vector2f GetPosition() const;

  [[nodiscard]] Vector2f GetVelocity() const;

  void SetPosition(const Vector2f& position);

  void SetVelocity(const Vector2f& velocity);

 protected:
  Vector2f position_;
  Vector2f velocity_;
};

}  // namespace engine::phys